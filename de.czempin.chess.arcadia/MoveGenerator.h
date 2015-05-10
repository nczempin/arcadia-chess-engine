#pragma once
#include <iostream>
#include "Position.h"
using namespace std;
class MoveGenerator
{
public:
	MoveGenerator(void);
	~MoveGenerator(void);
private:
	Position position;
public: 
	void generateAllMoves(Position position) {
		this->position = position;
		for (int i = 11; i < 89; i++) {
			int piece = position.board[i];
			int type = abs(piece);
			if ((type >= 1) && (type <= 6)) {
				bool color = BLACK;
				if (piece > 0) {
					color = WHITE;
				}
				if (color==position.onMove) {
					generateMoves(i, piece, color);
				}
			}
		}
		//return moves;
	}
	//
	void generateMoves(int i, int p, bool color) {
		switch (p) {
			//		case -1:
			//
			//		case 1:
			//			generatePawnMoves(this, moves, i, color);
			//			break;
			//
			//		case -2:
			//
			//		case 2:
			//			generateKnightMoves(this, moves, i, color);
			//			break;
			//
			//		case -3:
			//
			//		case 3:
			//			generateBishopMoves(this, moves, i, color);
			//			break;
			//
			//		case -4:
			//
			//		case 4:
			//			generateRookMoves(this, moves, i, color);
			//			break;
			//
			//		case -5:
			//
			//		case 5:
			//			generateQueenMoves(this, moves, i, color);
			//			break;
			//
		case -6:
		case 6:
			generateKingMoves(i);
			break;
		}

	}
	void generateKingMoves(int from) {
		generateKingMovesNoCastling(from);
		//generateCastling(position, moves, from);
	}
	static bool invalidSquare(int next) {
		bool isInvalid = false;
		if ((next < 11) || (next > 88))
			isInvalid = true;
		int mod = next % 10;
		if ((mod == 0) || (mod == 9))
			isInvalid = true;
		return isInvalid;
	}

	void generateKingMovesNoCastling(int from) {
		int kingMoves[] = { 9, 10, 11, -1, 1, -9, -10, -11 };

		for (int i = 0; i < 8; i++) {
			int next = from + kingMoves[i];
			if (!invalidSquare(next)) {
				int capturedPiece = position.board[next];
				if (capturedPiece == 0) {
					//moves.add(Move(from, next));
					cout << from << "-" << next << endl;
				} else if ((capturedPiece < 0) && (position.onMove)) {
					//moves.add(Move(from, next, 0, capturedPiece));
				} else if ((capturedPiece > 0) && (!position.onMove)) {
					//moves.add(Move(from, next, 0, capturedPiece));
				}
			}
		}
	}

	//
	//	Move generateNextBishopCapture(int from, Boolean color) {
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
	//	Move generateNextCaptureMove(int i, int p, Boolean color) {
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
	//	Move generateNextKingCapture(int i, Boolean color, SortedSet moves) {
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
	//	Move generateNextKnightCapture(int i, Boolean color, SortedSet moves) {
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
	//	Move generateNextNonCaptureMove(int i, int p, Boolean color) {
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
	//	Move generateNextPawnCapture(SortedSet moves, int from, Boolean color) {
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
	//	Move generateNextPawnNonCapture(SortedSet moves, int from, Boolean color) {
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
	//	Move generateNextQueenCapture(int i, Boolean color, SortedSet moves) {
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
	//	Move generateNextRookCapture(int i, Boolean color, SortedSet moves) {
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
	//				Boolean color = EdenBrain.convertColor(p);
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
	//	SortedSet generateNonCaptureMoves(int square, int piece, Boolean color) {
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
	//	Move generatePawnNonCapture1(int from, Boolean color) {
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
	//	Move generatePawnNonCapture2(int from, Boolean color) {
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
	//	void generatePawnNonCaptures(Position position, SortedSet moves, int from, Boolean color) {
	//		Move step1 = generatePawnNonCapture1(from, color);
	//		if (step1 != null)
	//			moves.add(step1);
	//		Move step2 = generatePawnNonCapture2(from, color);
	//		if (step2 != null) {
	//			moves.add(step2);
	//		}
	//	}
	//
	//	void generateQueenNonCaptures(Set moves, int from, Boolean color) {
	//		generateBishopNonCaptures(moves, from, color);
	//		generateRookNonCaptures(moves, from, color);
	//	}
	//
	//	void generateRookNonCaptures(Set moves, int from, Boolean color) {
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
