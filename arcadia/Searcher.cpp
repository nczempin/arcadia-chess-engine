#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>

#include "Searcher.h"
#include "Evaluator.h"
#include "Move.h"
#include "Info.h"


Searcher::Searcher(void)
    : ttTable(TT_SIZE)
{
    bestValue = 0;
    oldBestValue = 0;
    done = false;
    idDepth = 1;
    maxIdDepth = 64;
    kingCapture = false;
    clearSearchTables();
}


Searcher::~Searcher(void)
{
}

Move Searcher::findBestmove(vector<Move> moves, Position position){
    resetClock();
    clearSearchTables();
    idDepth = 1;
    Info::seldepth = 0;
    Info::nodes = 0;
    bestMove = moves.front();
    Move lastIterationBestMove = bestMove;
    bestValue = 0;
    oldBestValue = 0;
    kingCapture = false;
    pv.clear();
    pv.push_back(bestMove);
    done = false;
    deque<Move> lineDown;
    list<Move> sortedMoves;
    list<Move> otherMoves;
    do {
        lastIterationBestMove = bestMove;
        oldBestValue = bestValue;
        bestValue = -9999999;
        sortedMoves.clear();
        otherMoves.clear();
        Info::currmovenumber = 0;
        for (Move move : moves){
            Position newPos = position.copyPosition();
            newPos.makeMove(move);
            ++Info::nodes;
            Info::currmove = move;
            Info::currmovenumber++;
            lineDown.clear();
            kingCapture = false;
            searchHistory.clear();
            int value;
            uint64_t nextHash = newPos.getHash();
            if (isRepetition(nextHash)) {
                value = 0;
            } else {
                searchHistory.push_back(nextHash);
                value = -alphabeta(1, newPos, -9999999, -bestValue, lineDown);
                searchHistory.pop_back();
            }
            if (done || timeUp()){
                done = true;
                break;
            }
            move.value = value;
            if (value > bestValue){
                sortedMoves.push_front(move);
                bestValue = value;
                bestMove = move;
                pv = lineDown;
                pv.push_front(move);
                if (bestValue > 800000){
                    done = true;
                    break;
                }
            }else{
                otherMoves.push_back(move);
            }
        }
        if (bestValue <= -9000000){
            bestValue = oldBestValue;
            bestMove = lastIterationBestMove;
        } else {
            printInfo();
        }
        if ((maxIdDepth > 0 && idDepth >= maxIdDepth) || idDepth >= 64 || softTimeUp()){
            done = true;
        }
        if (!done){
            ++idDepth;
            moves.clear();
            for (Move move : sortedMoves){
                moves.push_back(move);
            }
            for (Move move : otherMoves){
                moves.push_back(move);
            }
        }
    } while (!done);
    return bestMove;
}

int Searcher::alphabeta(int depth, Position& position, int alpha, int beta, deque<Move>& lineUp){
    if (position.isGivingCheck()) {
        kingCapture = true;
        return 666663;
    }
    if (done || ((Info::nodes & 127) == 0 && timeUp())) {
        done = true;
        return 0;
    }
    const bool inCheck = position.isReceivingCheck();
    if (depth >= idDepth && (!inCheck || depth >= idDepth + 2)){
        return quiescence_alphabeta(depth, position, alpha, beta);
    }

    const int originalAlpha = alpha;
    const int remDepth = (idDepth - depth > 1) ? (idDepth - depth) : 1;
    const uint64_t posHash = position.getHash();
    ArcadiaTTEntry& tte = ttTable[posHash & TT_MASK];
    int ttFrom = -1;
    int ttTo = -1;
    int ttPromoted = 0;
    if (tte.key == posHash) {
        ttFrom = tte.bestFrom;
        ttTo = tte.bestTo;
        ttPromoted = tte.bestPromoted;
        if (depth > 1 && tte.depth >= remDepth && abs(tte.score) < 800000) {
            if (tte.flag == 0) {
                lineUp.clear();
                return tte.score;
            } else if (tte.flag == 1 && tte.score >= beta) {
                return beta;
            } else if (tte.flag == 2 && tte.score <= alpha) {
                return alpha;
            }
        }
    }

    vector<Move> moves;
    moves.reserve(40);
    MoveGenerator::generateAllMoves(position, moves);

    const int sideIdx = position.onMove ? 1 : 0;
    const Move k1 = (depth < 64) ? killers[depth][0] : Move(-1, -1, 0);
    const Move k2 = (depth < 64) ? killers[depth][1] : Move(-1, -1, 0);

    for (Move& m : moves) {
        if (m.from == ttFrom && m.to == ttTo && m.promoted == ttPromoted) {
            m.value = 10000000;
        } else if (m.captured > 0 || m.promoted > 0) {
            int aggressor = abs(position.board[m.from]);
            m.value = 1000000 + m.captured * 100 + m.promoted * 80 - aggressor;
        } else if (m.from == k1.from && m.to == k1.to) {
            m.value = 900000;
        } else if (m.from == k2.from && m.to == k2.to) {
            m.value = 800000;
        } else {
            m.value = history[sideIdx][m.from][m.to];
        }
    }
    stable_sort(moves.begin(), moves.end(), [](const Move& a, const Move& b){
        return a.value > b.value;
    });

    int actualMoves = 0;
    Move bestNodeMove(-1, -1, 0);
    int value = 0;
    deque<Move> lineDown;
    for(const Move& newMove : moves){
        Position nextPos = position.copyPosition();
        nextPos.makeMove(newMove);
        ++Info::nodes;
        lineDown.clear();
        uint64_t nextHash = nextPos.getHash();
        if (isRepetition(nextHash)) {
            if (!nextPos.isGivingCheck()) {
                value = 0;
            } else {
                kingCapture = false;
                continue;
            }
        } else {
            searchHistory.push_back(nextHash);
            if (actualMoves == 0) {
                value = -alphabeta(depth + 1, nextPos, -beta, -alpha, lineDown);
            } else {
                int reduction = 0;
                if (actualMoves >= 3 && remDepth >= 3 && newMove.captured == 0 && newMove.promoted == 0 && !inCheck) {
                    reduction = (actualMoves >= 8 && remDepth >= 4) ? 2 : 1;
                }
                value = -alphabeta(depth + 1 + reduction, nextPos, -(alpha + 1), -alpha, lineDown);
                if (!kingCapture && !done && value > alpha && (reduction > 0 || value < beta)) {
                    lineDown.clear();
                    value = -alphabeta(depth + 1, nextPos, -beta, -alpha, lineDown);
                }
            }
            searchHistory.pop_back();
        }
        if (kingCapture){
            kingCapture = false;
            continue;
        }
        if (done || ((Info::nodes & 127) == 0 && timeUp())){
            done = true;
            return alpha;
        }
        if (actualMoves == 0) {
            bestNodeMove = newMove;
        }
        ++actualMoves;
        if (value >= beta){
            if (newMove.captured == 0 && newMove.promoted == 0 && depth < 64) {
                if (!(killers[depth][0].from == newMove.from && killers[depth][0].to == newMove.to)) {
                    killers[depth][1] = killers[depth][0];
                    killers[depth][0] = newMove;
                }
                history[sideIdx][newMove.from][newMove.to] += remDepth * remDepth;
            }
            tte.key = posHash;
            tte.score = beta;
            tte.depth = static_cast<int16_t>(remDepth);
            tte.flag = 1;
            tte.bestFrom = static_cast<int8_t>(newMove.from);
            tte.bestTo = static_cast<int8_t>(newMove.to);
            tte.bestPromoted = static_cast<int8_t>(newMove.promoted);
            return beta;
        }
        if (value > alpha) {
            alpha = value;
            bestNodeMove = newMove;
            lineUp = lineDown;
            lineUp.push_front(newMove);
            if (value > 800000){
                return value;
            }
        }
    }
    if (actualMoves == 0){
        if (inCheck){
            return -888888 + depth; // Checkmate
        }else{
            return 0; // Stalemate
        }
    }
    tte.key = posHash;
    tte.score = alpha;
    tte.depth = static_cast<int16_t>(remDepth);
    tte.flag = (alpha > originalAlpha) ? 0 : 2;
    tte.bestFrom = static_cast<int8_t>(bestNodeMove.from);
    tte.bestTo = static_cast<int8_t>(bestNodeMove.to);
    tte.bestPromoted = static_cast<int8_t>(bestNodeMove.promoted);
    return alpha;
}

int Searcher::quiescence_alphabeta(int depth, Position& position, int alpha, int beta) {
    if (position.isGivingCheck()) {
        kingCapture = true;
        return 666663;
    }
    if (done || ((Info::nodes & 127) == 0 && timeUp())) {
        done = true;
        return 0;
    }
    if (depth > Info::seldepth){
        Info::seldepth = depth;
    }
    int v = Evaluator::getValue(position);
    if (v >= beta)
        return beta;
    if (v > alpha) {
        alpha = v;
    }
    if (depth - idDepth >= 10) {
        return alpha;
    }
    vector<Move> moves;
    moves.reserve(16);
    MoveGenerator::generateAllCaptures(position, moves);
    for (Move& m : moves) {
        m.value = m.captured * 100 + m.promoted * 80 - abs(position.board[m.from]);
    }
    stable_sort(moves.begin(), moves.end(), [](const Move& a, const Move& b){
        return a.value > b.value;
    });
    for(const Move& newMove: moves){
        int capture = newMove.captured;
        assert(capture > 0);
        if (newMove.promoted == 0 && capture >= 1 && capture <= 5) {
            if (v + Evaluator::pieceValues[capture - 1] + 200 < alpha) {
                continue;
            }
        }
        Position nextPos = position.copyPosition();
        nextPos.makeMove(newMove);
        ++Info::nodes;
        int value = -quiescence_alphabeta(depth + 1, nextPos, -beta, -alpha);
        if (kingCapture) {
            kingCapture = false;
            continue;
        }
        if (done || ((Info::nodes & 127) == 0 && timeUp())) {
            done = true;
            return alpha;
        }
        if (value >= beta) {
            return beta;
        }
        if (value > alpha) {
            alpha = value;
        }
    }
    return alpha;
}
