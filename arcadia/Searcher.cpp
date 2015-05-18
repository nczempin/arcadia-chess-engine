#include "Searcher.h"
#include "Evaluator.h"
#include "Move.h"


Searcher::Searcher(void)
{
}


Searcher::~Searcher(void)
{
}
	Move Searcher::findBestmove(list<Move> moves, Position position){
		// assumption: moves.size() > 1
		Move bestMove;
		vector<Move> pvec;
		int bestValue = -99999;
		for (Move move : moves){
			int value = alphabeta(1, 0.0, position, move, -99999, -bestValue, pvec, 0, false);
			if (value > bestValue){
				bestValue = value;
				bestMove = move;
				cout << move.toString() << ": " << value << endl;
			}
		}
         
		return bestMove;
	}
int Searcher::alphabeta(int depth, double extension, Position position, Move move, int originalAlpha, int beta, vector<Move> upPv, int checkExtensions, bool justExtended){

	int alpha = originalAlpha;
	Position nextPos = position.copyPosition();
	nextPos.makeMove(move);
	//list<Move>captureMoves = nextPos.generateCaptureMoves();

	int value = Evaluator::getValue(nextPos);
	return -value;
}
	