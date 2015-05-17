#pragma once
#include "global.h"
#include "Move.h"
#include "Position.h"
#include "MoveGenerator.h"

class Searcher
{
public:
	Searcher(void);
	~Searcher(void);
	Move findBestmove(list<Move> moves, Position p);
	Move analyze(Position p){
		MoveGenerator mg;
		list<Move> moves = mg.generateLegalMoves(p);
		if (moves.size() == 0){
			return NULL;
		} else if (moves.size() == 1){
			return moves.front();
		} else {
			Move m = findBestmove(moves, p);
			return m;
		}
	}
};

