#pragma once
#include <deque>
#include <chrono>

#include "global.h"
#include "Move.h"
#include "Position.h"
#include "MoveGenerator.h"
#include "Info.h"

using namespace std;

class Searcher
{
public:
	Searcher(void);
	~Searcher(void);
	Move bestMove;
	int bestValue;
	int oldBestValue;
	bool done;
	int idDepth;
	deque<Move> pv;
	int quiescence_alphabeta(int depth, Position position, int alpha, int beta, deque<Move>& lineUp);
	int alphabeta(int depth, Position position, int alpha, int beta, deque<Move>& lineUp);
	Move findBestmove(vector<Move> moves, Position p);
	Move analyze(Position p){
		MoveGenerator mg;
		vector<Move> moves = mg.generateLegalMoves(p);
		if (moves.size() == 0){
			return Move();
		} else if (moves.size() == 1){
			return moves.front();
		} else {
			Move m = findBestmove(moves, p);
			return m;
		}
	}

	void updateNps(){
		chrono::duration<double> elapsed_seconds = chrono::system_clock::now()-Info::start;
		double seconds = elapsed_seconds.count();
		Info::nps =  (Info::nodes/seconds);
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
		if (bestValue >80000){
			cout << "mate " <<   idDepth/2 ;
		}else if (bestValue<900000){
			cout << "cp " << oldBestValue;
		}else{
			cout << "cp " <<   bestValue;
		}
		cout << " pv ";
		for(Move m: pv){
			cout << m.toString()<< " ";
		}
		cout << endl;
	}
};

