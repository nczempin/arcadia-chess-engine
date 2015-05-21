#include <stack>

#include "Searcher.h"
#include "Evaluator.h"
#include "Move.h"


Searcher::Searcher(void)
{
}


Searcher::~Searcher(void)
{
}
bool done;
int idDepth;

Move Searcher::findBestmove(vector<Move> moves, Position position){
	// assumption: moves.size() > 1
	resetClock();
	vector<Move> pvec;
	idDepth = 1;
	int maxIdDepth = 0;
	Move bestMove;
	Move lastIterationBestMove;
	done = false;
	deque<Move> lineUp;
	deque<Move> lineDown;
	do {
		lastIterationBestMove = bestMove;
		int bestValue = -9999999;
		for (Move move : moves){
			Position newPos = position.copyPosition();
			newPos.makeMove(move);
			//cout << "trying " << move.toString() << endl;
			int value = -alphabeta(1, newPos, -9999999, -bestValue,lineDown);
			if (value > bestValue){
				bestValue = value;
				bestMove = move;
				/*			cout << "lineDown: ";
				for(Move m: lineDown){
				cout << m.toString();
				}
				cout << endl;*/
				lineUp = lineDown;
				lineUp.push_front(move);

				cout << "info depth " << idDepth;
				cout << " score ";
				if (bestValue >80000){
					cout << "mate " <<   idDepth/2 ;
					done = true;
				}else {
					cout << "cp " <<   bestValue ;
				}
				cout << " pv ";
				for(Move m: lineUp){
					cout << m.toString()<< " ";
				}
				cout << endl;
			}
			if (timeUp()){
				return lastIterationBestMove;
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
		cout << " pv ";
		for(Move m: lineUp){
			cout << m.toString()<< " ";
		}
		cout << endl;
		if (maxIdDepth > 0 && idDepth > maxIdDepth){
			done = true;
		}
		++idDepth;

	} while (!done);
	return bestMove;
}
int Searcher::alphabeta(int depth, Position position, int alpha, int beta, deque<Move>& lineUp){
	int value = 0;
	if (depth >= idDepth){
		//value = quiescence_alphabeta(depth, position, alpha, beta);
		value = Evaluator::getValue(position);
		return value;
	}
	vector<Move> moves = MoveGenerator::generateLegalMoves(position);
	if (moves.size()==0){
		//cout << "no more moves!" << endl;
		if (position.isReceivingCheck()){
			return -888888; // Checkmate
		}else{
			return 0; // Stalemate
		}
	}
	for(Move newMove : moves){

		//expensive way to make next move
		Position nextPos = position.copyPosition();
		nextPos.makeMove(newMove);
		//cout << "making " << newMove.toString() << endl;
		deque<Move> lineDown;
		value = -alphabeta(depth + 1, nextPos, -beta, -alpha,lineDown);
		// back to "position" = expensive take back move
		/*	if (lineDown.size()>0){
		cout << "new lineDown: ";
		for(Move m: lineDown){
		cout << m.toString()<< " ";
		}
		cout << endl;
		}*/
		if (value >= beta){
			//cout << "beta cutoff " << value<< " >= "<< beta <<": "<<newMove.toString()<<endl; 
			return beta;
		}
		if (value > alpha) {
			//cout << "new best: " << newMove.toString() << ", " << value << " > " << alpha << endl;
			alpha = value;
			lineUp = lineDown;
			lineUp.push_front(newMove);
			

			//bestMove = newMove;
			if (value > 800000){
				return value;
			}
		}
		if (timeUp()){
			done = true;
			return alpha;
		}

	}
	return alpha;
}

int Searcher::quiescence_alphabeta(int depth, Position position, int alpha, int beta) {
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
	int v = Evaluator::getValue(position);
	/*if (depth>20){
	return -v;
	}*/
	if (v >= beta)
		return -beta;
	if (v > alpha) {
		//bestMoveValidFlag.setNr(1);
		alpha = v;
	}
	//kingCapture = false;
	int loopCount = 0;
	Position nextPos = position.copyPosition();
	//nextPos.makeMove(move);
	vector<Move> moves = MoveGenerator::generateAllCaptures(position);
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
		int value = quiescence_alphabeta(depth + 1, nextPos, -beta, -alpha);
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