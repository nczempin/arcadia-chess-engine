#pragma once
#include <deque>

#include "global.h"
#include "Move.h"
#include "Position.h"
#include "MoveGenerator.h"

using namespace std;

class Searcher
{
public:
	Searcher(void);
	~Searcher(void);
	Move bestMove;
	bool done;
	int idDepth;
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
		Move m = bestMove;
		cout << "currently best move: " << m.toString() << endl;
	}
};

