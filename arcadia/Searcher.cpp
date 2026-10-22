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
{
    bestValue = 0;
    oldBestValue = 0;
    done = false;
    idDepth = 1;
    maxIdDepth = 64;
    kingCapture = false;
}


Searcher::~Searcher(void)
{
}

Move Searcher::findBestmove(vector<Move> moves, Position position){
    // assumption: moves.size() > 1
    resetClock();
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
        if ((maxIdDepth > 0 && idDepth >= maxIdDepth) || idDepth >= 64){
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
int Searcher::alphabeta(int depth, Position position, int alpha, int beta, deque<Move>& lineUp){
    if (done || timeUp()) {
        done = true;
        return 0;
    }
    int value = 0;
    if (depth >= idDepth){
        deque<Move> lineDown;
        value = quiescence_alphabeta(depth, position, alpha, beta, lineDown);
        lineUp = lineDown;
        return value;
    }
    vector<Move> moves;
    moves.reserve(40);
    MoveGenerator::generateAllMoves(position, moves);
    for (const Move& m : moves){
        if (m.captured == 6){
            kingCapture = true;
            return 666663;
        }
    }
    stable_sort(moves.begin(), moves.end(), [](const Move& a, const Move& b){
        if (a.captured != b.captured) return a.captured > b.captured;
        return a.promoted > b.promoted;
    });
    int actualMoves = 0;
    for(Move newMove : moves){
        Position nextPos = position.copyPosition();
        nextPos.makeMove(newMove);
        ++Info::nodes;
        deque<Move> lineDown;
        uint64_t nextHash = nextPos.getHash();
        if (isRepetition(nextHash)) {
            if (!nextPos.isGivingCheck()) {
                value = 0;
            } else {
                searchHistory.push_back(nextHash);
                value = -alphabeta(depth + 1, nextPos, -beta, -alpha, lineDown);
                searchHistory.pop_back();
                if (kingCapture) {
                    kingCapture = false;
                    continue;
                }
                lineDown.clear();
                value = 0;
            }
        } else {
            searchHistory.push_back(nextHash);
            value = -alphabeta(depth + 1, nextPos, -beta, -alpha, lineDown);
            searchHistory.pop_back();
        }
        if (kingCapture){
            kingCapture = false;
            continue;
        }
        if (done || timeUp()){
            done = true;
            return alpha;
        }
        ++actualMoves;
        if (value >= beta){
            return beta;
        }
        if (value > alpha) {
            alpha = value;
            lineUp = lineDown;
            lineUp.push_front(newMove);
            if (value > 800000){
                return value;
            }
        }
    }
    if (actualMoves == 0){
        if (position.isReceivingCheck()){
            return -888888 + depth; // Checkmate
        }else{
            return 0; // Stalemate
        }
    }
    return alpha;
}
static bool shouldBeIgnored(Position nextPos, Move newMove, int capture, int capturing) {
    (void)nextPos;
    (void)newMove;
    (void)capture;
    (void)capturing;
    return false;
}

int Searcher::quiescence_alphabeta(int depth, Position position, int alpha, int beta, deque<Move>& lineUp) {
    if (done || timeUp()) {
        done = true;
        return 0;
    }
    vector<Move> moves;
    moves.reserve(16);
    MoveGenerator::generateAllCaptures(position, moves);
    for (const Move& m : moves){
        if (m.captured == 6){
            kingCapture = true;
            return 666663;
        }
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
    stable_sort(moves.begin(), moves.end(), [](const Move& a, const Move& b){
        if (a.captured != b.captured) return a.captured > b.captured;
        return a.promoted > b.promoted;
    });
    for(Move newMove: moves){
        int capture = newMove.captured;
        assert(capture > 0);
        int capturing = abs(position.board[newMove.from]);
        if (!shouldBeIgnored(position, newMove, capture, capturing)) {
            Position nextPos = position.copyPosition();
            nextPos.makeMove(newMove);
            ++Info::nodes;
            deque<Move> lineDown;
            int value = -quiescence_alphabeta(depth + 1, nextPos, -beta, -alpha, lineDown);
            if (kingCapture) {
                kingCapture = false;
                continue;
            }
            if (done || timeUp()) {
                done = true;
                return alpha;
            }
            if (value >= beta) {
                return beta;
            }
            if (value > alpha) {
                alpha = value;
                lineUp = lineDown;
                lineUp.push_front(newMove);
            }
        }
    }
    return alpha;
}
