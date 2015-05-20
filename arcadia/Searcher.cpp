#include "Searcher.h"
#include "Evaluator.h"
#include "Move.h"


Searcher::Searcher(void)
{
}


Searcher::~Searcher(void)
{
}
int idDepth;
Move Searcher::findBestmove(vector<Move> moves, Position position){
	// assumption: moves.size() > 1
	resetClock();
	Move bestMove;
	vector<Move> pvec;
	idDepth = 1;
	int bestValue = -9999999;
	bool done = false;
	do {
		for (Move move : moves){
			int value = alphabeta(1, position, move, -9999999, -bestValue);
			if (value > bestValue){
				bestValue = value;
				bestMove = move;
				cout << "info depth " << idDepth << " score cp " <<   value << " pv "<< bestMove.toString() <<endl;
			}
			if (timeUp()){
				done = true;
				break;
			}
		}
		cout << "info depth " << idDepth;
		cout << " score ";
		if (bestValue >80000){
					cout << "mate " <<   idDepth/2 ;
			done = true;
		}else {
		cout << "cp " <<   bestValue ;
		}
		cout << " pv "<< bestMove.toString() <<endl;
		++idDepth;

	} while (!done);
	return bestMove;
}
int Searcher::alphabeta(int depth, Position position, Move move, const int originalAlpha, int beta){
	//cout << "ab: " << depth<< "(" << move.toString() << ")"  << endl;
	int alpha = originalAlpha;
	int value = 0;
	Position nextPos = position.copyPosition();
	nextPos.makeMove(move);
	//vector<Move>captureMoves = nextPos.generateCaptureMoves();
	if (depth >= idDepth){
		//vector<Move> downPv ;
		//value = quiescence_alphabeta(depth, position, move, alpha, beta, downPv, nextPos);
		//upPv.clear();
		//upPv.addAll(downPv);
		value = Evaluator::getValue(nextPos);	
		return value;
	}
	vector<Move> moves = MoveGenerator::generateLegalMoves(nextPos);
	if (moves.size()==0){
		//cout << "no more moves!" << endl;
		if (nextPos.isReceivingCheck()){
			return 888888; // Checkmate
		}else{
			return 0; // Stalemate
		}
	}
	vector<Move> downPv;
	Move bestMove;
	for(Move newMove : moves){
		value = alphabeta(depth + 1, nextPos, newMove, -beta, -alpha);
		if (value >= beta){
			return -beta;
		}
		if (value > alpha) {
			//cout << "new best: " << newMove.toString() << ", " << value << " > " << alpha << endl;
			alpha = value;
			bestMove = newMove;
			if (value > 800000){
				return -value;
			}
		}
	}
	return -alpha;
}

int Searcher::quiescence_alphabeta(int depth, Position position, Move move, int originalAlpha, int beta, vector<Move> upPv, Position nextPos) {
	int alpha = originalAlpha;
	//ValidFlag bestMoveValidFlag = new ValidFlag();
	//if ((timeUp()) || (timeIsUp)) {
	//	timeIsUp = true;
	//	return 0;
	//}
	//if (depth > Info.seldepth)
	//	Info.seldepth = depth;
	//if (nextPos == null)
	//	try {
	//		Info.qs_nodes += 1L;
	//		nextPos = Position.createPosition(position, move);
	//	} catch (ThreeRepetitionsAB e) {
	//		System.err.println("three repetitions. what to do?");
	//		return 0;
	//	}
	int v = Evaluator::getValue(nextPos);
	if (depth>20){
		return -v;
	}
	if (v >= beta)
		return -beta;
	if (v > alpha) {
		//bestMoveValidFlag.setNr(1);
		alpha = v;
	}
	//kingCapture = false;
	int loopCount = 0;
	vector<Move> moves = MoveGenerator::generateAllCaptures(nextPos);
	if (moves.size()==0){
		return -v;
	}
	for(Move newMove: moves){
		int capture = newMove.captured;
		int capturing = abs(position.board[newMove.from]);
		if (capture == 6) {
			//	kingCapture = true;
			//	illegalCount += 1;
			return -666663;
		}
		//	if (!shouldBeIgnored(nextPos, newMove, capture, capturing)) {
		//moveStack.push(newMove);
		vector<Move> downPv;
		int value = quiescence_alphabeta(depth + 1, nextPos, newMove, -beta, -alpha, downPv, nextPos);
		//if (kingCapture) {
		//	illegalCount += 1;
		//	moveStack.pop();
		//	kingCapture = false;
		//} else {
		//	loopCount++;
		if (value >= beta) {
			//moveStack.pop();
			return -beta;
		}
		//bestMoveValidFlag.setNr(-1);
		if (value > alpha) {
			alpha = value;
			//upPv.clear();
			//upPv.add(newMove);
			//upPv.addAll(downPv);
		}
		//moveStack.pop();
		//	}
		//}
	}
	/*	if (loopCount == 0) {
	nextPos.initNonCaptureMoveGenerator();
	boolean legal = false;
	while (nextPos.hasNextNonCaptureMove()) {
	Move testMove = nextPos.nextNonCaptureMove();
	Info.quiescentMateCheckNodes += 1;
	Position tp = Position.createTestPosition(nextPos, testMove);
	if (!tp.isGivingCheck()) {
	legal = true;
	break;
	}
	}
	if (!legal) {
	SortedSet lMoves = nextPos.generateLegalMoves();
	if (lMoves.size() == 0) {
	if (nextPos.isMate()) {
	int value = -90000 + depth;
	return -value;
	}
	return 0;
	}
	}
	alpha = v;
	}*/	
	return -alpha;
}
