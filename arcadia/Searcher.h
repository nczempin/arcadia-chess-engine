#pragma once
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
	int alphabeta(int depth, double extension, Position position, Move move, int originalAlpha, int beta, vector<Move> upPv, int checkExtensions, bool justExtended);
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
};

