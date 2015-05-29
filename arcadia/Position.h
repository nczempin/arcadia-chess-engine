#pragma once
//

#include "Move.h"
#include "global.h"
#include "Character.h"
#include <iomanip>
#include <string>
#include <iterator>
#include <list>
using namespace std;

class Position{
public:

	int enPassantSquare;
private:  

	static const int MAX_BOARD_SIZE = 89;
	//
	//
	//	static const  int pieceValues[6];
	//
	//
	//
	//private:   static const Map* pawnHash;
	//
	//	static const bool WHITE = true;
	//
	//	static const bool BLACK = false;
	//
	//
public:
	int board[MAX_BOARD_SIZE];
	int whiteKing;
	int blackKing;

	void print(){
		cout << "onMove: " << (onMove?"W":"B")<<endl;
		for (int i = 11; i < MAX_BOARD_SIZE; ++i){
			if (i%10>=1 && i%10 <=8){
				cout << setw(2)<< board[i];
			}
			if (i%10==8){
				cout << endl;
			}
		}
		cout << endl;

	}

	void setToStart(){
		clear();
		board[15] = 6; //white king
		whiteKing = 15;
		board[13] = 3; //white bishop
		board[16] = 3; //white bishop
		board[12] = 2; // white knight
		board[17] = 2; //white knight
		board[11] = 4; //white rook
		board[18] = 4; //white rook
		board[14] = 5; //white queen
		for (int i = 1; i<=8; ++i){
			board[20+i] = 1; // white pawns
		}
		board[85] = -6; //black king
		blackKing = 85;
		board[83] = -3; //black bishop
		board[86] = -3; //black bishop
		board[82] = -2; // black knight
		board[87] = -2; //black knight
		board[81] = -4; //black rook
		board[88] = -4; //black rook
		board[84] = -5; //black queen

		for (int i = 1; i<=8; ++i){
			board[70+i] = -1; // black pawns
		}
		onMove = true;
		castleLongBlack = true;
		castleShortBlack = true;
		castleLongWhite = true;
		castleShortWhite = true;

	}

	//
	//	static const int WK = 6;
	//
	//	static  const int WN = 2;
	//
	//	static const int WP = 1;
	//
	//	static const int WQ = 5;
	//
	//	static const int WB = 3;
	//
	//	static const int WR = 4;
	//
	//	static const int BB = -3;
	//
	//	static const int BISHOP = 3;
	//
	//	static const int BK = -6;
	//
	//	static const int BN = -2;
	//
	//	static const int BOARD_SIZE = 89;
	//
	//	static const int BP = -1;
	//
	//	static const int BQ = -5;
	//
	//	static const int BR = -4;
	//
	//	static const int EMPTY = 0;
	//
	//	static const int INVALID = 4294967295;
	//
	//	static const int KING = 6;
	//
	//	static const int KNIGHT = 2;
	//
	//	static const int PAWN = 1;
	//
	//	static const int QUEEN = 5;
	//
	//	static const int ROOK = 4;
	static void copyBoard(int from[], int to[]) {
		memcpy(to,from, sizeof(int)*89);
	}
	Position copyPosition() {
		Position p =  Position();
		/*	bishopCaptureCount = 0;
		bishopNonCaptureCount = 0;

		blackPieces = new TreeSet();
		captureMoves = null;

		isGivingCheck = null;
		isReceivingCheck = null;
		isStartPosition = false;
		moveNr = 0;*/

		//whitePieces = new TreeSet();
		//Info.nodes += 1L;
		copyBoard(board, p.board);
		//whitePieces.addAll(position.whitePieces);
		p.whiteKing = whiteKing;
		//blackPieces.addAll(position.blackPieces);
		p.blackKing = blackKing;
		//isStartPosition = position.isStartPosition();
		p.enPassantSquare = enPassantSquare;
		p.onMove = onMove;
		p.castleLongBlack =castleLongBlack;
		p.castleLongWhite = castleLongWhite;
		p.castleShortBlack = castleShortBlack;
		p.castleShortWhite = castleShortWhite;

		p.hasCastledBlack = hasCastledBlack;
		p.hasCastledWhite = hasCastledWhite;

		/*
		isGivingCheck = null;
		isReceivingCheck = null;
		zobrist = position.zobrist;
		pawnZobrist = position.pawnZobrist;
		pzCache = position.pzCache;
		isEndGame = position.isEndGame;*/
		return p;
	}


	void makeTestMove(Move move) {
		//isGivingCheck = null;
		//legalMoves = null;
		//setStartPosition(false);
		int movingPiece = moveRaw(move);
		int movingPieceType = abs(movingPiece);
		if ((movingPieceType == 1) && (move.to == enPassantSquare)){
			testClearEnPassantCapture(move);
		}
		if ((movingPieceType == 1) && (abs(move.to - move.from) == 20)) {
			enPassantSquare = ((move.from + move.to) / 2);
		} else
			enPassantSquare = 0;

		//castling
		//if ((movingPieceType == 6) && (abs(move.from - move.to) == 2)) {
		// int rookTo;
		// int rookFrom;
		// if (move.to == 17) {
		//  rookFrom = 18;
		//  rookTo = 16;
		// } else {
		//  if (move.to == 87) {
		//   rookFrom = 88;
		//   rookTo = 86;
		//  } else {
		//   if (move.to == 13) {
		//	   rookFrom = 11;
		//	   rookTo = 14;
		//   } else {
		//	   if (move.to == 83) {
		//		   rookFrom = 81;
		//		   rookTo = 84;
		//	   } else {
		//		   rookFrom = -1;
		//		   rookTo = -1;
		//		   cerr << "move.from: " << move.from;
		//		   cerr << "move.to.getIndex: " << move.to << " which is impossible!";
		//	   }
		//   }
		//  }
		// }
		// Move rookJump = Move(rookFrom, rookTo);
		// moveRaw(rookJump);
		// if (movingPiece > 0) {
		//  hasCastledWhite = true;
		// } else
		//  hasCastledBlack = true;
		//}
		//if (movingPieceType == 6) {
		// if (onMove) {
		//  castleShortWhite = false;
		//  castleLongWhite = false;
		// } else {
		//  castleShortBlack = false;
		//  castleLongBlack = false;
		// }
		//} else if (movingPieceType == 4){
		// if (onMove) {
		//  if (move.from == 18) {
		//   castleShortWhite = false;
		//  } else if (move.from == 11) {
		//   castleLongWhite = false;
		//  }
		// } else if (move.from == 88) {
		//  castleShortBlack = false;
		// } else if (move.from == 81)
		//  castleLongBlack = false;

		//}
		//int p = board[11];
		//if (p != 4)
		// castleLongWhite = false;
		//p = board[18];
		//if (p != 4)
		// castleShortWhite = false;
		//p = board[81];
		//if (p != -4)
		// castleLongBlack = false;
		//p = board[88];
		//if (p != -4)
		// castleShortBlack = false;


		onMove = !onMove;
	}

	Position createTestPosition( Move move) {
		Position newPos = copyPosition();
		//	Info.testNodes += 1;
		newPos.makeTestMove(move);
		return newPos;
	}




	void makeMove(Move move) {
		//long z = getZobrist();
		//zobrist = updateZobristForMove(move, z);
		//long pz = getPawnZobrist().longValue();
		//long incrementalZobrist = updatePawnZobristForMove(move, pz);
		//pawnZobrist = new Long(incrementalZobrist);
		//bool updateDrawCount = false;
		//if ((move.capturedPiece != 0) || (Math.abs(EdenBrain.position.board[move.from]) == 1))
		//	updateDrawCount = true;
		//isGivingCheck = null;
		//legalMoves = null;
		//setStartPosition(false);
		int movingPiece = moveRaw(move);
		int movingPieceType = abs(movingPiece);
		if ((movingPieceType == 1) && (move.to == enPassantSquare))
			clearEnPassantCapture(move);
		if (enPassantSquare != 0) {
			enPassantSquare = 0;
			//updateZobristEnPassant();
		}
		if ((movingPieceType == 1) && (abs(move.to - move.from) == 20)) {
			enPassantSquare = ((move.from + move.to) / 2);
			//updateZobristEnPassant();
		}
		//castle
		if ((movingPieceType == 6) && (abs(move.from - move.to) == 2)) {
			int rookTo;
			int rookFrom;
			if (move.to == 17) {
				rookFrom = 18;
				rookTo = 16;
			} else {
				if (move.to == 87) {
					rookFrom = 88;
					rookTo = 86;
				} else {
					if (move.to == 13) {
						rookFrom = 11;
						rookTo = 14;
					} else {
						if (move.to == 83) {
							rookFrom = 81;
							rookTo = 84;
						} else {
							rookFrom = -1;
							rookTo = -1;
							cerr << "move.from: " << move.from << " to " << move.to <<endl;
							//throw new RuntimeException("move.to.getIndex: " + move.to + " which is impossible!");
						}
					}
				}
			}
			Move rookJump =  Move(rookFrom, rookTo,0);
			moveRaw(rookJump);
			if (movingPiece > 0) {
				hasCastledWhite = true;
			} else
				hasCastledBlack = true;
		}
		if (movingPieceType == 6) {
			if (onMove) {
				castleShortWhite = false;
				castleLongWhite = false;
			} else {
				castleShortBlack = false;
				castleLongBlack = false;
			}
		} else if (movingPieceType == 4)
			if (onMove) {
				if (move.from == 18) {
					castleShortWhite = false;
				} else if (move.from == 11) {
					castleLongWhite = false;
				}
			} else if (move.from == 88) {
				castleShortBlack = false;
			} else if (move.from == 81)
				castleLongBlack = false;
			int p = board[11];
			if (p != 4)
				castleLongWhite = false;
			p = board[18];
			if (p != 4)
				castleShortWhite = false;
			p = board[81];
			if (p != -4)
				castleLongBlack = false;
			p = board[88];
			if (p != -4)
				castleShortBlack = false;
			onMove = !onMove;

			// handle draws
			/*	if (!EdenBrain.withinAlphabeta) {
			if (updateDrawCount) {
			EdenBrain.threeDrawsTable.clear();
			} else {
			long myZobrist = getZobrist();
			Long zobi = new Long(myZobrist);
			if (EdenBrain.threeDrawsTable.containsKey(zobi)) {
			Integer count = (Integer) EdenBrain.threeDrawsTable.get(zobi);
			EdenBrain.threeDrawsTable.remove(zobi);
			if (count.intValue() >= 2)
			throw new IllegalStateException("three-fold repetition!");
			count = new Integer(count.intValue() + 1);
			EdenBrain.threeDrawsTable.put(zobi, count);
			} else {
			Integer count = new Integer(1);
			EdenBrain.threeDrawsTable.put(zobi, count);
			}
			}
			} else if (updateDrawCount) {
			EdenBrain.alphaBetaDraws.clear();
			} else {
			long myZobrist = getZobrist();
			Long zobi = new Long(myZobrist);
			int total = 0;
			if (EdenBrain.alphaBetaDraws.containsKey(zobi)) {
			total += ((Integer) EdenBrain.alphaBetaDraws.get(zobi)).intValue();

			if (EdenBrain.threeDrawsTable.containsKey(zobi)) {
			total += ((Integer) EdenBrain.threeDrawsTable.get(zobi)).intValue();
			} else {
			Integer count = new Integer(1);
			EdenBrain.alphaBetaDraws.put(zobi, count);
			}
			EdenBrain.alphaBetaDraws.remove(zobi);
			if (total >= 2)
			throw new ThreeRepetitionsAB("three-fold repetition!");
			Integer count = new Integer(total + 1);
			EdenBrain.alphaBetaDraws.put(zobi, count);
			}
			}*/
	}

	//static int convertToint(bool color, int rawint) {
	//		//if (color == null)
	//		//	return 0;
	//		if (color == BLACK) {
	//			switch (rawint) {
	//			case 1:
	//				return -1;
	//
	//			case 2:
	//				return -2;
	//
	//			case 3:
	//				return -3;
	//
	//			case 4:
	//				return -4;
	//
	//			case 5:
	//				return -5;
	//
	//			case 6:
	//				return -6;
	//			}
	//		} else
	//			switch (rawint) {
	//			case 1:
	//				return 1;
	//
	//			case 2:
	//				return 2;
	//
	//			case 3:
	//				return 3;
	//
	//			case 4:
	//				return 4;
	//
	//			case 5:
	//				return 5;
	//
	//			case 6:
	//				return 6;
	//			}
	//		//throw new AssertionError("should never happen");
	//	}
	//


	//	
	void generateCastling(const int from,vector<Move>& moves) {
		int p = board[from];
		int kingHome = -1;
		bool castlingLong;
		bool castlingShort;
		if (p == 6) {
			kingHome = 15;
			castlingShort = castleShortWhite;
			castlingLong = castleLongWhite;
		} else {
			kingHome = 85;
			castlingShort = castleShortBlack;
			castlingLong = castleLongBlack;
		}
		if (from != kingHome)
			return;
		int pieceNextToKingR = board[(from + 1)];
		if ((castlingShort) && (pieceNextToKingR == 0) && (board[(from + 2)] == 0)) {
			if (isReceivingCheck())
				return;
			Move testCastleThrough =  Move(from, from + 1,0);
			Position testPosition = createTestPosition(testCastleThrough);
			//Info::castlingNodes += 1;
			if (!testPosition.isGivingCheckForCastling(from + 1))
				moves.push_back(Move(from, from + 2,0));
		}
		if ((castlingLong) && (abs(board[(from - 1)]) == 0) && (board[(from - 2)] == 0) && (board[(from - 3)] == 0)) {
			if (isReceivingCheck())
				return;
			Move testCastleThrough = Move(from, from - 1,0);
			Position testPosition = createTestPosition(testCastleThrough);
			if (!testPosition.isGivingCheckForCastling(from - 1)) {
				moves.push_back(Move(from, from - 2,0));
			}
		}
	}

	void generateKingCaptures(vector<Move>& moves, int from, bool color) {
		static int kingMoves[] = { 9, 10, 11, -1, 1, -9, -10, -11 };

		for (int i = 0; i < 8; i++) {
			int next = from + kingMoves[i];
			if (!invalidSquare(next)) {
				int capturedPiece = board[next];
				if (capturedPiece != 0) {
					if ((capturedPiece < 0) && (color)) {
						moves.push_back(Move(from, next, capturedPiece));
					} else if ((capturedPiece > 0) && (!color)) {
						moves.push_back(Move(from, next, capturedPiece));
					}
				}
			}
		}
	}


	void generateKnightCaptures(vector<Move>& moves, int from, bool color) {
		static int knightMoves[] = { 19, 21, 8, 12, -19, -21, -8, -12 };

		for (int i = 0; i < 8; i++) {
			int next = from + knightMoves[i];
			if (!invalidSquare(next)) {
				int capturedPiece = board[next];
				if (capturedPiece != 0) {
					if ((capturedPiece < 0) && (color))
						moves.push_back( Move( from, next, abs(capturedPiece)));
					if ((capturedPiece > 0) && (!color)) {
						moves.push_back( Move( from, next, abs(capturedPiece)));
					}
				}
			}
		}
	}


	//
	//	static void generatePawnCapture(Position position, SortedSet moves, int from, bool color, int multi, int next, int row) {
	//		if (invalidSquare(next))
	//			return;
	//		int capturedPiece = position.board[next];
	//		if ((capturedPiece != 0) && (((capturedPiece < 0) && (color)) || ((capturedPiece > 0) && (!color))))
	//			if (next / (row + multi * 6) == 1) {
	//				moves.add( Move(from, next, Piece::create(next, color, 2), capturedPiece));
	//				moves.add( Move(from, next, Piece::create(next, color, 3), capturedPiece));
	//				moves.add( Move(from, next, Piece::create(next, color, 4), capturedPiece));
	//				moves.add( Move(from, next, Piece::create(next, color, 5), capturedPiece));
	//			} else {
	//				moves.add(Move(from, next, 0, capturedPiece));
	//			}
	//		if (position.enPassantSquare == next) {
	//			moves.add(Move(from, next));
	//		}
	//	}
	//
	//	static void generatePawnCaptures(Position position, SortedSet moves, int from, bool color) {
	//		int multi = 10;
	//		int row = 20;
	//		if (!color) {
	//			multi = -multi;
	//			row = 70;
	//		}
	//		int file = from % 10;
	//		int next = from + multi - 1;
	//		if (file != 1)
	//			generatePawnCapture(position, moves, from, color, multi, next, row);
	//		next = from + multi + 1;
	//		if (file != 8) {
	//			generatePawnCapture(position, moves, from, color, multi, next, row);
	//		}
	//	}
	//
	//	static void generatePawnMoves(Position position, SortedSet moves, int from, bool color) {
	//		generatePawnNonCapture(position, moves, from, color);
	//		generatePawnCaptures(position, moves, from, color);
	//	}
	//
	//	static void generatePawnNonCapture(Position position, SortedSet moves, int from, bool color) {
	//		int multi = 10;
	//		int row = 20;
	//		if (color == BLACK) {
	//			multi = -multi;
	//			row = 70;
	//		}
	//		int next = from + multi;
	//		int p = position.board[next];
	//		if (p == 0) {
	//			if (next / (row + multi * 6) == 1) {
	//				moves.add( Move(from, next, Piece::create(next, color, 2)));
	//				moves.add( Move(from, next, Piece::create(next, color, 3)));
	//				moves.add( Move( from, next, Piece::create(next, color, 4)));
	//				moves.add( Move(from, next, Piece::create(next, color, 5)));
	//			} else {
	//				moves.add( Move(from, next, 0));
	//			}
	//			if ((from > row) && (row + 9 > from)) {
	//				next += multi;
	//				p = position.board[next];
	//				if (p == 0) {
	//					moves.add( Move(from, next, 0));
	//				}
	//			}
	//		}
	//	}
	//
		void generateQueenCaptures(vector<Move>& moves, int from, bool color) {
			generateBishopCaptures(moves, from, color);
			generateRookCaptures(moves, from, color);
		}
	//
	//	static void generateQueenMoves(Position position, SortedSet moves, int from, bool color) {
	//		generateBishopMoves(position, moves, from, color);
	//		generateRookMoves(position, moves, from, color);
	//	}
	//
	void generatePawnCapture(vector<Move>& moves, int from, int multi, int next, int row, bool color) {
		if (invalidSquare(next))
			return;
		int capturedPiece = board[next];
		if ((capturedPiece != 0) && (((capturedPiece < 0) && (color)) || ((capturedPiece > 0) && (!color))))
			if (next / (row + multi * 6) == 1) {
				//promotion
				Move m = Move(from, next, capturedPiece, 5);
				moves.push_back(m);
#ifdef USE_UNDERPROMOTION
				m = Move(from, next, capturedPiece, 4);
				moves.push_back(m);
				m = Move(from, next, capturedPiece, 3);
				moves.push_back(m);
				m = Move(from, next, capturedPiece, 2);
				moves.push_back(m);
#endif
			} else {
				Move m = Move(from, next, capturedPiece);
				moves.push_back(m);
			}
			if (enPassantSquare == next) {
				Move m = Move(from, next, capturedPiece);
				moves.push_back(m);
			}
	}
	void generatePawnCaptures(vector<Move>& moves, int from, bool color) {
		if ((board[from]<0 && color)||(board[from]>0 && !color)){
			return;
		}
		int multi = 10;
		int row = 20;
		if (!color) {
			multi = -multi;
			row = 70;
		}
		int file = from % 10;
		int next = from + multi - 1;
		if (file != 1)
			generatePawnCapture(moves, from, multi, next, row, color);
		next = from + multi + 1;
		if (file != 8) {
			generatePawnCapture(moves, from, multi, next, row, color);
		}
	}
	void generateRookCaptures(vector<Move>&moves, int from, bool color) {
		for (int i = 1; i < 8; i++) {
			int next = from + i * 10;
	/*		if (next > 88)
				break;*/
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -10;
			//if (next < 0)
			//	break;
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * 1;
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -1;
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
	}


	//	static int getBishopValue(int square) {
	//		return bishopSquareValues[(square - 10)];
	//	}
	//
	//	static Position getEmpty() {
	//		return new Position();
	//	}
	//
	//	static int getKnightPcSqValue(int square) {
	//		return knightSquareValues[(square - 10)];
	//	}
	//
	//	static bool invalidSquare(int next) {
	//		bool isInvalid = false;
	//		if ((next < 11) || (next > 88))
	//			isInvalid = true;
	//		int mod = next % 10;
	//		if ((mod == 0) || (mod == 9))
	//			isInvalid = true;
	//		return isInvalid;
	//	}
	//

	//	//Move bestMove;
	//
	//	int bestValue;
	//
	//	int bishopCaptureCount;
	//
	//	SortedSet bishopCaptures;
	//
	//	int bishopNonCaptureCount;
	//
	//	SortedSet bishopNonCaptures;
	//
	//	int blackKing;
	//
	//	SortedSet blackPieces;
	//
	//	SortedSet captureMoves;
	//
	bool castleLongBlack;

	bool castleLongWhite;

	bool castleShortBlack;

	bool castleShortWhite;


	bool hasCastledBlack;

	bool hasCastledWhite;

	//	//bool isEndGame;
	//
	//	bool isGivingCheck;
	//
	//	bool isReceivingCheck;
	//
	//	bool isStartPosition;
	//
	//	SortedSet kingCaptures;
	//
	//	SortedSet kingNonCaptures;
	//
	//	SortedSet knightCaptures;
	//
	//	SortedSet knightNonCaptures;
	//
	//	int lastPawnCapture;
	//
	//	int lastPawnNonCapture;
	//
	//	SortedSet legalMoves;
	//
	//	int moveNr;
	//
	//	Move nextCaptureMove;
	//
	//	Move nextNonCaptureMove;
	//
	//
	//	int persistentSquareForCapture;
	//
	//	int persistentSquareForNonCapture;
	//
	//	SortedSet queenCaptures;
	//
	//	SortedSet queenNonCaptures;
	//
	//	SortedSet rookCaptures;
	//
	//	SortedSet rookNonCaptures;
	//
	//	int whiteKing;
	//
	//	SortedSet whitePieces;
	//
	//	long zobrist;
	//
	//	Long pzCache;
	//
	//	Long pawnZobrist;
	//
	//	PieceCount wpc;
	//
	//	PieceCount bpc;
	//
	//	Position() {
	//		bishopCaptureCount = 0;
	//		bishopNonCaptureCount = 0;
	//		blackKing = -1;
	//		blackPieces = new TreeSet();
	//		captureMoves = null;
	//		castleLongBlack = true;
	//		castleLongWhite = true;
	//		castleShortBlack = true;
	//		castleShortWhite = true;
	//		enPassantSquare = 0;
	//		hasCastledBlack = false;
	//		hasCastledWhite = false;
	//		isGivingCheck = null;
	//		isReceivingCheck = null;
	//		isStartPosition = false;
	//		moveNr = 0;
	//		onMove = WHITE;
	//		whiteKing = -1;
	//		whitePieces = new TreeSet();
	//		Info.nodes += 1L;
	//		board = new int[89];
	//		whitePieces.clear();
	//		whiteKing = -1;
	//		blackPieces.clear();
	//		blackKing = -1;
	//		clearBoard();
	//	}
	//
	//	Position(Position& position) {
	//		bishopCaptureCount = 0;
	//		bishopNonCaptureCount = 0;
	//		blackKing = -1;
	//		blackPieces = new TreeSet();
	//		captureMoves = null;
	//		castleLongBlack = true;
	//		castleLongWhite = true;
	//		castleShortBlack = true;
	//		castleShortWhite = true;
	//		enPassantSquare = 0;
	//		hasCastledBlack = false;
	//		hasCastledWhite = false;
	//		isGivingCheck = null;
	//		isReceivingCheck = null;
	//		isStartPosition = false;
	//		moveNr = 0;
	//		onMove = WHITE;
	//		whiteKing = -1;
	//		whitePieces = new TreeSet();
	//		Info.nodes += 1L;
	//		board = new int[89];
	//		copyBoard(position.board, board);
	//		whitePieces.addAll(position.whitePieces);
	//		whiteKing = position.whiteKing;
	//		blackPieces.addAll(position.blackPieces);
	//		blackKing = position.blackKing;
	//		isStartPosition = position.isStartPosition();
	//		onMove = position.onMove();
	//		castleLongBlack = position.getCastleLongBlack();
	//		castleLongWhite = position.getCastleLongWhite();
	//		castleShortBlack = position.getCastleShortBlack();
	//		castleShortWhite = position.getCastleShortWhite();
	//		enPassantSquare = position.enPassant();
	//		hasCastledBlack = position.hasCastledBlack();
	//		hasCastledWhite = position.hasCastledWhite();
	//		isGivingCheck = null;
	//		isReceivingCheck = null;
	//		zobrist = position.zobrist;
	//		pawnZobrist = position.pawnZobrist;
	//		pzCache = position.pzCache;
	//		isEndGame = position.isEndGame;
	//	}
	//
	//	void addPiece(Piece piece, String square) {
	//		piece.addPiece(this, square);
	//	}
	//
	//	void addStartPieces() {
	//		addPiece(Piece.create(new Square("a2"), WHITE, 1), "a2");
	//		addPiece(Piece.create(new Square("b2"), WHITE, 1), "b2");
	//		addPiece(Piece.create(new Square("c2"), WHITE, 1), "c2");
	//		addPiece(Piece.create(new Square("d2"), WHITE, 1), "d2");
	//		addPiece(Piece.create(new Square("e2"), WHITE, 1), "e2");
	//		addPiece(Piece.create(new Square("f2"), WHITE, 1), "f2");
	//		addPiece(Piece.create(new Square("g2"), WHITE, 1), "g2");
	//		addPiece(Piece.create(new Square("h2"), WHITE, 1), "h2");
	//		addPiece(Piece.create(new Square("a1"), WHITE, 4), "a1");
	//		addPiece(Piece.create(new Square("b1"), WHITE, 2), "b1");
	//		addPiece(Piece.create(new Square("c1"), WHITE, 3), "c1");
	//		addPiece(Piece.create(new Square("d1"), WHITE, 5), "d1");
	//		addPiece(Piece.create(new Square("e1"), WHITE, 6), "e1");
	//		whiteKing = 15;
	//		addPiece(Piece.create(new Square("f1"), WHITE, 3), "f1");
	//		addPiece(Piece.create(new Square("g1"), WHITE, 2), "g1");
	//		addPiece(Piece.create(new Square("h1"), WHITE, 4), "h1");
	//		addPiece(Piece.create(new Square("a7"), BLACK, 1), "a7");
	//		addPiece(Piece.create(new Square("b7"), BLACK, 1), "b7");
	//		addPiece(Piece.create(new Square("c7"), BLACK, 1), "c7");
	//		addPiece(Piece.create(new Square("d7"), BLACK, 1), "d7");
	//		addPiece(Piece.create(new Square("e7"), BLACK, 1), "e7");
	//		addPiece(Piece.create(new Square("f7"), BLACK, 1), "f7");
	//		addPiece(Piece.create(new Square("g7"), BLACK, 1), "g7");
	//		addPiece(Piece.create(new Square("h7"), BLACK, 1), "h7");
	//		addPiece(Piece.create(new Square("a8"), BLACK, 4), "a8");
	//		addPiece(Piece.create(new Square("b8"), BLACK, 2), "b8");
	//		addPiece(Piece.create(new Square("c8"), BLACK, 3), "c8");
	//		addPiece(Piece.create(new Square("d8"), BLACK, 5), "d8");
	//		addPiece(Piece.create(new Square("e8"), BLACK, 6), "e8");
	//		blackKing = 85;
	//		addPiece(Piece.create(new Square("f8"), BLACK, 3), "f8");
	//		addPiece(Piece.create(new Square("g8"), BLACK, 2), "g8");
	//		addPiece(Piece.create(new Square("h8"), BLACK, 4), "h8");
	//	}
	//
	//	void addToCheckHash(Integer integer) {
	//	}
	//
	//	void adjustKingSquaresForKBNK() {
	//		bool lightSquaredBishop = null;
	//		for (Iterator itW = whitePieces.iterator(); itW.hasNext();) {
	//			int s = ((Integer) itW.next()).intValue();
	//			int piece = board[s];
	//			if (piece == 3) {
	//				if (s % 2 == 0) {
	//					lightSquaredBishop = bool.TRUE;
	//					break;
	//				}
	//				lightSquaredBishop = bool.FALSE;
	//				break;
	//			}
	//		}
	//
	//		if (lightSquaredBishop == null) {
	//			for (Iterator itB = blackPieces.iterator(); itB.hasNext();) {
	//				int s = ((Integer) itB.next()).intValue();
	//				int piece = board[s];
	//				if (piece == -3) {
	//					if (s % 2 == 0) {
	//						lightSquaredBishop = bool.TRUE;
	//						break;
	//					}
	//					lightSquaredBishop = bool.FALSE;
	//					break;
	//				}
	//			}
	//		}
	//
	//		if (!lightSquaredBishop.boolValue()) {
	//			kingEndgameSquareValues = kingEndgameSquareValuesKBNKLight;
	//		} else {
	//			kingEndgameSquareValues = kingEndgameSquareValuesKBNKDark;
	//		}
	//	}
	//
	//	Move getBestMove() {
	//		return bestMove;
	//	}
	//
	//	int getBestValue() {
	//		return bestValue;
	//	}
	//
	void clear() {
		for (int i = 0; i < 89; i++) {
			board[i] = 0;
		}
	}
	//
	void clearEnPassantCapture(Move move) {
		//long zobi;
		if (move.to > move.from) { //move towards black's back rank
			board[move.to-10] = 0;
			//zobi = kleinerZobristEntfernen(move.to - 10);
			//clearSquare(move.to, -10, board);
			//blackPieces.remove(new Integer(move.to - 10));
		} else {
			board[move.to+10] = 0;
			//zobi = kleinerZobristEntfernen(move.to + 10);
			//clearSquare(move.to, 10, board);
			//whitePieces.remove(new Integer(move.to + 10));
		}
		//zobrist ^= zobi;
	}

	//	PieceCount countBlackPieces() {
	//		int queensCount = 0;
	//		int rookCount = 0;
	//		int knightsCount = 0;
	//		int bishopsCount = 0;
	//		int pawnsCount = 0;
	//		for (Iterator wpIt = blackPieces.iterator(); wpIt.hasNext();) {
	//			int i = ((Integer) wpIt.next()).intValue();
	//			int piece = board[i];
	//			switch (piece) {
	//			case -1:
	//				pawnsCount++;
	//				break;
	//
	//			case -4:
	//				rookCount++;
	//				break;
	//
	//			case -3:
	//				bishopsCount++;
	//				break;
	//
	//			case -2:
	//				knightsCount++;
	//				break;
	//
	//			case -5:
	//				queensCount++;
	//			}
	//
	//		}
	//
	//		PieceCount wpc = new PieceCount(pawnsCount, knightsCount, bishopsCount, rookCount, queensCount);
	//		return wpc;
	//	}
	//
	//	PieceCount countWhitePieces() {
	//		int queensCount = 0;
	//		int rookCount = 0;
	//		int knightsCount = 0;
	//		int bishopsCount = 0;
	//		int pawnsCount = 0;
	//		for (Iterator wpIt = whitePieces.iterator(); wpIt.hasNext();) {
	//			int i = ((Integer) wpIt.next()).intValue();
	//			int piece = board[i];
	//			switch (piece) {
	//			case 1:
	//				pawnsCount++;
	//				break;
	//
	//			case 4:
	//				rookCount++;
	//				break;
	//
	//			case 3:
	//				bishopsCount++;
	//				break;
	//
	//			case 2:
	//				knightsCount++;
	//				break;
	//
	//			case 5:
	//				queensCount++;
	//			}
	//
	//		}
	//
	//		PieceCount wpc = new PieceCount(pawnsCount, knightsCount, bishopsCount, rookCount, queensCount);
	//		return wpc;
	//	}
	//
	//	int enPassant() {
	//		return enPassantSquare;
	//	}
	//
	//	bool enPrise(Move prospectiveMove) {
	//		int next = prospectiveMove.to;
	//		Position dummy = createTestPosition(this, prospectiveMove);
	//		Info.enPriseNodes += 1;
	//		return !dummy.isAttacked(next, onMove());
	//	}
	//
	///*	bool equals(Position position) {
	//			if (!board.equals(position.board))
	//				return false;
	//			if (isStartPosition != position.isStartPosition())
	//				return false;
	//			if (!onMove.equals(position.onMove()))
	//				return false;
	//			if (castleLongBlack != position.getCastleLongBlack())
	//				return false;
	//			if (castleLongWhite != position.getCastleLongWhite())
	//				return false;
	//			if (castleShortBlack != position.getCastleShortBlack())
	//				return false;
	//			if (castleShortWhite != position.getCastleShortWhite())
	//				return false;
	//			if (enPassantSquare != position.enPassant())
	//				return false;
	//			if (hasCastledBlack != position.hasCastledBlack())
	//				return false;
	//			if (hasCastledWhite != position.hasCastledWhite()) {
	//				return false;
	//			}
	//
	//			isGivingCheck = null;
	//			isReceivingCheck = null;
	//			return true;
	//		
	//
	//	}
	//*/
	//	int evaluatePawnStructureEndgame() {
	//		Info.pawnStructureProbes += 1;
	//		Long pz = getPawnZobrist();
	//		if (pawnHash.containsKey(pz)) {
	//			Integer value = (Integer) pawnHash.get(pz);
	//			Info.pawnStructureHits += 1;
	//			return value.intValue();
	//		}
	//		Iterator whiteIt = whitePieces.iterator();
	//		int whiteCValue = 0;
	//		while (whiteIt.hasNext()) {
	//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
	//			int whitePiece = board[whiteSquare];
	//			if (whitePiece == 1) {
	//				whiteCValue += pieceValues[0];
	//				int file = whiteSquare % 10;
	//				whiteCValue += getPawnEndgameValue(whiteSquare, whitePiece, file);
	//			}
	//		}
	//		Iterator blackIt = blackPieces.iterator();
	//		int blackCValue = 0;
	//		while (blackIt.hasNext()) {
	//			int blackSquare = ((Integer) blackIt.next()).intValue();
	//			int blackPiece = board[blackSquare];
	//			if (blackPiece == -1) {
	//				blackCValue += pieceValues[0];
	//				int file = blackSquare % 10;
	//				blackCValue += getPawnEndgameValue(blackSquare, blackPiece, file);
	//			}
	//		}
	//		int retVal = whiteCValue - blackCValue;
	//		Info.phSize = pawnHash.size();
	//		if (Info.phSize < 256000)
	//			pawnHash.put(pz, new Integer(retVal));
	//		return retVal;
	//	}
	//
	//	int evaluatePawnStructureMidgame() {
	//		Info.pawnStructureProbes += 1;
	//		Long pz = getPawnZobrist();
	//		if (pawnHash.containsKey(pz)) {
	//			Integer value = (Integer) pawnHash.get(pz);
	//			Info.pawnStructureHits += 1;
	//			return value.intValue();
	//		}
	//		Iterator whiteIt = whitePieces.iterator();
	//		int whiteCValue = 0;
	//		while (whiteIt.hasNext()) {
	//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
	//			int whitePiece = board[whiteSquare];
	//			if (whitePiece == 1) {
	//				whiteCValue += pieceValues[0];
	//				int file = whiteSquare % 10;
	//				whiteCValue += getPawnMidgameValue(whiteSquare, whitePiece, file);
	//			}
	//		}
	//		Iterator blackIt = blackPieces.iterator();
	//		int blackCValue = 0;
	//		while (blackIt.hasNext()) {
	//			int blackSquare = ((Integer) blackIt.next()).intValue();
	//			int blackPiece = board[blackSquare];
	//			if (blackPiece == -1) {
	//				blackCValue += pieceValues[0];
	//				int file = blackSquare % 10;
	//				blackCValue += getPawnMidgameValue(blackSquare, blackPiece, file);
	//			}
	//		}
	//		int retVal = whiteCValue - blackCValue;
	//		Info.phSize = pawnHash.size();
	//		if (Info.phSize < 256000)
	//			pawnHash.put(pz, new Integer(retVal));
	//		return retVal;
	//	}
	//
	void fillRank(int rank, string currentRank) {
		int rankStart = 10 * (rank + 1);
		int next = rankStart + 1;
		for (int i = 0; i < currentRank.length(); i++) {
			char currChar = currentRank[i];
			if (Character::isDigit(currChar)) {
				int digit = Character::getNumericValue(currChar);
				//cout << "skipping " << digit << "("<<currChar << ")" << endl;
				for (int j = 0; j < digit; j++) {
					board[next] = 0;
					next++;
					if (next > 88) {
						break;
					}
				}
			} else if (Character::isLetter(currChar)) {
				switch (currChar) {
				case 'k':
					board[next] = -6;
					//blackPieces.add(new Integer(next));
					blackKing = next;
					break;

				case 'q':
					board[next] = -5;
					//blackPieces.add(new Integer(next));
					break;

				case 'r':
					board[next] = -4;
					//blackPieces.add(new Integer(next));
					break;

				case 'b':
					board[next] = -3;
					//blackPieces.add(new Integer(next));
					break;

				case 'n':
					board[next] = -2;
					//blackPieces.add(new Integer(next));
					break;

				case 'p':
					board[next] = -1;
					//blackPieces.add(new Integer(next));
					break;

				case 'K':
					board[next] = 6;
					//whitePieces.add(new Integer(next));
					whiteKing = next;
					break;

				case 'Q':
					board[next] = 5;
					//whitePieces.add(new Integer(next));
					break;

				case 'R':
					board[next] = 4;
					//whitePieces.add(new Integer(next));
					break;

				case 'B':
					board[next] = 3;
					//whitePieces.add(new Integer(next));
					break;

				case 'N':
					board[next] = 2;
					//whitePieces.add(new Integer(next));
					break;

				case 'P':
					board[next] = 1;
					//whitePieces.add(new Integer(next));
				}
				cout << next << ": " << board[next] << endl;

				next++;
			}
		}
	}

	int findKing(bool colorWhite) {
		if (colorWhite) {
			return whiteKing;
		}
		return blackKing;
	}
	bool tryMoveCapture(vector<Move>& moves, int from, int next, bool color) {
		if (invalidSquare(next))
			return true;
		int type =board[next];
		if (type == 0)
			return false;
		//ignore own pieces
		if ((type < 0) && (!color))
			return true;
		if ((type > 0) && (color)) {
			return true;
		}

		Move m = Move(from, next, abs(type));
		moves.push_back(m);
		return true;
	}

	void generateBishopCaptures(vector<Move>& moves, int from, bool color) {
		for (int i = 1; i < 8; i++) {
			int next = from + i * 9;
			//if (next > 88)
			//	break;
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -9;
			//if (next < 0)
			//	break;
			bool finished = tryMoveCapture(moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * 11;
			//if (next > 88)
			//	break;
			bool finished = tryMoveCapture(moves, from, next, color);
			if (finished) {
				break;
			}
		}
		for (int i = 1; i < 8; i++) {
			int next = from + i * -11;
			//if (next < 0)
			//	break;
			bool finished = tryMoveCapture( moves, from, next, color);
			if (finished) {
				break;
			}
		}
	}

	//	void generateBishopNonCaptures(Set moves, int from, bool color) {
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * 9;
	//			if (next > 88)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * -9;
	//			if (next < 0)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * 11;
	//			if (next > 88)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//		for (int i = 1; i < 8; i++) {
	//			int next = from + i * -11;
	//			if (next < 0)
	//				break;
	//			bool finished = tryMoveNonCapture(moves, from, next, color);
	//			if (finished) {
	//				break;
	//			}
	//		}
	//	}
	//
		//vector<Move> generateCaptureMoves() {
		//	vector<Move> moves;
		//	for (int i = 11; i < 89; i++) {
		//		int p = board[i];
		//		int type = abs(p);
		//		if ((type >= 1) && (type <= 7)) {
		//			bool color = convertColor(p);
		//			if (color==onMove) {
		//				vector<Move> pieceMoves = generateCaptureMoves(i, p, color);
		//				moves.merge(pieceMoves);
		//			}
		//		}
		//	}
	
		//	return moves;
		//}
	
		vector<Move> generateCaptureMoves(int i, int p, bool color) {
			vector<Move> moves;
			switch (p) {
			case -1:
			case 1:
				generatePawnCaptures(moves, i, color);
				break;
	
			case -2:
			case 2:
				generateKnightCaptures(moves, i, color);
				break;
	
			case -3:
			case 3:
				generateBishopCaptures(moves,i, color);
				break;
	
			case -4:
			case 4:
				generateRookCaptures( moves, i, color);
				break;
	
			case -5:
			case 5:
				generateQueenCaptures(moves, i, color);
				break;
	
			case -6:
			case 6:
				generateKingCaptures(moves, i, color);
			}
	
			return moves;
		}
	
	//	void generateKingNonCapturesNoCastling(Set moves, int from, bool color) {
	//		int[] kingMoves = { 9, 10, 11, -1, 1, -9, -10, -11 };
	//
	//		for (int i = 0; i < kingMoves.length; i++) {
	//			int next = from + kingMoves[i];
	//			if (!invalidSquare(next)) {
	//				int capturedPiece = board[next];
	//				if (capturedPiece == 0) {
	//					moves.add(new Move(this, from, next, 0, 0));
	//				}
	//			}
	//		}
	//	}
	//
	//	void generateKnightNonCaptures(Set moves, int from, bool color) {
	//		int[] knightMoves = { 19, 21, 8, 12, -19, -21, -8, -12 };
	//
	//		for (int i = 0; i < knightMoves.length; i++) {
	//			int next = from + knightMoves[i];
	//			if (!invalidSquare(next)) {
	//				int capturedPiece = board[next];
	//				if (capturedPiece == 0) {
	//					moves.add(new Move(this, from, next));
	//				}
	//			}
	//		}
	//	}
	//
	
#define WHITE true
#define BLACK false
	bool onMove;

	
	//	bool getCastleLongBlack() {
	//		return castleLongBlack;
	//	}
	//
	//	bool getCastleLongWhite() {
	//		return castleLongWhite;
	//	}
	//
	//	bool getCastleShortBlack() {
	//		return castleShortBlack;
	//	}
	//
	//	bool getCastleShortWhite() {
	//		return castleShortWhite;
	//	}
	//
	//	int getEndgameValue() {
	//		if ((wpc.isKBNK()) || (bpc.isKBNK()))
	//			adjustKingSquaresForKBNK();
	//		int whiteValue = 0;
	//		int blackValue = 0;
	//		bool possibleBishopPairWhite = false;
	//		bool possibleBishopPairBlack = false;
	//		int pawnStructureValue = evaluatePawnStructureEndgame();
	//		Iterator whiteIt = whitePieces.iterator();
	//		int whiteCValue = 0;
	//		int whiteMValue = 0;
	//		while (whiteIt.hasNext()) {
	//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
	//			int whitePiece = board[whiteSquare];
	//			if (whitePiece != 1) {
	//				whiteMValue += getPieceMaterialValue(whitePiece);
	//				if (whitePiece == 3) {
	//					if (possibleBishopPairWhite)
	//						whiteCValue += 50;
	//					possibleBishopPairWhite = true;
	//				}
	//				int file = whiteSquare % 10;
	//				whiteCValue += getPieceEndgameValue(whiteSquare, whitePiece, file);
	//			}
	//		}
	//		Iterator blackIt = blackPieces.iterator();
	//		int blackCValue = 0;
	//		int blackMValue = 0;
	//		while (blackIt.hasNext()) {
	//			int blackSquare = ((Integer) blackIt.next()).intValue();
	//			int blackPiece = board[blackSquare];
	//			if (blackPiece != -1) {
	//				blackMValue += getPieceMaterialValue(blackPiece);
	//				if (blackPiece == -3) {
	//					if (possibleBishopPairBlack)
	//						blackCValue += 50;
	//					possibleBishopPairBlack = true;
	//				}
	//				int file = blackSquare % 10;
	//				blackCValue += getPieceEndgameValue(blackSquare, blackPiece, file);
	//			}
	//		}
	//		blackValue += blackCValue;
	//		whiteValue += whiteCValue;
	//		if (whiteMValue > blackMValue + 105) {
	//			int diff = whiteMValue + blackMValue - 500;
	//			int bonus = (8000 - diff) / 100;
	//			if (bonus > 74)
	//				bonus = 74;
	//			whiteValue += bonus;
	//		} else if (blackMValue > whiteMValue + 105) {
	//			int diff = blackMValue + whiteMValue - 500;
	//			int bonus = (8000 - diff) / 100;
	//			if (bonus > 74)
	//				bonus = 74;
	//			blackValue += bonus;
	//		}
	//		int retVal = 0;
	//		retVal += whiteValue + whiteMValue + pawnStructureValue - blackValue - blackMValue;
	//		if (onMove() == BLACK)
	//			retVal = -retVal;
	//		return retVal;
	//	}
	//

	//	Long getPawnZobrist() {
	//		if (pawnZobrist != null)
	//			return pawnZobrist;
	//		long grosserZobrist = 0L;
	//		for (Iterator wIt = whitePieces.iterator(); wIt.hasNext();) {
	//			int square = ((Integer) wIt.next()).intValue();
	//			int figur = board[square];
	//			if (figur == 1) {
	//				long kleinerZobrist = kleinerZobristSetzen(figur, square);
	//				grosserZobrist ^= kleinerZobrist;
	//			}
	//		}
	//
	//		for (Iterator bIt = blackPieces.iterator(); bIt.hasNext();) {
	//			int square = ((Integer) bIt.next()).intValue();
	//			int figur = board[square];
	//			if (figur == -1) {
	//				long kleinerZobrist = kleinerZobristSetzen(figur, square);
	//				grosserZobrist ^= kleinerZobrist;
	//			}
	//		}
	//
	//		Long pz = new Long(grosserZobrist);
	//		pawnZobrist = pz;
	//		return pz;
	//	}
	//
//
	
	//	long getZobrist() {
	//		if (zobrist != 0L)
	//			return zobrist;
	//		long grosserZobrist = 0L;
	//		for (int i = 11; i < 89; i++) {
	//			int figur = board[i];
	//			if (figur != 0) {
	//				int spalte = i % 10;
	//				if ((spalte != 0) && (spalte != 9)) {
	//					long kleinerZobrist = kleinerZobristSetzen(figur, i);
	//					grosserZobrist ^= kleinerZobrist;
	//				}
	//			}
	//		}
	//
	//		if ((onMove != null) && (onMove.equals(BLACK)))
	//			grosserZobrist ^= EdenBrain.onMoveZobrist;
	//		if (enPassantSquare != 0)
	//			grosserZobrist ^= EdenBrain.enPassantZobrist;
	//		zobrist = grosserZobrist;
	//		return grosserZobrist;
	//	}
	//
	//
	//	int hashCode() {
	//		int base1 = board.hashCode();
	//		int base2 = 0;
	//		if (castleLongBlack)
	//			base2++;
	//		if (castleLongWhite)
	//			base2 += 2;
	//		if (castleShortBlack)
	//			base2 += 4;
	//		if (castleShortWhite)
	//			base2 += 8;
	//		if (hasCastledWhite)
	//			base2 += 16;
	//		if (hasCastledBlack)
	//			base2 += 32;
	//		if (onMove.boolValue())
	//			base2 += 64;
	//		int retVal = base1 * base2;
	//		return retVal;
	//	}
	//
	//	bool hasNextCaptureMove() {
	//		updateCaptureMove();
	//		return nextCaptureMove != null;
	//	}
	//
	//	bool hasNextNonCaptureMove() {
	//		updateNonCaptureMove();
	//		return nextNonCaptureMove != null;
	//	}
	//
	//	
	//	void initCaptureMoveGenerator() {
	//		nextCaptureMove = null;
	//		persistentSquareForCapture = 11;
	//		initializeCaptureMoveCounters();
	//	}
	//
	//	void initializeCaptureMoveCounters() {
	//		lastPawnCapture = 0;
	//		bishopCaptureCount = 0;
	//		knightCaptures = null;
	//		bishopCaptures = null;
	//		rookCaptures = null;
	//		queenCaptures = null;
	//		kingCaptures = null;
	//	}
	//
	//	void initializeNonCaptureMoveCounters() {
	//		lastPawnNonCapture = 0;
	//		bishopNonCaptureCount = 0;
	//		knightNonCaptures = null;
	//		bishopNonCaptures = null;
	//		rookNonCaptures = null;
	//		queenNonCaptures = null;
	//		kingNonCaptures = null;
	//	}
	//
	//	void initNonCaptureMoveGenerator() {
	//		nextNonCaptureMove = null;
	//		persistentSquareForNonCapture = 11;
	//		initializeNonCaptureMoveCounters();
	//	}
	//
	//	bool isAttacked(int i, bool color) {
	//		SortedSet moves = new TreeSet();
	//		generateBishopCaptures(moves, i, color);
	//		for (Iterator it = moves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			if ((pieceOn(move.to).getType() == 3) || (pieceOn(move.to).getType() == 5)) {
	//				return true;
	//			}
	//		}
	//		moves.clear();
	//		generateRookCaptures(this, moves, i, color);
	//		for (Iterator it = moves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			if ((pieceOn(move.to).getType() == 4) || (pieceOn(move.to).getType() == 5)) {
	//				return true;
	//			}
	//		}
	//		moves.clear();
	//		generateKingCaptures(this, moves, i, color);
	//		for (Iterator it = moves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			if (pieceOn(move.to).getType() == 6) {
	//				return true;
	//			}
	//		}
	//		moves.clear();
	//		generateKnightCaptures(this, moves, i, color);
	//		for (Iterator it = moves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			Piece p = pieceOn(move.to);
	//			if ((p != null) && (p.getType() == 2)) {
	//				return true;
	//			}
	//		}
	//		moves.clear();
	//		generatePawnCaptures(this, moves, i, color);
	//		for (Iterator it = moves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			if (pieceOn(move.to).getType() == 1) {
	//				return true;
	//			}
	//		}
	//		return false;
	//	}
	//
	
	//	bool isEndgame() {
	//		if ((isEndGame != null) && (isEndGame.equals(bool.TRUE)))
	//			return true;
	//		int lightPiecesCount = wpc.knightsCount + wpc.bishopsCount;
	//		int heavyPiecesCount = wpc.rookCount + wpc.queensCount;
	//		if (wpc.queensCount >= 1) {
	//			if (wpc.rookCount > 1)
	//				return false;
	//			if ((wpc.rookCount == 1) && (lightPiecesCount > 0))
	//				return false;
	//			return lightPiecesCount <= 2;
	//		}
	//		if ((wpc.rookCount > 1) && (lightPiecesCount > 2))
	//			return false;
	//		if ((wpc.rookCount == 1) && (lightPiecesCount > 3)) {
	//			return false;
	//		}
	//
	//		isEndGame = bool.TRUE;
	//		return true;
	//	}
	//

	//
	//	//bool isInsufficientMaterial(PieceCount pc) {
	//	//	return (pc.loneKing()) || (pc.oneLight()) || (pc.isNN());
	//	//}
	//
	//	//bool isInsufficientMaterial(PieceCount we, PieceCount other) {
	//	//	return (isInsufficientMaterial(we)) && (isInsufficientMaterial(other));
	//	//}
	//
		//
	//	bool isLegal(int from, int to, int promotedTo) {
	//		Move toConsider = new Move(this, from, to, promotedTo);
	//		SortedSet legalMoves = generateLegalMoves();
	//		for (Iterator it = legalMoves.iterator(); it.hasNext();) {
	//			Move move = (Move) it.next();
	//			if (toConsider.getText().equals(move.getText())) {
	//				return true;
	//			}
	//		}
	//		return false;
	//	}
	///*
	//	bool isMate() {
	//		if (!noMoves())
	//			return false;
	//		return isReceivingCheck();
	//	}
	//
	

	bool isGivingCheck() {
		//if (isGivingCheck != null)
		//	return isGivingCheck.boolValue();
		bool othercolor = !onMove;
		int currentPiece = findKing(othercolor);
		//if (currentPiece == -1)
		//	assert "no king found";//throw new IllegalStateException("no king found");
		int i = currentPiece;
		vector<Move> moves ;
		generateKnightCaptures( moves, i, othercolor);
		//cout << "knight captures: " << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		for (Move move:moves){
			int piece = abs(board[move.to]);
			if (piece == 2) {
				int t = board[move.to];
				bool c = t>0;//EdenBrain.convertColor(t);
				if (c!=othercolor) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		moves.clear();
		generateBishopCaptures(moves, i, othercolor);
		//cout << "bishop captures: " << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		for (Move move:moves){
			int piece = abs(board[move.to]);
			if ((piece == 3) || (piece == 5)) {
				int t = board[move.to];
				bool c = t>0;//convertColor(t);
				if (c!=othercolor) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		moves.clear();
		generateRookCaptures(moves, i, othercolor);
		//cout << "rook captures: " << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		for (Move move:moves){
			int piece = abs(board[move.to]);
			if ((piece == 4) || (piece == 5)) {
				int t = board[move.to];
				bool c = t>0;//EdenBrain.convertColor(t);
				if (c!=othercolor) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		moves.clear();
		generateKingCaptures(moves, i, othercolor);
		//	cout << "king captures: " << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		for (Move move:moves){
			int piece = abs(board[move.to]);
			if (piece == 6) {
				// king will always be the enemy
				//isGivingCheck = new bool(true);
				return true;
			}
		}

		moves.clear();
		generatePawnCaptures(moves, i, othercolor);
		//cout << "pawn captures: " << endl;
		//for (Move move:moves){
		//	move.print();
		//}
		for (Move move:moves){
			int piece =abs(board[move.to]);
			if (piece == 1) {
				int t = board[move.to];
				bool c = t>0;//EdenBrain.convertColor(t);
				if (c!=othercolor) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		//isGivingCheck = new bool(false);
		return false;
	}

	bool isGivingCheckForCastling(int square) {
		//if (isGivingCheck != null)
		//	return isGivingCheck.boolValue();
		int i = square;
		bool c1 = convertColor(board[i]);
		vector<Move> moves;
		generateBishopCaptures(moves, i, c1);
		for (Move move: moves){
			int piece = abs(board[move.to]);
			if ((piece == 3) || (piece == 5)) {
				int t = board[move.to];
				bool c = convertColor(t);
				if (c!=c1) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		moves.clear();
		generateRookCaptures(moves, i, c1);
		for (Move move: moves){
			int piece = abs(board[move.to]);
			if ((piece == 4) || (piece == 5)) {
				int t = board[move.to];
				bool c = convertColor(t);
				if (c!=c1) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		//moves.clear();
		//generateKingCaptures(this, moves, i, c1);
		//for (Iterator it = moves.iterator(); it.hasNext();) {
		//	Move move = (Move) it.next();
		//	int piece = Math.abs(board[move.to]);
		//	if (piece == 6) {
		//		isGivingCheck = new bool(true);
		//		return true;
		//	}
		//}

		moves.clear();
		generateKnightCaptures(moves, i, c1);
		for (Move move: moves){
			int piece = abs(board[move.to]);
			if (piece == 2) {
				int t = board[move.to];
				bool c = convertColor(t);
				if (c!=c1) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		moves.clear();
		generatePawnCaptures(moves, i, !onMove);
		for (Move move: moves){
			int piece = abs(board[move.to]);
			if ((piece == 1) && (abs(board[move.to]) == 1)) {
				int t = board[move.to];
				bool c = convertColor(t);
				if (c!=c1) {
					//isGivingCheck = new bool(true);
					return true;
				}
			}
		}

		//isGivingCheck = new bool(false);
		return false;
	}


	bool isGivingCheckNonKingMoving(int moveFrom) {
		//Integer zobrist = null;
		//if (this.isGivingCheck != null)
		//	return this.isGivingCheck.boolValue();
		bool othercolor = !onMove;
		int kingPosition = findKing(othercolor);
		//if (kingPosition == -1)
		//	throw new IllegalStateException("no king found");
		vector<Move> moves;
		if (onDiagonal(moveFrom, kingPosition)) {
			moves.clear();
			generateBishopCaptures(moves, kingPosition, othercolor);
			for (Move move : moves){
				int piece = abs(board[move.to]);
				if ((piece == 3) || (piece == 5)) {
					int t = board[move.to];
					bool c = t>0;//convertColor(t);
					if (c!=othercolor) {
						//isGivingCheck = new bool(true);
						return true;
					}
				}
			}

			moves.clear();
			//generatePawnCaptures(this, moves, kingPosition, othercolor);TODO
			//for (Iterator it = moves.iterator(); it.hasNext();) {
			//	Move move = (Move) it.next();
			//	int piece = Math.abs(this.board[move.to]);
			//	if (piece == 1) {
			//		int t = this.board[move.to];
			//		bool c = EdenBrain.convertColor(t);
			//		if (c.equals(othercolor)) {
			//			this.isGivingCheck = new bool(true);
			//			addToCheckHash(zobrist);
			//			return true;
			//		}
			//	}
			//}
		}

		if ((onRank(moveFrom, kingPosition)) || (onFile(moveFrom, kingPosition))) {
			moves.clear();
			generateRookCaptures(moves, kingPosition, othercolor); //TODO separate rank and file generation
			for (Move move:moves){
				int piece = abs(board[move.to]);
				if ((piece == 4) || (piece == 5)) {
					int t = board[move.to];
					bool c = t>0;//convertColor(t);
					if (c!=othercolor) {
						//isGivingCheck = new bool(true);
						return true;
					}
				}
			}
		}

		moves.clear();
		//generateKingCaptures(this, moves, kingPosition, othercolor); TODO
		//for (Iterator it = moves.iterator(); it.hasNext();) {
		//	Move move = (Move) it.next();
		//	int piece = Math.abs(this.board[move.to]);
		//	if (piece == 6) {
		//		this.isGivingCheck = new bool(true);
		//		addToCheckHash(zobrist);
		//		return true;
		//	}
		//}

		//		this.isGivingCheck = new bool(false);
		//		addToCheckHash(zobrist);
		return false;
	}
	bool isReceivingCheck() {
		/*	if (isReceivingCheck != null)
		return isReceivingCheck.boolValue();*/
		bool kingColor = onMove;
		int kingPosition = findKing(kingColor);
		//if (kingPosition == -1)
		//	throw new IllegalStateException("no king found");
		vector<Move> moves;
		generateRookCaptures(moves, kingPosition, kingColor);
		for (Move move: moves) {
			int pt = abs(board[move.to]);
			if (pt == 4 || pt == 5) {
				//isReceivingCheck = true;
				return true;
			}
		}

		moves.clear();
		generatePawnCaptures(moves, kingPosition, kingColor);
		for (Move move: moves) {
			if (abs(board[move.to]) == 1) {
				//isReceivingCheck = new bool(true);
				return true;
			}
		}

		moves.clear();
		generateKnightCaptures( moves, kingPosition, kingColor);
		for (Move move: moves) {
			if (abs(board[move.to]) == 2) {
				//isReceivingCheck = new bool(true);
				return true;
			}
		}

		moves.clear();
		generateBishopCaptures(moves, kingPosition, kingColor);
		for (Move move: moves) {
			int pt = abs(board[move.to]);
			if (pt == 3 || pt == 5){
				//isReceivingCheck = new bool(true);
				return true;
			}
		}

		moves.clear();
		//TODO	   generateKingMovesNoCastling( moves, kingPosition, kingColor);
		for (Move move: moves) {
			if (abs(board[move.to]) == 6) {
				//isReceivingCheck = new bool(true);
				return true;
			}
		}

		//isReceivingCheck = new bool(false);
		return false;
	}
	//
	//	bool isStartPosition() {
	//		return isStartPosition;
	//	}
	//
	//	long kleinerZobristEntfernen(int i) {
	//		int figur = board[i];
	//		return kleinerZobristSetzen(figur, i);
	//	}
	//
	//	long kleinerZobristSetzen(int figur, int square) {
	//		if (figur == 0)
	//			return 0L;
	//		if (figur > 0) {
	//			return EdenBrain.zobrists[0][(figur - 1)][(square - 11)];
	//		}
	//		return EdenBrain.zobrists[1][(-figur - 1)][(square - 11)];
	//	}*/
	//
	void makeMove(int from, int to, int captured, int promotedTo) {
		Move move = Move(from, to, captured, promotedTo);
		//bool isLegal = isLegal(from, to, promotedTo);
		//if (isLegal) {
		//	try {
		makeMove(move);
		//	} catch (ThreeRepetitionsAB e) {
		//		e.printStackTrace();
		//	}
		//} else {
		//	System.out.println("Illegal move:" + move);
		//}
	}

	//	
	void makeMove(string moveString)  {
		Move m = Move(moveString);
		makeMove(m.from, m.to, m.captured, m.promoted);
		//isGivingCheck = null;
		//isReceivingCheck = null;
	}
	//
	//	Piece makeNewPiece(Square to, String promotedTo, Piece newPiece) {
	//		if (promotedTo.equals("q")) {
	//			newPiece = Piece.create(to, onMove(), 5);
	//		} else if (promotedTo.equals("r")) {
	//			newPiece = Piece.create(to, onMove(), 4);
	//		} else if (promotedTo.equals("b")) {
	//			newPiece = Piece.create(to, onMove(), 3);
	//		} else if (promotedTo.equals("n"))
	//			newPiece = Piece.create(to, onMove(), 2);
	//		return newPiece;
	//	}
	//

	int moveRaw(Move move) {
		int movingPiece = board[move.from];
		int fromSquare = move.from;
		int capturedSquare = move.to;
		int capturedPiece = board[capturedSquare];
		/*	if (capturedPiece > 0) {
		whitePieces.remove(capturedSquare);
		if (capturedPiece == 6) {
		whiteKing = -1;
		}
		} else if (capturedPiece < 0) {
		blackPieces.remove(capturedSquare);
		if (capturedPiece == -6)
		blackKing = -1;
		}*/
		if (move.promoted == 0) {
			if (movingPiece > 0) {
				//	whitePieces.add(capturedSquare);
				//	whitePieces.remove(fromSquare);
				if (movingPiece == 6) {
					whiteKing = move.to;
				}
			} else {
				//	blackPieces.add(capturedSquare);
				//	blackPieces.remove(fromSquare);
				if (movingPiece == -6)
					blackKing = move.to;
			}
			board[move.to] = movingPiece;
			//cout << "set " << move.to << " to " << movingPiece<<endl;
			board[move.from] = 0;
			//cout << "cleared " << move.from <<endl;
			//clearSquare(move.from, 0, board);
		} else {
			//cout << move.toString() << " promoted" << endl;
			movingPiece = move.promoted;
			if (board[move.from] < 0)
				movingPiece *= -1;
			board[move.from] = 0;
			board[move.to] = movingPiece;
			//clearSquare(move.from, 0, board);

		}
		return movingPiece;
	}
	//
	//	//Move getNextCaptureMove() {
	//	//	updateCaptureMove();
	//	//	if (nextCaptureMove == null) {
	//	//		throw new NoSuchElementException("next without hasnext");
	//	//	}
	//
	//	//	Move retVal = new Move(nextCaptureMove);
	//	//	nextCaptureMove = null;
	//	//	return retVal;
	//	//}
	//
	//	//Move nextNonCaptureMove() {
	//	//	updateNonCaptureMove();
	//	//	if (nextNonCaptureMove == null) {
	//	//		throw new NoSuchElementException("next without hasnext");
	//	//	}
	//
	//	//	Move retVal = new Move(nextNonCaptureMove);
	//	//	nextNonCaptureMove = null;
	//	//	return retVal;
	//	//}
	//
	//	bool noMoves() {
	//		Collection moves = generateLegalMoves();
	//		return moves.size() == 0;
	//	}
	//
	bool onDiagonal(int moveFrom, int kingPosition) {
		int diff = moveFrom - kingPosition;
		return (diff % 11 == 0) || (diff % 9 == 0);
	}

	bool onFile(int moveFrom, int kingPosition) {
		int diff = moveFrom - kingPosition;
		return diff / 10 == 0;
	}


	bool onRank(int moveFrom, int kingPosition) {
		int col1 = moveFrom / 10;
		int col2 = moveFrom / 10;
		return col1 == col2;
	}
	//
	//	Piece pieceOn(int index) {
	//		return Piece.makePiece(index, board);
	//	}
	//
	//	Piece pieceOn(String string) {
	//		int index = decodeSquare(string);
	//		return pieceOn(index);
	//	}
	//
	//	TransEntry readHashtable(int depth, double extensions) {
	//		if (!Options.useTranspositionTable)
	//			return null;
	//		Info.hashReads += 1;
	//		int depthToGo = Info.idDepth + (int) extensions - depth;
	//		long z = getZobrist();
	//		Long zobi = new Long(z);
	//		if (EdenBrain.transpositions.containsKey(zobi)) {
	//			TransEntry te = (TransEntry) EdenBrain.transpositions.get(zobi);
	//			int height = te.getDepth();
	//			if (depthToGo > height) {
	//				Info.hashDepthMiss += 1;
	//				return null;
	//			}
	//
	//			Info.hashHitCount += 1;
	//			return te;
	//		}
	//
	//		Info.hashMiss += 1;
	//		return null;
	//	}
	//

	//	void setBestMove(Move bestMove) {
	//		bestMove = bestMove;
	//	}
	//
	//	void setBestValue(int bestValue) {
	//		bestValue = bestValue;
	//	}
	//
	void setFenPosition(string fenString) {
		clear();
		vector<string> fenFields = split(fenString,' ');
		//for(string field: fenFields){
		//	cout << field<< endl;
		//}
		string fenPosition = fenFields[0];
		vector<string> ranks = split(fenPosition,'/');
	/*	for(string rank: ranks){
			cout << rank<< endl;
		}*/
		for (int i = 0; i < 8; i++) {
			string currentRank = ranks[(7 - i)];
			fillRank(i, currentRank);
		}

		string fenOnMove = fenFields[1];
		if (fenOnMove=="w") {
			onMove = WHITE;
		} else if (fenOnMove=="b"){
			onMove = BLACK;
		}else{
			//huh?
		}
		string fenCastling = fenFields[2];
		castleShortWhite = (fenCastling.find('K') != string::npos);
		castleLongWhite = (fenCastling.find('Q') != string::npos);
		castleShortBlack = (fenCastling.find('k') != string::npos);
		castleLongBlack = (fenCastling.find('q') != string::npos);

		string fenEnPassant = fenFields[3];
		if (fenEnPassant=="-") {
			enPassantSquare = 0;
		} else {
			enPassantSquare = decodeSquare(fenEnPassant);
		}
	}

	//	void setOnMove(bool onMove) {
	//		onMove = onMove;
	//	}
	//
	//	void setStartPosition(bool startPosition) {
	//		isStartPosition = startPosition;
	//	}
	//
	//	void setToStartPosition() {
	//		clearBoard();
	//		addStartPieces();
	//		castleShortWhite = true;
	//		castleLongWhite = true;
	//		castleShortBlack = true;
	//		castleLongBlack = true;
	//		enPassantSquare = 0;
	//		onMove = WHITE;
	//		isGivingCheck = null;
	//		isReceivingCheck = null;
	//		setStartPosition(true);
	//	}
	//
	void testClearEnPassantCapture(Move move) {
		if (move.to > move.from) {
			board[move.to-10] = 0;
			//			clearSquare(move.to, -10, board);
			//			blackPieces.remove(new Integer(move.to - 10));
		} else {
			board[move.to+10] = 0;
			//			clearSquare(move.to, 10, board);
			//			whitePieces.remove(new Integer(move.to + 10));
		}
	}
	//
	//	String toString() {
	//		return board.toString();
	//	}
	//

	//
	//	int typeOn(int nextIndex) {
	//		return board[nextIndex];
	//	}
	//
	//	void updateCaptureMove() {
	//		if (nextCaptureMove != null)
	//			return;
	//		bool color = null;
	//		bool finished = false;
	//		while (!finished) {
	//			if (persistentSquareForCapture > 88)
	//				return;
	//			int p = board[persistentSquareForCapture];
	//			int type = Math.abs(p);
	//			if ((type < 1) || (type > 6)) {
	//				persistentSquareForCapture += 1;
	//			} else {
	//				color = EdenBrain.convertColor(p);
	//				if (!color.equals(onMove())) {
	//					persistentSquareForCapture += 1;
	//				} else {
	//					Move nextCapture = generateNextCaptureMove(persistentSquareForCapture, p, color);
	//					if (nextCapture != null) {
	//						nextCaptureMove = nextCapture;
	//						finished = true;
	//						break;
	//					}
	//					initializeCaptureMoveCounters();
	//					persistentSquareForCapture += 1;
	//				}
	//			}
	//		}
	//	}
	//
	//	void updateNonCaptureMove() {
	//		if (nextNonCaptureMove != null)
	//			return;
	//		bool color = null;
	//		bool finished = false;
	//		while (!finished) {
	//			if (persistentSquareForNonCapture > 88)
	//				return;
	//			int p = board[persistentSquareForNonCapture];
	//			int type = Math.abs(p);
	//			if ((type < 1) || (type > 6)) {
	//				persistentSquareForNonCapture += 1;
	//			} else {
	//				color = EdenBrain.convertColor(p);
	//				if (!color.equals(onMove())) {
	//					persistentSquareForNonCapture += 1;
	//				} else {
	//					Move nextNonCapture = generateNextNonCaptureMove(persistentSquareForNonCapture, p, color);
	//					if (nextNonCapture != null) {
	//						nextNonCaptureMove = nextNonCapture;
	//						finished = true;
	//						break;
	//					}
	//					initializeNonCaptureMoveCounters();
	//					persistentSquareForNonCapture += 1;
	//				}
	//			}
	//		}
	//	}
	//
	//	long updatePawnZobristForMove(Move move, long pzobrist) {
	//		int sourceType = board[move.from];
	//		long zoFrom = 0L;
	//		long zoTo = 0L;
	//		if ((sourceType == 1) || (sourceType == -1)) {
	//			zoFrom = kleinerZobristEntfernen(move.from);
	//			if (move.promotedTo == 0)
	//				zoTo = kleinerZobristSetzen(sourceType, move.to);
	//		}
	//		long zoKick = 0L;
	//		if ((board[move.to] == 1) || (board[move.to] == -1))
	//			zoKick = kleinerZobristEntfernen(move.to);
	//		pzobrist ^= zoFrom;
	//		pzobrist ^= zoTo;
	//		pzobrist ^= zoKick;
	//		return pzobrist;
	//	}
	//
	//	void updateZobristEnPassant() {
	//		zobrist ^= EdenBrain.enPassantZobrist;
	//	}
	//
	//	long updateZobristForMove(Move move, long z) {
	//		int sourceType = board[move.from];
	//		long zoFrom = kleinerZobristEntfernen(move.from);
	//		long zoKick = 0L;
	//		if (move.capturedPiece != 0)
	//			zoKick = kleinerZobristEntfernen(move.to);
	//		long zoTo = kleinerZobristSetzen(sourceType, move.to);
	//		if (move.promotedTo != 0) {
	//			int sgn = Math.abs(sourceType) / sourceType;
	//			int pieceToPromote = sgn * move.promotedTo;
	//			zoTo = kleinerZobristSetzen(pieceToPromote, move.to);
	//		}
	//		long zoRookJumpFrom = 0L;
	//		long zoRookJumpTo = 0L;
	//		if (move.isCastling(Math.abs(board[move.from]))) {
	//			int rookJumpTo;
	//			int rookJumpFrom;
	//			if (move.to % 10 == 7) {
	//				rookJumpFrom = move.to + 1;
	//				rookJumpTo = move.to - 1;
	//			} else {
	//				rookJumpFrom = move.to - 2;
	//				rookJumpTo = move.to + 1;
	//			}
	//			zoRookJumpFrom = kleinerZobristEntfernen(rookJumpFrom);
	//			zoRookJumpTo = kleinerZobristSetzen(board[rookJumpFrom], rookJumpTo);
	//		}
	//		z ^= zoFrom;
	//		z ^= zoTo;
	//		z ^= zoRookJumpFrom;
	//		z ^= zoRookJumpTo;
	//		z ^= zoKick;
	//		z ^= EdenBrain.onMoveZobrist;
	//		return z;
	//	}
	//
	//	void writeHashtable(Move move, int depth, double extensions, int value, int originalAlpha, int beta) {
	//		assert (value < 99999);
	//
	//		if (!Options.useTranspositionTable)
	//			return;
	//		if (move == null) {
	//			System.out.println("debug: move==null: movestack:" + EdenBrain.moveStack);
	//			RuntimeException e = new IllegalStateException("move = null");
	//			e.printStackTrace();
	//			if (Options.DEBUG)
	//				throw e;
	//		}
	//		int depthToGo = Info.idDepth + (int) extensions - depth;
	//		long z = getZobrist();
	//		Long zobi = new Long(z);
	//		ValidFlag validFlag = new ValidFlag();
	//		if ((value > originalAlpha) && (value < beta)) {
	//			validFlag.setNr(1);
	//		} else if (value >= beta) {
	//			validFlag.setNr(4);
	//		} else if (value <= originalAlpha) {
	//			validFlag.setNr(2);
	//			move = null;
	//		}
	//		TransEntry te = new TransEntry(move, value, depthToGo, z, validFlag);
	//		Info.hashFull = EdenBrain.transpositions.size() / (Options.MAX_TRANSPOSITIONS / 1000);
	//		if (Info.hashFull < 1000) {
	//			EdenBrain.transpositions.put(zobi, te);
	//		}
	//	}
	//
};