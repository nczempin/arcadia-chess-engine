#pragma once
#include <deque>

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
			return NULL;
		} else if (moves.size() == 1){
			return moves.front();
		} else {
			Move m = findBestmove(moves, p);
			return m;
		}
	}
	void printInfo(){
				cout << "info depth " << idDepth;
				cout << " seldepth " << Info::seldepth;
				cout << " currmove " << Info::currmove.toString();
				cout << " score ";
				if (bestValue >80000){
					cout << "mate " <<   idDepth/2 ;
					done = true;
				}else {
					cout << "cp " <<   bestValue ;
				}
				cout << " pv ";
				for(Move m: pv){
					cout << m.toString()<< " ";
				}
				cout << endl;
	}
};

