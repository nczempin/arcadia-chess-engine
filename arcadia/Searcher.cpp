#include "Searcher.h"
#include "Evaluator.h"
#include "Move.h"


Searcher::Searcher(void)
{
}


Searcher::~Searcher(void)
{
}
Move Searcher::findBestmove(vector<Move> moves, Position position){
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
	//cout << "ab: " << depth<< "(" << move.toString() << ")"  << endl;
	int alpha = originalAlpha;
	int value = 0;
	Position nextPos = position.copyPosition();
	nextPos.makeMove(move);
	//vector<Move>captureMoves = nextPos.generateCaptureMoves();
	if (depth >= 4){ //TODO set depth dynamically of course
		value = Evaluator::getValue(nextPos);
		//cout << "evaluating: "  << value << endl;
		return -value;
	}
	vector<Move> moves = MoveGenerator::generateLegalMoves(nextPos);
	vector<Move> downPv;
	Move bestMove;
	for(Move newMove : moves){
		value = alphabeta(depth + 1, extension, nextPos, newMove, -beta, -alpha, downPv, checkExtensions, false);
		if (value > alpha) {
			//cout << "new best: " << newMove.toString() << ", " << value << " > " << alpha << endl;
			alpha = value;
			bestMove = newMove;
		}
	}
	return -alpha;
}