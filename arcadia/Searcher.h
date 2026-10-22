#pragma once
#include <deque>
#include <chrono>
#include <vector>
#include <cstdint>
#include <cstring>

#include "global.h"
#include "Move.h"
#include "Position.h"
#include "MoveGenerator.h"
#include "Info.h"

using namespace std;

struct ArcadiaTTEntry {
	uint64_t key = 0;
	int score = 0;
	int16_t depth = -1;
	uint8_t flag = 0; // 0 = EXACT, 1 = LOWER_BOUND, 2 = UPPER_BOUND
	int8_t bestFrom = -1;
	int8_t bestTo = -1;
	int8_t bestPromoted = 0;
};

class Searcher
{
public:
	static constexpr size_t TT_SIZE = 65536;
	static constexpr size_t TT_MASK = TT_SIZE - 1;

	Searcher(void);
	~Searcher(void);
	Move bestMove;
	int bestValue;
	int oldBestValue;
	bool done;
	int idDepth;
	int maxIdDepth;
	bool kingCapture;
	deque<Move> pv;
	vector<uint64_t> gameHistory;
	vector<uint64_t> searchHistory;
	vector<ArcadiaTTEntry> ttTable;
	Move killers[64][2];
	int history[2][89][89];

	void clearSearchTables() {
		for (int d = 0; d < 64; ++d) {
			killers[d][0] = Move(-1, -1, 0);
			killers[d][1] = Move(-1, -1, 0);
		}
		std::memset(history, 0, sizeof(history));
	}

	bool isRepetition(uint64_t h) const {
		int count = 0;
		for (uint64_t gh : gameHistory) {
			if (gh == h) {
				++count;
				if (count >= 2) return true;
			}
		}
		for (uint64_t sh : searchHistory) {
			if (sh == h) {
				++count;
				if (count >= 2) return true;
			}
		}
		return false;
	}
	int quiescence_alphabeta(int depth, Position& position, int alpha, int beta, deque<Move>& lineUp);
	int alphabeta(int depth, Position& position, int alpha, int beta, deque<Move>& lineUp);
	Move findBestmove(vector<Move> moves, Position p);
	Move analyze(Position p){
		resetClock();
		MoveGenerator mg;
		vector<Move> moves = mg.generateLegalMoves(p);
		if (moves.size() == 0){
			bestMove = Move(-1,-1,0);
			return bestMove;
		} else if (moves.size() == 1){
			idDepth = 1;
			Info::seldepth = 1;
			Info::nodes = 1;
			Info::currmove = moves.front();
			Info::currmovenumber = 1;
			bestMove = moves.front();
			bestValue = 0;
			oldBestValue = 0;
			pv.clear();
			pv.push_back(bestMove);
			return bestMove;
		} else {
			Move m = findBestmove(moves, p);
			return m;
		}
	}

	void updateNps(){
		chrono::duration<double> elapsed_seconds = chrono::system_clock::now()-Info::start;
		double seconds = elapsed_seconds.count();
		if (seconds > 0.0001) {
			Info::nps = static_cast<int>(Info::nodes / seconds);
		} else {
			Info::nps = 0;
		}
	}

	void printInfo(){
		cout << "info depth " << idDepth;
		cout << " seldepth " << Info::seldepth;
		cout << " currmove " << Info::currmove.toString();
		cout << " currmovenumber " << Info::currmovenumber;
		cout << " nodes " << Info::nodes;
		updateNps();
		cout << " nps " << Info::nps;
		cout << " score ";
		int displayScore = (bestValue <= -9000000) ? oldBestValue : bestValue;
		if (displayScore > 800000){
			int mateMoves = max(1, (888888 - displayScore + 1) / 2);
			cout << "mate " << mateMoves;
		}else if (displayScore < -800000){
			int mateMoves = max(1, (888888 + displayScore + 1) / 2);
			cout << "mate -" << mateMoves;
		}else{
			cout << "cp " << displayScore;
		}
		cout << " pv ";
		for(Move m: pv){
			cout << m.toString()<< " ";
		}
		cout << endl;
	}
};
