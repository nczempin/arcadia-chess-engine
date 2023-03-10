#pragma once
#include <list>
#include <vector>

#include "Position.h"
#include "Move.h"

using namespace std;
class MoveGenerator
{
public:
	MoveGenerator(void){
	}
	~MoveGenerator(void);
private:
	static Position position;
public: 
	static vector<Move> removeIllegalMoves(vector<Move>& moves) {
		vector<Move> legalMoves;
		for(Move move: moves){

			//			Info.ensureLegalNodes += 1;
			Position nextPos = position.createTestPosition(move);
			if (!nextPos.isGivingCheck()) {
				legalMoves.push_back(move);
			}
		}
		return legalMoves;
	}
	static vector<Move> generateLegalCaptureMoves(Position position){
		vector<Move> moves;
		generateAllCaptures(position,moves);
		vector<Move> legalMoves = removeIllegalMoves(moves);
		return legalMoves;
	}
	static vector<Move> generateLegalMoves(Position position){
		vector<Move> moves;
		generateAllMoves(position,moves);
		//cout << "all moves (including illegal)" << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		moves = removeIllegalMoves(moves);
		//cout << "only legal moves" << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		//if (moves.size()==0){
		//	if (position.isReceivingCheck()){
		//		cout << "I am Mate." << endl;
		//	}else{
		//		cout << "I am Stalemate." << endl;
		//	}
		//}
		return moves;
	}
	static void generateAllMoves(Position p,vector<Move>& moves) {

		position = p;
		for (int i = 11; i < 89; i++) {
			int piece = position.board[i];
			int type = abs(piece);
			if ((type >= 1) && (type <= 6)) {
				bool color = BLACK;
				if (piece > 0) {
					color = WHITE;
				}
				if (color==position.onMove) {
					generateMoves(i, piece,moves);
				}
			}
		}
	}
	static void generateAllCaptures(Position p,vector<Move>& moves) {

		position = p;
		for (int i = 11; i < 89; i++) {
			int piece = position.board[i];
			int type = abs(piece);
			if ((type >= 1) && (type <= 6)) {
				bool color = BLACK;
				if (piece > 0) {
					color = WHITE;
				}
				if (color==position.onMove) {
					generateCaptures(i, piece, color,moves);
				}
			}
		}
	}

	static void generateCaptures(int i, int p, bool color,	vector<Move>& moves) {
		switch (p) {
		case -1:

		case 1:
			generatePawnCaptures(i,moves);
			break;

		case -2:

		case 2:
			position.generateKnightCaptures(moves,i,color);
			break;

		case -3:

		case 3:
			position.generateBishopCaptures(moves,i,color);
			break;

		case -4:

		case 4:
			position.generateRookCaptures(moves,i,color);
			break;

		case -5:

		case 5:
			position.generateQueenCaptures(moves,i,color);
			break;

		case -6:
		case 6:
			position.generateKingCaptures(moves,i,color);
			break;
		}

	}
	static void generateMoves(int i, int p,	vector<Move>& moves) {
		switch (p) {
		case -1:

		case 1:
			generatePawnMoves(i, moves);
			break;

		case -2:

		case 2:
			generateKnightMoves( i, moves);
			break;

		case -3:

		case 3:
			generateBishopMoves(i, moves);
			break;

		case -4:

		case 4:
			generateRookMoves(i, moves);
			break;

		case -5:

		case 5:
			generateQueenMoves(i, moves);
			break;

		case -6:
		case 6:
			generateKingMoves(i, moves);
			break;
		}
	}

	static void  generatePawnMoves(int from,vector<Move>& moves) {
		generatePawnCaptures(from, moves);
		generatePawnNonCapture(from,moves);
	}

	static 	void generatePawnCapture(int from, int multi, int next, int row,vector<Move>& moves) {
		if (invalidSquare(next))
			return ;
		int capturedPiece = position.board[next];
		if ((capturedPiece != 0) && (((capturedPiece < 0) && (position.onMove)) || ((capturedPiece > 0) && (!position.onMove)))){
			int absCapturedPiece = abs(capturedPiece);
			if (next / (row + multi * 6) == 1) {
				Move m = Move(from, next, absCapturedPiece, 5);
				moves.push_back(m);
#ifdef USE_UNDERPROMOTION
				m = Move(from, next, absCapturedPiece, 4);
				moves.push_back(m);
				m = Move(from, next, absCapturedPiece, 3);
				moves.push_back(m);
				m = Move(from, next, absCapturedPiece, 2);
				moves.push_back(m);
#endif
			} else {
				Move m = Move(from, next, absCapturedPiece);
				moves.push_back(m);
			}
		}
			if (position.enPassantSquare == next) {
				Move m = Move(from, next, 1); //hardcoded pawn, because it is not taken from the actual "next" square
			//cout << "generated " << m.toString() << endl;
				moves.push_back(m);
			}

	}
	static void generatePawnCaptures(int from,vector<Move>& moves) {
		int multi = 10;
		int row = 20;
		if (!position.onMove) {
			multi = -multi;
			row = 70;
		}
		int file = from % 10;
		int next = from + multi - 1;
		if (file != 1)
			generatePawnCapture(from, multi, next, row,moves);
		next = from + multi + 1;
		if (file != 8) {
			generatePawnCapture(from, multi, next, row,moves);
		}
	}
	static void generatePawnNonCapture(int from,vector<Move>& moves) {
		int multi = 10;
		int row = 20;
		if (!position.onMove) {
			multi = -multi;
			row = 70;
		}
		int next = from + multi;
		int p = position.board[next];
		if (p == 0) {
			if (next / (row + multi * 6) == 1) {
				//promotion.
				Move m = Move(from, next,0,5);
				moves.push_back(m);
#ifdef USE_UNDERPROMOTION
				m = Move(from, next,0,4);
				moves.push_back(m);
				m = Move(from, next,0,3);
				moves.push_back(m);
				m = Move(from, next,0,2);
				moves.push_back(m);

#endif
			} else {
				Move m = Move(from, next,0);
				moves.push_back(m);
			}
			//double step pawn move
			if ((from > row) && (row + 9 > from)) {
				next += multi;
				p = position.board[next];
				if (p == 0) {
					//position.enPassantSquare = next - multi;
					//cout << "ep set: " << position.enPassantSquare << endl;
					Move m = Move(from, next,0);
					//m.print();
					moves.push_back(m);
				}
			}
		}
	}


	static void generateKnightMoves(int from,vector<Move>& moves) {
		static const int knightMoves[] = { 19, 21, 8, 12, -19, -21, -8, -12 };

		for (int i = 0; i <8; i++) {
			int next = from + knightMoves[i];
			if (!invalidSquare(next)) {
				int capturedPiece = position.board[next];
				if (((capturedPiece < 0) && (!position.onMove))||((capturedPiece > 0) && (position.onMove))) {
					//no move. sorry about the reverse logic
				}else{
					Move m = Move(from, next, abs(capturedPiece));
					moves.push_back(m);
				}
			}
		}
	}

	static vector<Move> generateKingMoves(int from,vector<Move>& moves) {
		generateKingMovesNoCastling(from, moves);
		position.generateCastling(from, moves);
		return moves;
	}
	static void generateQueenMoves(int from,vector<Move>& moves) {
		generateBishopMoves(from, moves);
		generateRookMoves(from, moves);
	}


	static void generateKingMovesNoCastling(int from,vector<Move>& moves) {

		static int kingMoves[] = { 9, 10, 11, -1, 1, -9, -10, -11 };

		for (int i = 0; i < 8; i++) {
			int next = from + kingMoves[i];
			if (!invalidSquare(next)) {
				int capturedPiece = position.board[next];
				if (((capturedPiece < 0) && (!position.onMove))||((capturedPiece > 0) && (position.onMove))) {
					//no move. sorry about the reverse logic
				}else{
					int capturedPiece = position.board[next];
					Move m = Move(from, next, abs(capturedPiece));
					moves.push_back(m);
				}
			}
		}
	}
	static void generateRookMoves(int from,vector<Move>& moves) {
		bool finished = false;
		for (int i = 1; i < 8; i++) {
			int next = from + i * 10;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -10;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * 1;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -1;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
	}

	static void generateBishopMoves(int from,vector<Move>& moves) {
		bool finished = false;
		for (int i = 1; i < 8; i++) {
			int next = from + i * 9;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -9;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * 11;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -11;
			finished = tryMove(from, next,moves);
			if (finished) {
				break;
			}
		}
	}
	static bool tryMove(int from, int next,vector<Move>& moves) {

		if (invalidSquare(next))
			return true;
		int piece = position.board[next];
		if (piece == 0) {
			Move move = Move(from, next,0);
			moves.push_back(move);
			return false;
		}
		//own piece
		if (((piece < 0) && (!position.onMove))||((piece > 0) && (position.onMove))) {
			return true;
		}
		//enemy piece, presumably
		Move move = Move(from, next, abs(piece));
		moves.push_back(move);
		return true;
	}
	//
	//	Move generateNextBishopCapture(int from, bool color) {
	//		SortedSet moves = new TreeSet();
	//		if (this.bishopCaptureCount == 4)
	//			return null;
	//		if (this.bishopCaptureCount == 0) {
	//			for (int i = 1; i < 8; i++) {
	//				int next = from + i * 9;
	//				if (next > 88)
	//					break;
	//				bool finished = tryMoveCapture(this, moves, from, next, color);
	//				if (finished) {
	//					break;
	//				}
	//			}
	//			this.bishopCaptureCount = 1;
	//			if (moves.size() == 1) {
	//				Move retVal = (Move) moves.first();
	//				return retVal;
	//			}
	//		}
	//		if (this.bishopCaptureCount == 1) {
	//			for (int i = 1; i < 8; i++) {
	//				int next = from + i * -9;
	//				if (next < 0)
	//					break;
	//				bool finished = tryMoveCapture(this, moves, from, next, color);
	//				if (finished) {
	//					break;
	//				}
	//			}
	//			this.bishopCaptureCount = 2;
	//			if (moves.size() == 1) {
	//				Move retVal = (Move) moves.first();
	//				return retVal;
	//			}
	//		}
	//		if (this.bishopCaptureCount == 2) {
	//			for (int i = 1; i < 8; i++) {
	//				int next = from + i * 11;
	//				if (next > 88)
	//					break;
	//				bool finished = tryMoveCapture(this, moves, from, next, color);
	//				if (finished) {
	//					break;
	//				}
	//			}
	//			this.bishopCaptureCount = 3;
	//			if (moves.size() == 1) {
	//				Move retVal = (Move) moves.first();
	//				return retVal;
	//			}
	//		}
	//		if (this.bishopCaptureCount == 3) {
	//			for (int i = 1; i < 8; i++) {
	//				int next = from + i * -11;
	//				if (next < 0)
	//					break;
	//				bool finished = tryMoveCapture(this, moves, from, next, color);
	//				if (finished) {
	//					break;
	//				}
	//			}
	//			this.bishopCaptureCount = 4;
	//			if (moves.size() == 1) {
	//				Move retVal = (Move) moves.first();
	//				return retVal;
	//			}
	//		}
	//		return null;
	//	}
	//
	//	Move generateNextCaptureMove(int i, int p, bool color) {
	//		SortedSet moves = new TreeSet();
	//		switch (p) {
	//		case -1:
	//
	//		case 1:
	//			return generateNextPawnCapture(moves, i, color);
	//
	//		case -2:
	//
	//		case 2:
	//			return generateNextKnightCapture(i, color, moves);
	//
	//		case -3:
	//
	//		case 3:
	//			return generateNextBishopCapture(i, color);
	//
	//		case -4:
	//
	//		case 4:
	//			return generateNextRookCapture(i, color, moves);
	//
	//		case -5:
	//
	//		case 5:
	//			return generateNextQueenCapture(i, color, moves);
	//
	//		case -6:
	//
	//		case 6:
	//			return generateNextKingCapture(i, color, moves);
	//		}
	//
	//		return null;
	//	}
	//
	//	Move generateNextKingCapture(int i, bool color, SortedSet moves) {
	//		if (this.kingCaptures == null) {
	//			this.kingCaptures = new TreeSet();
	//			generateKingCaptures(this, moves, i, color);
	//			this.kingCaptures = moves;
	//		}
	//		if (this.kingCaptures.size() == 0) {
	//			return null;
	//		}
	//
	//		Move retVal = (Move) this.kingCaptures.first();
	//		this.kingCaptures.remove(retVal);
	//		return retVal;
	//	}
	//
	//	Move generateNextKnightCapture(int i, bool color, SortedSet moves) {
	//		if (this.knightCaptures == null) {
	//			this.knightCaptures = new TreeSet();
	//			generateKnightCaptures(this, moves, i, color);
	//			this.knightCaptures = moves;
	//		}
	//		if (this.knightCaptures.size() == 0) {
	//			return null;
	//		}
	//
	//		Move retVal = (Move) this.knightCaptures.first();
	//		this.knightCaptures.remove(retVal);
	//		return retVal;
	//	}
	//
	//	Move generateNextNonCaptureMove(int i, int p, bool color) {
	//		SortedSet moves = new TreeSet();
	//		switch (p) {
	//		case -1:
	//
	//		case 1:
	//			return generateNextPawnNonCapture(moves, i, color);
	//
	//		case -2:
	//
	//		case 2:
	//			return null;
	//
	//		case -3:
	//
	//		case 3:
	//			return null;
	//
	//		case -4:
	//
	//		case 4:
	//			return null;
	//
	//		case -5:
	//
	//		case 5:
	//			return null;
	//
	//		case -6:
	//
	//		case 6:
	//			return null;
	//		}
	//
	//		return null;
	//	}
	//
	//	Move generateNextPawnCapture(SortedSet moves, int from, bool color) {
	//		if (this.lastPawnCapture < 0) {
	//			if (this.lastPawnCapture == -from)
	//				return null;
	//			this.lastPawnCapture = 0;
	//		}
	//		int multi = 10;
	//		int row = 20;
	//		if (color == BLACK) {
	//			multi = -multi;
	//			row = 70;
	//		}
	//		int file = from % 10;
	//
	//		if (this.lastPawnCapture == 0) {
	//			int next = from + multi - 1;
	//			if (file != 1)
	//				generatePawnCapture(this, moves, from, color, multi, next, row);
	//			if (!moves.isEmpty()) {
	//				this.lastPawnCapture = from;
	//				return (Move) moves.first();
	//			}
	//		}
	//		int next = from + multi + 1;
	//		if (file != 8)
	//			generatePawnCapture(this, moves, from, color, multi, next, row);
	//		this.lastPawnCapture = (-from);
	//		if (!moves.isEmpty()) {
	//			return (Move) moves.first();
	//		}
	//		return null;
	//	}
	//
	//	Move generateNextPawnNonCapture(SortedSet moves, int from, bool color) {
	//		if (this.lastPawnNonCapture == 2)
	//			return null;
	//		if (this.lastPawnNonCapture == 0) {
	//			Move m = generatePawnNonCapture1(from, color);
	//			if (m != null) {
	//				this.lastPawnNonCapture = 1;
	//				return m;
	//			}
	//		}
	//		if (this.lastPawnNonCapture == 1) {
	//			Move m = generatePawnNonCapture2(from, color);
	//			if (m != null) {
	//				this.lastPawnNonCapture = 2;
	//				return m;
	//			}
	//		}
	//		return null;
	//	}
	//
	//	Move generateNextQueenCapture(int i, bool color, SortedSet moves) {
	//		if (this.queenCaptures == null) {
	//			this.queenCaptures = new TreeSet();
	//			generateQueenCaptures(this, moves, i, color);
	//			this.queenCaptures = moves;
	//		}
	//		if (this.queenCaptures.size() == 0) {
	//			return null;
	//		}
	//
	//		Move retVal = (Move) this.queenCaptures.first();
	//		this.queenCaptures.remove(retVal);
	//		return retVal;
	//	}
	//
	//	Move generateNextRookCapture(int i, bool color, SortedSet moves) {
	//		if (this.rookCaptures == null) {
	//			this.rookCaptures = new TreeSet();
	//			generateRookCaptures(this, moves, i, color);
	//			this.rookCaptures = moves;
	//		}
	//		if (this.rookCaptures.size() == 0) {
	//			return null;
	//		}
	//
	//		Move retVal = (Move) this.rookCaptures.first();
	//		this.rookCaptures.remove(retVal);
	//		return retVal;
	//	}
	//
	//	SortedSet generateNonCaptureMoves() {
	//		SortedSet moves = new TreeSet();
	//		for (int i = 11; i < 89; i++) {
	//			int p = this.board[i];
	//			int type = Math.abs(p);
	//			if ((type >= 1) && (type <= 7)) {
	//				bool color = EdenBrain.convertColor(p);
	//				if (color.equals(onMove())) {
	//					SortedSet pieceMoves = generateNonCaptureMoves(i, p, color);
	//					moves.addAll(pieceMoves);
	//				}
	//			}
	//		}
	//
	//		return moves;
	//	}
	//
	//	SortedSet generateNonCaptureMoves(int square, int piece, bool color) {
	//		SortedSet moves = new TreeSet();
	//		switch (piece) {
	//		case -1:
	//
	//		case 1:
	//			generatePawnNonCaptures(this, moves, square, color);
	//			break;
	//
	//		case -2:
	//
	//		case 2:
	//			generateKnightNonCaptures(moves, square, color);
	//			break;
	//
	//		case -3:
	//
	//		case 3:
	//			generateBishopNonCaptures(moves, square, color);
	//			break;
	//
	//		case -4:
	//
	//		case 4:
	//			generateRookNonCaptures(moves, square, color);
	//			break;
	//
	//		case -5:
	//
	//		case 5:
	//			generateQueenNonCaptures(moves, square, color);
	//			break;
	//
	//		case -6:
	//
	//		case 6:
	//			generateKingNonCapturesNoCastling(moves, square, color);
	//			generateCastling(this, moves, square);
	//		}
	//
	//		return moves;
	//	}
	//
	//	Move generatePawnNonCapture1(int from, bool color) {
	//		int multi = 10;
	//		int row = 20;
	//		if (color == BLACK) {
	//			multi = -multi;
	//			row = 70;
	//		}
	//		int next = from + multi;
	//		int p = this.board[next];
	//		if (p == 0) {
	//			if (next / (row + multi * 6) == 1) {
	//				return new Move(this, from, next, Piece.create(next, color, 5));
	//			}
	//			return new Move(this, from, next, 0);
	//		}
	//
	//		return null;
	//	}
	//
	//	Move generatePawnNonCapture2(int from, bool color) {
	//		int multi = 10;
	//		int row = 20;
	//		if (color == BLACK) {
	//			multi = -multi;
	//			row = 70;
	//		}
	//		int next = from + multi;
	//		int p = this.board[next];
	//		if ((p == 0) && (from > row) && (row + 9 > from)) {
	//			next += multi;
	//			p = this.board[next];
	//			if (p == 0)
	//				return new Move(this, from, next, 0);
	//		}
	//		return null;
	//	}
	//
	//	void generatePawnNonCaptures(Position position, SortedSet moves, int from, bool color) {
	//		Move step1 = generatePawnNonCapture1(from, color);
	//		if (step1 != null)
	//			moves.add(step1);
	//		Move step2 = generatePawnNonCapture2(from, color);
	//		if (step2 != null) {
	//			moves.add(step2);
	//		}
	//	}
	//
	//	void generateQueenNonCaptures(Set moves, int from, bool color) {
	//		generateBishopNonCaptures(moves, from, color);
	//		generateRookNonCaptures(moves, from, color);
	//	}
	//
	//	void generateRookNonCaptures(Set moves, int from, bool color) {
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * 10;
	//			if (next > 88)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * -10;
	//			if (next < 0)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * 1;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * -1;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//	}
	//
};

