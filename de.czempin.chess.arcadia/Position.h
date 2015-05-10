#pragma once
//
//#include "Map.h"
//#include "Set.h"
//#include "String.h"
//#include "SortedSet.h"
//#include "Boolean.h"
//#include "Square.h"
//#include "Move.h"
//#include "Long.h"
//#include "PieceCount.h"
//#include "Piece.h"
//#include "Integer.h"
//#include "TransEntry.h"
//#include "Character.h"
//#include "Info.h"
//#include "TreeSet.h"
#include <string>
using namespace std;

class Position{
public:
//	//void generateMoves();
//private:
//	int onMove;
//	bool convertColor(int p){
//		return p > 0;
//	}
	int enPassantSquare;
private:  static const int MAX_BOARD_SIZE = 89;
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
public:int board[MAX_BOARD_SIZE];
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



	   
	static string encodeSquare(int square) {
		int ten =square / 10;
		int one = square - ten * 10;
		char letter = (int)'a' + one - 1;	
		char number = (int)'1' + ten - 1;	
		string retVal;
		retVal+=letter;
		retVal+=number;

		return retVal;
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
//	//static void copyBoard(int[] from, int[] to) {
//	//	System.arraycopy(from, 0, to, 0, from.length);
//	//}
//
//	 static Position copyPosition(Position position) {
//	
//			return Position(position);
//
//	}
//
//	//static Position createPosition(Position p, Move move) throws ThreeRepetitionsAB {
//	//	Position newPos = copyPosition(p);
//	//	newPos.makeMove(move);
//	//	return newPos;
//	//}
//
//	 static Position createTestPosition(Position p, Move move) {
//		Position newPos = copyPosition(p);
//		Info::testNodes += 1;
//		newPos.makeTestMove(move);
//		return newPos;
//	}
//
//	 int decodePiece(String promotedTo) {
//		int retValue = 0;
//		if (promotedTo.equals("q")) {
//			retValue = 5;
//		} else if (promotedTo.equals("r")) {
//			retValue = 4;
//		} else if (promotedTo.equals("b")) {
//			retValue = 3;
//		} else if (promotedTo.equals("n"))
//			retValue = 2;
//		return retValue;
//	}
//
//	 int decodeSquare(String square) {
//		char letter = square.charAt(0);
//		char digit = square.charAt(1);
//		int one = Character::getNumericValue(letter) - Character::getNumericValue('a') + 1;
//		int ten = Character::getNumericValue(digit);
//		int index = 10 * ten + one;
//		return index;
//	}
//static void generateBishopMoves(Position position, SortedSet moves, int from, Boolean color) {
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 9;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -9;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 11;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -11;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//	}
//
//	 string encodeSquare(int square) {
//		int ten = square / 10;
//		int one = square - ten * 10;
//		char letter = 97 + one - 1;
//		char digit = (char)ten;
//		return ""+letter + digit;
//	}
//
//
//	
//	static void generateCastling(Position position, Set moves, int fromSquare) {
//		int from = fromSquare;
//		int p = position.board[from];
//		int kingHome = -1;
//		bool castlingLong;
//		bool castlingShort;
//		if (p == 6) {
//			kingHome = 15;
//			castlingShort = position.getCastleShortWhite();
//			castlingLong = position.getCastleLongWhite();
//		} else {
//			kingHome = 85;
//			castlingShort = position.getCastleShortBlack();
//			castlingLong = position.getCastleLongBlack();
//		}
//		if (from != kingHome)
//			return;
//		int pieceNextToKingR = position.board[(from + 1)];
//		if ((castlingShort) && (pieceNextToKingR == 0) && (position.board[(from + 2)] == 0)) {
//			if (position.isReceivingCheck)
//				return;
//			Move testCastleThrough =  Move(fromSquare, from + 1);
//			Position testPosition = createTestPosition(position, testCastleThrough);
//			Info::castlingNodes += 1;
//			if (!testPosition.isGivingCheckForCastling(from + 1))
//				moves.add(Move(fromSquare, from + 2));
//		}
//		if ((castlingLong) && (abs(position.board[(from - 1)]) == 0) && (position.board[(from - 2)] == 0) && (position.board[(from - 3)] == 0)) {
//			if (position.isReceivingCheck)
//				return;
//			Move testCastleThrough = Move(fromSquare, from - 1);
//			Position testPosition = createTestPosition(position, testCastleThrough);
//			if (!testPosition.isGivingCheckForCastling(from - 1)) {
//				moves.add(Move(fromSquare, from - 2));
//			}
//		}
//	}
//
//	static void generateKingCaptures(Position position, Set moves, int from, bool color) {
//		int kingMoves[] = { 9, 10, 11, -1, 1, -9, -10, -11 };
//
//		for (int i = 0; i < 8; i++) {
//			int next = from + kingMoves[i];
//			if (!invalidSquare(next)) {
//				int capturedPiece = position.board[next];
//				if (capturedPiece != 0) {
//					if ((capturedPiece < 0) && (color)) {
//						moves.add(Move(from, next, 0, capturedPiece));
//					} else if ((capturedPiece > 0) && (!color)) {
//						moves.add(Move(from, next, 0, capturedPiece));
//					}
//				}
//			}
//		}
//	}
//

//	static void generateKnightCaptures(Position position, Set moves, int from, bool color) {
//		int knightMoves[] = { 19, 21, 8, 12, -19, -21, -8, -12 };
//
//		for (int i = 0; i < 8; i++) {
//			int next = from + knightMoves[i];
//			if (!invalidSquare(next)) {
//				int capturedPiece = position.board[next];
//				if (capturedPiece != 0) {
//					if ((capturedPiece < 0) && (color))
//						moves.add( Move( from, next, 0, capturedPiece));
//					if ((capturedPiece > 0) && (!color)) {
//						moves.add( Move( from, next, 0, capturedPiece));
//					}
//				}
//			}
//		}
//	}
//
//	static void generateKnightMoves(Position position, Set moves, int from, bool color) {
//		int knightMoves[] = { 19, 21, 8, 12, -19, -21, -8, -12 };
//
//		for (int i = 0; i <8; i++) {
//			int next = from + knightMoves[i];
//			if (!invalidSquare(next)) {
//				int capturedPiece = position.board[next];
//				if (capturedPiece == 0) {
//					moves.add(Move(from, next));
//				} else if ((capturedPiece < 0) && (color)) {
//					moves.add(Move(from, next, 0, capturedPiece));
//				} else if ((capturedPiece > 0) && (!color)) {
//					moves.add(Move(from, next, 0, capturedPiece));
//				}
//			}
//		}
//	}
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
//	static void generateQueenCaptures(Position position, Set moves, int from, Boolean color) {
//		position.generateBishopCaptures(moves, from, color);
//		generateRookCaptures(position, moves, from, color);
//	}
//
//	static void generateQueenMoves(Position position, SortedSet moves, int from, Boolean color) {
//		generateBishopMoves(position, moves, from, color);
//		generateRookMoves(position, moves, from, color);
//	}
//
//	static void generateRookCaptures(Position position, Set moves, int from, Boolean color) {
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 10;
//			if (next > 88)
//				break;
//			bool finished = tryMoveCapture(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -10;
//			if (next < 0)
//				break;
//			bool finished = tryMoveCapture(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 1;
//			bool finished = tryMoveCapture(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -1;
//			bool finished = tryMoveCapture(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//	}
//
//	static void generateRookMoves(Position position, SortedSet moves, int from, Boolean color) {
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 10;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -10;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 1;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -1;
//			bool finished = tryMove(position, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//	}
//
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
//	static bool tryMove(Position position, SortedSet moves, int from, int next, Boolean color) {
//		if (invalidSquare(next))
//			return true;
//		int type = position.typeOn(next);
//		if (type == 0) {
//			moves.add(new Move(position, from, next));
//			return false;
//		}
//		if ((type < 0) && (color.equals(BLACK)))
//			return true;
//		if ((type > 0) && (color.equals(WHITE))) {
//			return true;
//		}
//
//		Move m = new Move(position, from, next, 0, type);
//		moves.add(m);
//		return true;
//	}
//
//	static bool tryMoveCapture(Position position, Set moves, int from, int next, Boolean color) {
//		if (invalidSquare(next))
//			return true;
//		int type = position.board[next];
//		if (type == 0)
//			return false;
//		if ((type < 0) && (color.equals(BLACK)))
//			return true;
//		if ((type > 0) && (color.equals(WHITE))) {
//			return true;
//		}
//
//		Move m = new Move(position, from, next, 0, type);
//		moves.add(m);
//		return true;
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
//	bool castleLongBlack;
//
//	bool castleLongWhite;
//
//	bool castleShortBlack;
//
//	bool castleShortWhite;
//
//	int enPassantSquare;
//
//	bool hasCastledBlack;
//
//	bool hasCastledWhite;
//
//	//Boolean isEndGame;
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
//		this.bishopCaptureCount = 0;
//		this.bishopNonCaptureCount = 0;
//		this.blackKing = -1;
//		this.blackPieces = new TreeSet();
//		this.captureMoves = null;
//		this.castleLongBlack = true;
//		this.castleLongWhite = true;
//		this.castleShortBlack = true;
//		this.castleShortWhite = true;
//		this.enPassantSquare = 0;
//		this.hasCastledBlack = false;
//		this.hasCastledWhite = false;
//		this.isGivingCheck = null;
//		this.isReceivingCheck = null;
//		this.isStartPosition = false;
//		this.moveNr = 0;
//		this.onMove = WHITE;
//		this.whiteKing = -1;
//		this.whitePieces = new TreeSet();
//		Info.nodes += 1L;
//		this.board = new int[89];
//		this.whitePieces.clear();
//		this.whiteKing = -1;
//		this.blackPieces.clear();
//		this.blackKing = -1;
//		clearBoard();
//	}
//
//	Position(Position& position) {
//		this.bishopCaptureCount = 0;
//		this.bishopNonCaptureCount = 0;
//		this.blackKing = -1;
//		this.blackPieces = new TreeSet();
//		this.captureMoves = null;
//		this.castleLongBlack = true;
//		this.castleLongWhite = true;
//		this.castleShortBlack = true;
//		this.castleShortWhite = true;
//		this.enPassantSquare = 0;
//		this.hasCastledBlack = false;
//		this.hasCastledWhite = false;
//		this.isGivingCheck = null;
//		this.isReceivingCheck = null;
//		this.isStartPosition = false;
//		this.moveNr = 0;
//		this.onMove = WHITE;
//		this.whiteKing = -1;
//		this.whitePieces = new TreeSet();
//		Info.nodes += 1L;
//		this.board = new int[89];
//		copyBoard(position.board, this.board);
//		this.whitePieces.addAll(position.whitePieces);
//		this.whiteKing = position.whiteKing;
//		this.blackPieces.addAll(position.blackPieces);
//		this.blackKing = position.blackKing;
//		this.isStartPosition = position.isStartPosition();
//		this.onMove = position.onMove();
//		this.castleLongBlack = position.getCastleLongBlack();
//		this.castleLongWhite = position.getCastleLongWhite();
//		this.castleShortBlack = position.getCastleShortBlack();
//		this.castleShortWhite = position.getCastleShortWhite();
//		this.enPassantSquare = position.enPassant();
//		this.hasCastledBlack = position.hasCastledBlack();
//		this.hasCastledWhite = position.hasCastledWhite();
//		this.isGivingCheck = null;
//		this.isReceivingCheck = null;
//		this.zobrist = position.zobrist;
//		this.pawnZobrist = position.pawnZobrist;
//		this.pzCache = position.pzCache;
//		this.isEndGame = position.isEndGame;
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
//		this.whiteKing = 15;
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
//		this.blackKing = 85;
//		addPiece(Piece.create(new Square("f8"), BLACK, 3), "f8");
//		addPiece(Piece.create(new Square("g8"), BLACK, 2), "g8");
//		addPiece(Piece.create(new Square("h8"), BLACK, 4), "h8");
//	}
//
//	void addToCheckHash(Integer integer) {
//	}
//
//	void adjustKingSquaresForKBNK() {
//		Boolean lightSquaredBishop = null;
//		for (Iterator itW = this.whitePieces.iterator(); itW.hasNext();) {
//			int s = ((Integer) itW.next()).intValue();
//			int piece = this.board[s];
//			if (piece == 3) {
//				if (s % 2 == 0) {
//					lightSquaredBishop = Boolean.TRUE;
//					break;
//				}
//				lightSquaredBishop = Boolean.FALSE;
//				break;
//			}
//		}
//
//		if (lightSquaredBishop == null) {
//			for (Iterator itB = this.blackPieces.iterator(); itB.hasNext();) {
//				int s = ((Integer) itB.next()).intValue();
//				int piece = this.board[s];
//				if (piece == -3) {
//					if (s % 2 == 0) {
//						lightSquaredBishop = Boolean.TRUE;
//						break;
//					}
//					lightSquaredBishop = Boolean.FALSE;
//					break;
//				}
//			}
//		}
//
//		if (!lightSquaredBishop.boolValue()) {
//			this.kingEndgameSquareValues = this.kingEndgameSquareValuesKBNKLight;
//		} else {
//			this.kingEndgameSquareValues = this.kingEndgameSquareValuesKBNKDark;
//		}
//	}
//
//	Move getBestMove() {
//		return this.bestMove;
//	}
//
//	int getBestValue() {
//		return this.bestValue;
//	}
//
//	void clearBoard() {
//		for (int i = 0; i < 89; i++) {
//			this.board[i] = 0;
//		}
//	}
//
//	void clearEnPassantCapture(Move move, int board[]) {
//		long zobi;
//		if (move.to > move.from) {
//			zobi = kleinerZobristEntfernen(move.to - 10);
//			clearSquare(move.to, -10, board);
//			this.blackPieces.remove(new Integer(move.to - 10));
//		} else {
//			zobi = kleinerZobristEntfernen(move.to + 10);
//			clearSquare(move.to, 10, board);
//			this.whitePieces.remove(new Integer(move.to + 10));
//		}
//		this.zobrist ^= zobi;
//	}
//
//	PieceCount countBlackPieces() {
//		int queensCount = 0;
//		int rookCount = 0;
//		int knightsCount = 0;
//		int bishopsCount = 0;
//		int pawnsCount = 0;
//		for (Iterator wpIt = this.blackPieces.iterator(); wpIt.hasNext();) {
//			int i = ((Integer) wpIt.next()).intValue();
//			int piece = this.board[i];
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
//		for (Iterator wpIt = this.whitePieces.iterator(); wpIt.hasNext();) {
//			int i = ((Integer) wpIt.next()).intValue();
//			int piece = this.board[i];
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
//		return this.enPassantSquare;
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
//			if (!this.board.equals(position.board))
//				return false;
//			if (this.isStartPosition != position.isStartPosition())
//				return false;
//			if (!this.onMove.equals(position.onMove()))
//				return false;
//			if (this.castleLongBlack != position.getCastleLongBlack())
//				return false;
//			if (this.castleLongWhite != position.getCastleLongWhite())
//				return false;
//			if (this.castleShortBlack != position.getCastleShortBlack())
//				return false;
//			if (this.castleShortWhite != position.getCastleShortWhite())
//				return false;
//			if (this.enPassantSquare != position.enPassant())
//				return false;
//			if (this.hasCastledBlack != position.hasCastledBlack())
//				return false;
//			if (this.hasCastledWhite != position.hasCastledWhite()) {
//				return false;
//			}
//
//			this.isGivingCheck = null;
//			this.isReceivingCheck = null;
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
//		Iterator whiteIt = this.whitePieces.iterator();
//		int whiteCValue = 0;
//		while (whiteIt.hasNext()) {
//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
//			int whitePiece = this.board[whiteSquare];
//			if (whitePiece == 1) {
//				whiteCValue += pieceValues[0];
//				int file = whiteSquare % 10;
//				whiteCValue += getPawnEndgameValue(whiteSquare, whitePiece, file);
//			}
//		}
//		Iterator blackIt = this.blackPieces.iterator();
//		int blackCValue = 0;
//		while (blackIt.hasNext()) {
//			int blackSquare = ((Integer) blackIt.next()).intValue();
//			int blackPiece = this.board[blackSquare];
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
//		Iterator whiteIt = this.whitePieces.iterator();
//		int whiteCValue = 0;
//		while (whiteIt.hasNext()) {
//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
//			int whitePiece = this.board[whiteSquare];
//			if (whitePiece == 1) {
//				whiteCValue += pieceValues[0];
//				int file = whiteSquare % 10;
//				whiteCValue += getPawnMidgameValue(whiteSquare, whitePiece, file);
//			}
//		}
//		Iterator blackIt = this.blackPieces.iterator();
//		int blackCValue = 0;
//		while (blackIt.hasNext()) {
//			int blackSquare = ((Integer) blackIt.next()).intValue();
//			int blackPiece = this.board[blackSquare];
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
//	void fillRank(int rank, String currentRank) {
//		int rankStart = 10 * (rank + 1);
//		int next = rankStart + 1;
//		for (int i = 0; i < currentRank.length(); i++) {
//			char currChar = currentRank.charAt(i);
//			if (Character.isDigit(currChar)) {
//				int digit = Character.getNumericValue(currChar);
//				for (int j = 0; j < digit; j++) {
//					this.board[next] = 0;
//					next++;
//					if (next > 88) {
//						break;
//					}
//				}
//			} else if (Character.isLetter(currChar)) {
//				switch (currChar) {
//				case 'k':
//					this.board[next] = -6;
//					this.blackPieces.add(new Integer(next));
//					this.blackKing = next;
//					break;
//
//				case 'q':
//					this.board[next] = -5;
//					this.blackPieces.add(new Integer(next));
//					break;
//
//				case 'r':
//					this.board[next] = -4;
//					this.blackPieces.add(new Integer(next));
//					break;
//
//				case 'b':
//					this.board[next] = -3;
//					this.blackPieces.add(new Integer(next));
//					break;
//
//				case 'n':
//					this.board[next] = -2;
//					this.blackPieces.add(new Integer(next));
//					break;
//
//				case 'p':
//					this.board[next] = -1;
//					this.blackPieces.add(new Integer(next));
//					break;
//
//				case 'K':
//					this.board[next] = 6;
//					this.whitePieces.add(new Integer(next));
//					this.whiteKing = next;
//					break;
//
//				case 'Q':
//					this.board[next] = 5;
//					this.whitePieces.add(new Integer(next));
//					break;
//
//				case 'R':
//					this.board[next] = 4;
//					this.whitePieces.add(new Integer(next));
//					break;
//
//				case 'B':
//					this.board[next] = 3;
//					this.whitePieces.add(new Integer(next));
//					break;
//
//				case 'N':
//					this.board[next] = 2;
//					this.whitePieces.add(new Integer(next));
//					break;
//
//				case 'P':
//					this.board[next] = 1;
//					this.whitePieces.add(new Integer(next));
//				}
//
//				next++;
//			}
//		}
//	}
//
//	int findKing(bool colorWhite) {
//		if (colorWhite) {
//			return this.whiteKing;
//		}
//		return this.blackKing;
//	}
//
//	void generateBishopCaptures(Set moves, int from, Boolean color) {
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 9;
//			if (next > 88)
//				break;
//			bool finished = tryMoveCapture(this, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -9;
//			if (next < 0)
//				break;
//			bool finished = tryMoveCapture(this, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * 11;
//			if (next > 88)
//				break;
//			bool finished = tryMoveCapture(this, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//		for (int i = 1; i < 8; i++) {
//			int next = from + i * -11;
//			if (next < 0)
//				break;
//			bool finished = tryMoveCapture(this, moves, from, next, color);
//			if (finished) {
//				break;
//			}
//		}
//	}
//
//	void generateBishopNonCaptures(Set moves, int from, Boolean color) {
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
//	SortedSet generateCaptureMoves() {
//		SortedSet moves = new TreeSet();
//		for (int i = 11; i < 89; i++) {
//			int p = this.board[i];
//			int type = Math.abs(p);
//			if ((type >= 1) && (type <= 7)) {
//				Boolean color = EdenBrain.convertColor(p);
//				if (color.equals(onMove())) {
//					SortedSet pieceMoves = generateCaptureMoves(i, p, color);
//					moves.addAll(pieceMoves);
//				}
//			}
//		}
//
//		return moves;
//	}
//
//	SortedSet generateCaptureMoves(int i, int p, Boolean color) {
//		SortedSet moves = new TreeSet();
//		switch (p) {
//		case -1:
//
//		case 1:
//			generatePawnCaptures(this, moves, i, color);
//			break;
//
//		case -2:
//
//		case 2:
//			generateKnightCaptures(this, moves, i, color);
//			break;
//
//		case -3:
//
//		case 3:
//			generateBishopCaptures(moves, i, color);
//			break;
//
//		case -4:
//
//		case 4:
//			generateRookCaptures(this, moves, i, color);
//			break;
//
//		case -5:
//
//		case 5:
//			generateQueenCaptures(this, moves, i, color);
//			break;
//
//		case -6:
//
//		case 6:
//			generateKingCaptures(this, moves, i, color);
//		}
//
//		return moves;
//	}
//
//	void generateKingNonCapturesNoCastling(Set moves, int from, Boolean color) {
//		int[] kingMoves = { 9, 10, 11, -1, 1, -9, -10, -11 };
//
//		for (int i = 0; i < kingMoves.length; i++) {
//			int next = from + kingMoves[i];
//			if (!invalidSquare(next)) {
//				int capturedPiece = this.board[next];
//				if (capturedPiece == 0) {
//					moves.add(new Move(this, from, next, 0, 0));
//				}
//			}
//		}
//	}
//
//	void generateKnightNonCaptures(Set moves, int from, Boolean color) {
//		int[] knightMoves = { 19, 21, 8, 12, -19, -21, -8, -12 };
//
//		for (int i = 0; i < knightMoves.length; i++) {
//			int next = from + knightMoves[i];
//			if (!invalidSquare(next)) {
//				int capturedPiece = this.board[next];
//				if (capturedPiece == 0) {
//					moves.add(new Move(this, from, next));
//				}
//			}
//		}
//	}
//
//	SortedSet generateLegalMoves() {
//		if (this.legalMoves != null) {
//			return this.legalMoves;
//		}
//
//		SortedSet moves = generateMoves();
//		removeIllegalMoves(moves);
//		this.legalMoves = moves;
//		return moves;
//	}
//
#define WHITE true
#define BLACK false
bool onMove;
	
//	int getBishopValue(int i, int plusminus) {
//		int retValue = bishopSquareValues[(i - 10)];
//		if (plusminus > 0) {
//			if (i == 16) {
//				if (this.board[25] > 0)
//					retValue -= 3;
//				if (this.board[27] > 0)
//					retValue--;
//			}
//			if ((i == 34) && (this.board[24] == 1)) {
//				retValue -= 25;
//			}
//		} else {
//			if (i == 86) {
//				if (this.board[75] < 0)
//					retValue -= 3;
//				if (this.board[77] < 0)
//					retValue--;
//			}
//			if ((i == 64) && (this.board[74] == -1))
//				retValue -= 25;
//		}
//		return retValue;
//	}
//
//	bool getCastleLongBlack() {
//		return this.castleLongBlack;
//	}
//
//	bool getCastleLongWhite() {
//		return this.castleLongWhite;
//	}
//
//	bool getCastleShortBlack() {
//		return this.castleShortBlack;
//	}
//
//	bool getCastleShortWhite() {
//		return this.castleShortWhite;
//	}
//
//	int getEndgameValue() {
//		if ((this.wpc.isKBNK()) || (this.bpc.isKBNK()))
//			adjustKingSquaresForKBNK();
//		int whiteValue = 0;
//		int blackValue = 0;
//		bool possibleBishopPairWhite = false;
//		bool possibleBishopPairBlack = false;
//		int pawnStructureValue = evaluatePawnStructureEndgame();
//		Iterator whiteIt = this.whitePieces.iterator();
//		int whiteCValue = 0;
//		int whiteMValue = 0;
//		while (whiteIt.hasNext()) {
//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
//			int whitePiece = this.board[whiteSquare];
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
//		Iterator blackIt = this.blackPieces.iterator();
//		int blackCValue = 0;
//		int blackMValue = 0;
//		while (blackIt.hasNext()) {
//			int blackSquare = ((Integer) blackIt.next()).intValue();
//			int blackPiece = this.board[blackSquare];
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
//	int getHorizontalKingTropism(int plusminus, int square) {
//		int kingPosition;
//
//		if (plusminus > 0) {
//			kingPosition = this.blackKing;
//		} else
//			kingPosition = this.whiteKing;
//		int myRank = square % 10;
//		int yourRank = kingPosition % 10;
//		return Math.abs(myRank - yourRank);
//	}
//
//	int getKingEndgameValue(int square, int piece) {
//		return this.kingEndgameSquareValues[(square - 10)];
//	}
//
//	int getKingMidgameValue(int square, int piece, int file) {
//		int retValue = 0;
//		int openFiles = 0;
//		int halfOpenFiles = 0;
//		int rank = square / 10;
//		if (isOnOpenFile(square, file)) {
//			openFiles++;
//		} else if (isOnOpenOrHalfOpenFile(piece, file, rank))
//			halfOpenFiles++;
//		if (isOnOpenFile(square, file - 1)) {
//			openFiles++;
//		} else if (isOnOpenOrHalfOpenFile(piece, file - 1, rank))
//			halfOpenFiles++;
//		if (isOnOpenFile(square, file + 1)) {
//			openFiles++;
//		} else if (isOnOpenOrHalfOpenFile(piece, file + 1, rank))
//			halfOpenFiles++;
//		retValue = (int) (retValue - 30.0 * Math.pow(2.0, openFiles));
//		retValue = (int) (retValue - 5.0 * Math.pow(2.0, halfOpenFiles));
//		if (piece == 6) {
//			if ((square > 13) && (square < 17))
//				retValue -= 35;
//			if (square > 20) {
//				retValue -= 55;
//			} else {
//				if ((square == 17) || (square == 18)) {
//					if (this.board[26] != 1)
//						retValue -= 10;
//					if ((this.board[27] != 1) && (this.board[27] != 3)) {
//						retValue -= 10;
//						if (this.board[37] != 1)
//							retValue -= 10;
//					}
//					if (this.board[28] != 1) {
//						retValue -= 6;
//						if (this.board[38] != 1) {
//							retValue -= 11;
//						}
//					}
//				} else if ((square == 12) || (square == 11) || (square == 13)) {
//					if (this.board[23] != 1)
//						retValue -= 10;
//					if ((this.board[22] != 1) && (this.board[22] != 3)) {
//						retValue -= 10;
//						if (this.board[32] != 1)
//							retValue -= 10;
//					}
//					if (this.board[21] != 1) {
//						retValue -= 10;
//						if (this.board[31] != 1)
//							retValue -= 10;
//					}
//				}
//				if (square == 13)
//					retValue -= 37;
//			}
//		}
//		if (piece == -6) {
//			if ((square > 83) && (square < 87))
//				retValue -= 35;
//			if (square < 80) {
//				retValue -= 55;
//			} else if ((square == 87) || (square == 88)) {
//				if (this.board[76] != -1)
//					retValue -= 10;
//				if ((this.board[77] != -1) && (this.board[77] != -3)) {
//					retValue -= 10;
//					if (this.board[67] != -1)
//						retValue -= 10;
//				}
//				if (this.board[78] != -1) {
//					retValue -= 6;
//					if (this.board[68] != -1) {
//						retValue -= 11;
//					}
//				}
//			} else if ((square == 82) || (square == 81) || (square == 83)) {
//				if (this.board[73] != -1)
//					retValue -= 10;
//				if ((this.board[72] != -1) || (this.board[72] != -3)) {
//					retValue -= 10;
//					if (this.board[62] != -1)
//						retValue -= 10;
//				}
//				if (this.board[71] != -1) {
//					retValue -= 10;
//					if (this.board[61] != -1)
//						retValue -= 10;
//				}
//				if (square == 83)
//					retValue -= 37;
//			}
//		}
//		return retValue;
//	}
//
//	int getKnightValue(int piece, int square) {
//		int retVal = getKnightPcSqValue(square);
//		int x = getHorizontalKingTropism(piece, square);
//		int y = getVerticalKingTropism(piece, square);
//		int manhattanTropism = x + y;
//		retVal -= manhattanTropism / 3;
//		return retVal;
//	}
//
//	int getMidgameValue() {
//		int whiteValue = 0;
//		int blackValue = 0;
//		bool possibleBishopPairWhite = false;
//		bool possibleBishopPairBlack = false;
//		int pawnStructureValue = evaluatePawnStructureMidgame();
//		Iterator whiteIt = this.whitePieces.iterator();
//		int whiteCValue = 0;
//		int whiteMValue = 0;
//		while (whiteIt.hasNext()) {
//			int whiteSquare = ((Integer) whiteIt.next()).intValue();
//			int whitePiece = this.board[whiteSquare];
//			if (whitePiece != 1) {
//				whiteMValue += getPieceMaterialValue(whitePiece);
//				if (whitePiece == 3) {
//					if (possibleBishopPairWhite)
//						whiteCValue += 50;
//					possibleBishopPairWhite = true;
//				}
//				int file = whiteSquare % 10;
//				whiteCValue += getPieceMidgameValue(whiteSquare, whitePiece, file);
//			}
//		}
//		Iterator blackIt = this.blackPieces.iterator();
//		int blackCValue = 0;
//		int blackMValue = 0;
//		while (blackIt.hasNext()) {
//			int blackSquare = ((Integer) blackIt.next()).intValue();
//			int blackPiece = this.board[blackSquare];
//			if (blackPiece != -1) {
//				blackMValue += getPieceMaterialValue(blackPiece);
//				if (blackPiece == -3) {
//					if (possibleBishopPairBlack)
//						blackCValue += 50;
//					possibleBishopPairBlack = true;
//				}
//				int file = blackSquare % 10;
//				blackCValue += getPieceMidgameValue(blackSquare, blackPiece, file);
//			}
//		}
//		blackValue += blackCValue;
//		whiteValue += whiteCValue;
//		if (!this.hasCastledBlack)
//			blackValue -= 61;
//		if (!this.hasCastledWhite)
//			whiteValue -= 61;
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
//	int getPawnEndgameValue(int i, int plusminus, int file) {
//		int retValue = 0;
//		if (plusminus > 0) {
//			retValue = whitePawnSquareValues[(79 - i)] / 2;
//		} else
//			retValue = blackPawnSquareValues[(i - 20)] / 2;
//		int rank = i / 10;
//		if (isPassed(i, plusminus, file, rank))
//			if (plusminus > 0) {
//				retValue = (int) (retValue + 1.5 * this.passedPawnProgression[(rank - 2)]);
//			} else
//				retValue = (int) (retValue + 1.5 * this.passedPawnProgression[(7 - rank)]);
//		if (isIsolated(i, file))
//			retValue -= 15;
//		if (isDoubled(i, file))
//			retValue -= 18;
//		return retValue;
//	}
//
//	int getPawnMidgameValue(int i, int plusminus, int file) {
//		int retValue;
//
//		if (plusminus > 0) {
//			retValue = whitePawnSquareValues[(79 - i)];
//		} else
//			retValue = blackPawnSquareValues[(i - 20)];
//		int rank = i / 10;
//		if (isPassed(i, plusminus, file, rank)) {
//			int passedValue = 0;
//			if (plusminus > 0) {
//				passedValue += this.passedPawnProgression[(rank - 2)];
//			} else
//				passedValue += this.passedPawnProgression[(7 - rank)];
//			retValue += passedValue;
//		}
//		if (isIsolated(i, file))
//			retValue -= 12;
//		if (isDoubled(i, file))
//			retValue -= 16;
//		return retValue;
//	}
//
//	Long getPawnZobrist() {
//		if (this.pawnZobrist != null)
//			return this.pawnZobrist;
//		long grosserZobrist = 0L;
//		for (Iterator wIt = this.whitePieces.iterator(); wIt.hasNext();) {
//			int square = ((Integer) wIt.next()).intValue();
//			int figur = this.board[square];
//			if (figur == 1) {
//				long kleinerZobrist = kleinerZobristSetzen(figur, square);
//				grosserZobrist ^= kleinerZobrist;
//			}
//		}
//
//		for (Iterator bIt = this.blackPieces.iterator(); bIt.hasNext();) {
//			int square = ((Integer) bIt.next()).intValue();
//			int figur = this.board[square];
//			if (figur == -1) {
//				long kleinerZobrist = kleinerZobristSetzen(figur, square);
//				grosserZobrist ^= kleinerZobrist;
//			}
//		}
//
//		Long pz = new Long(grosserZobrist);
//		this.pawnZobrist = pz;
//		return pz;
//	}
//
//	int getPieceEndgameValue(int square, int piece, int file) {
//		int retValue = 0;
//		switch (piece) {
//		case -6:
//
//		case 6:
//			retValue = getKingEndgameValue(square, piece);
//			break;
//
//		case -5:
//
//		case 5:
//			retValue = -25;
//			break;
//
//		case -4:
//
//		case 4:
//			retValue = 25;
//			break;
//
//		case -3:
//
//		case 3:
//			retValue = 3;
//			break;
//
//		case -2:
//
//		case 2:
//			retValue = -3;
//			break;
//
//		case -1:
//
//		case 1:
//			retValue = getPawnEndgameValue(square, piece, file);
//			break;
//
//		case 0:
//
//		default:
//			retValue = 0;
//		}
//
//		return retValue;
//	}
//
//	int getPieceMaterialValue(int piece) {
//		if (piece == 0) {
//			System.out.println("moveStack: " + EdenBrain.moveStack);
//			throw new IllegalStateException("piece==0");
//		}
//
//		int retVal = pieceValues[(Math.abs(piece) - 1)];
//		return retVal;
//	}
//
//	int getPieceMidgameValue(int square, int piece, int file) {
//		int retValue = 0;
//		switch (piece) {
//		case -6:
//
//		case 6:
//			retValue = getKingMidgameValue(square, piece, file);
//			break;
//
//		case -5:
//
//		case 5:
//			retValue = getQueenValue(piece, square, file);
//			break;
//
//		case -4:
//
//		case 4:
//			retValue = getRookValue(piece, square, file);
//			break;
//
//		case -3:
//
//		case 3:
//			retValue = getBishopValue(square, piece);
//			break;
//
//		case -2:
//
//		case 2:
//			retValue = getKnightValue(piece, square);
//			break;
//
//		case -1:
//
//		case 1:
//			retValue = getPawnMidgameValue(square, piece, file);
//			break;
//
//		case 0:
//
//		default:
//			retValue = 0;
//		}
//
//		return retValue;
//	}
//
//	int getQueenValue(int plusminus, int square, int file) {
//		int retValue = getRookValue(plusminus, square, file) / 4;
//		return retValue;
//	}
//
//	int getRookValue(int plusminus, int square, int file) {
//		int retVal = isOnOpenFile(square, file) ? 12 : 0;
//		int x = getHorizontalKingTropism(plusminus, square);
//		int y = getVerticalKingTropism(plusminus, square);
//		int minTropism = Math.min(x, y);
//		retVal -= minTropism / 4;
//		return retVal;
//	}
//
//	int getValue() {
//		this.wpc = countWhitePieces();
//		this.bpc = countBlackPieces();
//		if (isInsufficientMaterial(this.wpc, this.bpc))
//			return 0;
//		if (isInsufficientMaterial(this.bpc, this.wpc))
//			return 0;
//		if (isEndgame()) {
//			return getEndgameValue();
//		}
//		return getMidgameValue();
//	}
//
//	int getVerticalKingTropism(int plusminus, int square) {
//		int kingPosition;
//
//		if (plusminus > 0) {
//			kingPosition = this.blackKing;
//		} else
//			kingPosition = this.whiteKing;
//		int myRank = square / 10;
//		int yourRank = kingPosition / 10;
//		return Math.abs(myRank - yourRank);
//	}
//
//	long getZobrist() {
//		if (this.zobrist != 0L)
//			return this.zobrist;
//		long grosserZobrist = 0L;
//		for (int i = 11; i < 89; i++) {
//			int figur = this.board[i];
//			if (figur != 0) {
//				int spalte = i % 10;
//				if ((spalte != 0) && (spalte != 9)) {
//					long kleinerZobrist = kleinerZobristSetzen(figur, i);
//					grosserZobrist ^= kleinerZobrist;
//				}
//			}
//		}
//
//		if ((this.onMove != null) && (this.onMove.equals(BLACK)))
//			grosserZobrist ^= EdenBrain.onMoveZobrist;
//		if (this.enPassantSquare != 0)
//			grosserZobrist ^= EdenBrain.enPassantZobrist;
//		this.zobrist = grosserZobrist;
//		return grosserZobrist;
//	}
//
//
//	int hashCode() {
//		int base1 = this.board.hashCode();
//		int base2 = 0;
//		if (this.castleLongBlack)
//			base2++;
//		if (this.castleLongWhite)
//			base2 += 2;
//		if (this.castleShortBlack)
//			base2 += 4;
//		if (this.castleShortWhite)
//			base2 += 8;
//		if (this.hasCastledWhite)
//			base2 += 16;
//		if (this.hasCastledBlack)
//			base2 += 32;
//		if (this.onMove.boolValue())
//			base2 += 64;
//		int retVal = base1 * base2;
//		return retVal;
//	}
//
//	bool hasNextCaptureMove() {
//		updateCaptureMove();
//		return this.nextCaptureMove != null;
//	}
//
//	bool hasNextNonCaptureMove() {
//		updateNonCaptureMove();
//		return this.nextNonCaptureMove != null;
//	}
//
//	bool hasNoEnemyPawns(int piece, int file) {
//		if ((file < 1) || (file > 8))
//			return true;
//		int plusminus = Math.abs(piece) / piece;
//		int conversion = 80 + file;
//		int start = file + 10;
//		for (int i = start; i < conversion; i += 10) {
//			if (this.board[i] == -plusminus)
//				return false;
//		}
//		return true;
//	}
//
//	bool hasNoEnemyPawnsAhead(int piece, int file, int rank) {
//		if ((file < 1) || (file > 8))
//			return true;
//		int plusminus = Math.abs(piece) / piece;
//		int direction = plusminus * 10;
//		int conversion = plusminus <= 0 ? 10 + file : 80 + file;
//		int start = rank * 10 + file + direction;
//		for (int i = start; i != conversion; i += direction) {
//			if (this.board[i] == -plusminus)
//				return false;
//		}
//		return true;
//	}
//
//	bool hasNoPawns(int square, int file) {
//		if ((file < 1) || (file > 8))
//			return true;
//		for (int i = 20 + file; i < 79; i += 10) {
//			if (this.board[i] == this.board[square])
//				return false;
//		}
//		return true;
//	}
//
//	void initCaptureMoveGenerator() {
//		this.nextCaptureMove = null;
//		this.persistentSquareForCapture = 11;
//		initializeCaptureMoveCounters();
//	}
//
//	void initializeCaptureMoveCounters() {
//		this.lastPawnCapture = 0;
//		this.bishopCaptureCount = 0;
//		this.knightCaptures = null;
//		this.bishopCaptures = null;
//		this.rookCaptures = null;
//		this.queenCaptures = null;
//		this.kingCaptures = null;
//	}
//
//	void initializeNonCaptureMoveCounters() {
//		this.lastPawnNonCapture = 0;
//		this.bishopNonCaptureCount = 0;
//		this.knightNonCaptures = null;
//		this.bishopNonCaptures = null;
//		this.rookNonCaptures = null;
//		this.queenNonCaptures = null;
//		this.kingNonCaptures = null;
//	}
//
//	void initNonCaptureMoveGenerator() {
//		this.nextNonCaptureMove = null;
//		this.persistentSquareForNonCapture = 11;
//		initializeNonCaptureMoveCounters();
//	}
//
//	bool isAttacked(int i, Boolean color) {
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
//	bool isDoubled(int square, int file) {
//		for (int i = 20 + file; i < 79; i += 10) {
//			if ((i != square) && (this.board[i] == this.board[square]))
//				return true;
//		}
//		return false;
//	}
//
//	bool isEndgame() {
//		if ((this.isEndGame != null) && (this.isEndGame.equals(Boolean.TRUE)))
//			return true;
//		int lightPiecesCount = this.wpc.knightsCount + this.wpc.bishopsCount;
//		int heavyPiecesCount = this.wpc.rookCount + this.wpc.queensCount;
//		if (this.wpc.queensCount >= 1) {
//			if (this.wpc.rookCount > 1)
//				return false;
//			if ((this.wpc.rookCount == 1) && (lightPiecesCount > 0))
//				return false;
//			return lightPiecesCount <= 2;
//		}
//		if ((this.wpc.rookCount > 1) && (lightPiecesCount > 2))
//			return false;
//		if ((this.wpc.rookCount == 1) && (lightPiecesCount > 3)) {
//			return false;
//		}
//
//		this.isEndGame = Boolean.TRUE;
//		return true;
//	}
//
//	//bool isGivingCheck() {
//	//	if (this.isGivingCheck != null)
//	//		return this.isGivingCheck.boolValue();
//	//	Boolean othercolor = Boolean.valueOf(!onMove().boolValue());
//	//	int currentPiece = findKing(othercolor.boolValue());
//	//	if (currentPiece == -1)
//	//		throw new IllegalStateException("no king found");
//	//	int i = currentPiece;
//	//	SortedSet moves = new TreeSet();
//	//	generateBishopCaptures(moves, i, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if ((piece == 3) || (piece == 5)) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(othercolor)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateRookCaptures(this, moves, i, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if ((piece == 4) || (piece == 5)) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(othercolor)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateKingCaptures(this, moves, i, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if (piece == 6) {
//	//			this.isGivingCheck = new Boolean(true);
//	//			return true;
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateKnightCaptures(this, moves, i, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if (piece == 2) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(othercolor)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generatePawnCaptures(this, moves, i, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if ((piece == 1) && (Math.abs(this.board[move.to]) == 1)) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(othercolor)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	this.isGivingCheck = new Boolean(false);
//	//	return false;
//	//}
//
//	bool isGivingCheckForCastling(int square) {
//		if (this.isGivingCheck != null)
//			return this.isGivingCheck.boolValue();
//		int i = square;
//		Boolean c1 = EdenBrain.convertColor(this.board[i]);
//		SortedSet moves = new TreeSet();
//		generateBishopCaptures(moves, i, c1);
//		for (Iterator it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			int piece = Math.abs(this.board[move.to]);
//			if ((piece == 3) || (piece == 5)) {
//				int t = this.board[move.to];
//				Boolean c = EdenBrain.convertColor(t);
//				if (!c.equals(c1)) {
//					this.isGivingCheck = new Boolean(true);
//					return true;
//				}
//			}
//		}
//	}
//	//	moves.clear();
//	//	generateRookCaptures(this, moves, i, c1);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if ((piece == 4) || (piece == 5)) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(c1)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateKingCaptures(this, moves, i, c1);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if (piece == 6) {
//	//			this.isGivingCheck = new Boolean(true);
//	//			return true;
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateKnightCaptures(this, moves, i, c1);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if (piece == 2) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(c1)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generatePawnCaptures(this, moves, i, Boolean.valueOf(!onMove().boolValue()));
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if ((piece == 1) && (Math.abs(this.board[move.to]) == 1)) {
//	//			int t = this.board[move.to];
//	//			Boolean c = EdenBrain.convertColor(t);
//	//			if (!c.equals(c1)) {
//	//				this.isGivingCheck = new Boolean(true);
//	//				return true;
//	//			}
//	//		}
//	//	}
//
//	//	this.isGivingCheck = new Boolean(false);
//	//	return false;
//	//}
//
//	//bool isGivingCheckNonKingMoving(int moveFrom) {
//	//	Integer zobrist = null;
//	//	if (this.isGivingCheck != null)
//	//		return this.isGivingCheck.boolValue();
//	//	Boolean othercolor = Boolean.valueOf(!onMove().boolValue());
//	//	int kingPosition = findKing(othercolor.boolValue());
//	//	if (kingPosition == -1)
//	//		throw new IllegalStateException("no king found");
//	//	SortedSet moves = new TreeSet();
//	//	if (onDiagonal(moveFrom, kingPosition)) {
//	//		moves.clear();
//	//		generateBishopCaptures(moves, kingPosition, othercolor);
//	//		for (Iterator it = moves.iterator(); it.hasNext();) {
//	//			Move move = (Move) it.next();
//	//			int piece = Math.abs(this.board[move.to]);
//	//			if ((piece == 3) || (piece == 5)) {
//	//				int t = this.board[move.to];
//	//				Boolean c = EdenBrain.convertColor(t);
//	//				if (!c.equals(othercolor)) {
//	//					this.isGivingCheck = new Boolean(true);
//	//					addToCheckHash(zobrist);
//	//					return true;
//	//				}
//	//			}
//	//		}
//
//	//		moves.clear();
//	//		generatePawnCaptures(this, moves, kingPosition, othercolor);
//	//		for (Iterator it = moves.iterator(); it.hasNext();) {
//	//			Move move = (Move) it.next();
//	//			int piece = Math.abs(this.board[move.to]);
//	//			if (piece == 1) {
//	//				int t = this.board[move.to];
//	//				Boolean c = EdenBrain.convertColor(t);
//	//				if (c.equals(othercolor)) {
//	//					this.isGivingCheck = new Boolean(true);
//	//					addToCheckHash(zobrist);
//	//					return true;
//	//				}
//	//			}
//	//		}
//	//	}
//
//	//	if ((onRank(moveFrom, kingPosition)) || (onFile(moveFrom, kingPosition))) {
//	//		moves.clear();
//	//		generateRookCaptures(this, moves, kingPosition, othercolor);
//	//		for (Iterator it = moves.iterator(); it.hasNext();) {
//	//			Move move = (Move) it.next();
//	//			int piece = Math.abs(this.board[move.to]);
//	//			if ((piece == 4) || (piece == 5)) {
//	//				int t = this.board[move.to];
//	//				Boolean c = EdenBrain.convertColor(t);
//	//				if (!c.equals(othercolor)) {
//	//					this.isGivingCheck = new Boolean(true);
//	//					addToCheckHash(zobrist);
//	//					return true;
//	//				}
//	//			}
//	//		}
//	//	}
//
//	//	moves.clear();
//	//	generateKingCaptures(this, moves, kingPosition, othercolor);
//	//	for (Iterator it = moves.iterator(); it.hasNext();) {
//	//		Move move = (Move) it.next();
//	//		int piece = Math.abs(this.board[move.to]);
//	//		if (piece == 6) {
//	//			this.isGivingCheck = new Boolean(true);
//	//			addToCheckHash(zobrist);
//	//			return true;
//	//		}
//	//	}
//
//	//	this.isGivingCheck = new Boolean(false);
//	//	addToCheckHash(zobrist);
//	//	return false;
//	//}
//
//	//bool isInsufficientMaterial(PieceCount pc) {
//	//	return (pc.loneKing()) || (pc.oneLight()) || (pc.isNN());
//	//}
//
//	//bool isInsufficientMaterial(PieceCount we, PieceCount other) {
//	//	return (isInsufficientMaterial(we)) && (isInsufficientMaterial(other));
//	//}
//
//	//bool isIsolated(int square, int file) {
//	//	return (hasNoPawns(square, file - 1)) && (hasNoPawns(square, file + 1));
//	//}
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
//	bool isOnOpenFile(int square, int file) {
//		if ((file < 1) || (file > 8))
//			return false;
//		for (int i = 20 + file; i < 80; i += 10) {
//			if ((this.board[i] == 1) || (this.board[i] == -1))
//				return false;
//		}
//		return true;
//	}
//
//	bool isOnOpenOrHalfOpenFile(int plusminus, int file, int rank) {
//		if ((file < 1) || (file > 8))
//			return false;
//		if (hasNoEnemyPawns(plusminus, file))
//			return true;
//		return hasNoEnemyPawns(-plusminus, file);
//	}
//
//	bool isPassed(int square, int plusminus, int file, int rank) {
//		if (!hasNoEnemyPawnsAhead(plusminus, file - 1, rank))
//			return false;
//		if (!hasNoEnemyPawnsAhead(plusminus, file + 1, rank))
//			return false;
//		return hasNoEnemyPawnsAhead(plusminus, file, rank);
//	}
//
//	bool isReceivingCheck() {
//		if (this.isReceivingCheck != null)
//			return this.isReceivingCheck.boolValue();
//		Boolean kingColor = onMove();
//		int kingPosition = findKing(kingColor.boolValue());
//		if (kingPosition == -1)
//			throw new IllegalStateException("no king found");
//		int i = kingPosition;
//		SortedSet moves = new TreeSet();
//		Iterator it = moves.iterator();
//		generateRookCaptures(this, moves, i, kingColor);
//		for (it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			if ((pieceOn(move.to).getType() == 4) || (pieceOn(move.to).getType() == 5)) {
//				this.isReceivingCheck = new Boolean(true);
//				return true;
//			}
//		}
//
//		moves.clear();
//		generatePawnCaptures(this, moves, i, kingColor);
//		for (it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			if (pieceOn(move.to).getType() == 1) {
//				this.isReceivingCheck = new Boolean(true);
//				return true;
//			}
//		}
//
//		moves.clear();
//		generateKnightCaptures(this, moves, i, kingColor);
//		for (it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			Piece p = pieceOn(move.to);
//			if ((p != null) && (p.getType() == 2)) {
//				this.isReceivingCheck = new Boolean(true);
//				return true;
//			}
//		}
//
//		moves.clear();
//		generateBishopCaptures(moves, i, kingColor);
//		for (it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			if ((pieceOn(move.to).getType() == 3) || (pieceOn(move.to).getType() == 5)) {
//				this.isReceivingCheck = new Boolean(true);
//				return true;
//			}
//		}
//
//		moves.clear();
//		generateKingMovesNoCastling(this, moves, i, kingColor);
//		for (it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			if (pieceOn(move.to).getType() == 6) {
//				this.isReceivingCheck = new Boolean(true);
//				return true;
//			}
//		}
//
//		this.isReceivingCheck = new Boolean(false);
//		return false;
//	}
//
//	bool isStartPosition() {
//		return this.isStartPosition;
//	}
//
//	long kleinerZobristEntfernen(int i) {
//		int figur = this.board[i];
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
//	void makeMove(int from, int to, int promotedTo) {
//		Move move = new Move(this, from, to, promotedTo);
//		bool isLegal = isLegal(from, to, promotedTo);
//		if (isLegal) {
//			try {
//				makeMove(move);
//			} catch (ThreeRepetitionsAB e) {
//				e.printStackTrace();
//			}
//		} else {
//			System.out.println("Illegal move:" + move);
//		}
//	}
//
//	void makeMove(Move move) {
//		long z = getZobrist();
//		this.zobrist = updateZobristForMove(move, z);
//		long pz = getPawnZobrist().longValue();
//		long incrementalZobrist = updatePawnZobristForMove(move, pz);
//		this.pawnZobrist = new Long(incrementalZobrist);
//		bool updateDrawCount = false;
//		if ((move.capturedPiece != 0) || (Math.abs(EdenBrain.position.board[move.from]) == 1))
//			updateDrawCount = true;
//		this.isGivingCheck = null;
//		this.legalMoves = null;
//		setStartPosition(false);
//		int movingPiece = moveRaw(move);
//		int movingPieceType = Math.abs(movingPiece);
//		if ((movingPieceType == 1) && (move.to == enPassant()))
//			clearEnPassantCapture(move, this.board);
//		if (this.enPassantSquare != 0) {
//			this.enPassantSquare = 0;
//			updateZobristEnPassant();
//		}
//		if ((movingPieceType == 1) && (Math.abs(move.to - move.from) == 20)) {
//			this.enPassantSquare = ((move.from + move.to) / 2);
//			updateZobristEnPassant();
//		}
//		if ((movingPieceType == 6) && (Math.abs(move.from - move.to) == 2)) {
//			int rookTo;
//			int rookFrom;
//			if (move.to == 17) {
//				rookFrom = 18;
//				rookTo = 16;
//			} else {
//				if (move.to == 87) {
//					rookFrom = 88;
//					rookTo = 86;
//				} else {
//					if (move.to == 13) {
//						rookFrom = 11;
//						rookTo = 14;
//					} else {
//						if (move.to == 83) {
//							rookFrom = 81;
//							rookTo = 84;
//						} else {
//							rookFrom = -1;
//							rookTo = -1;
//							System.out.println("move.from: " + move.from);
//							throw new RuntimeException("move.to.getIndex: " + move.to + " which is impossible!");
//						}
//					}
//				}
//			}
//			Move rookJump = new Move(this, rookFrom, rookTo);
//			moveRaw(rookJump);
//			if (movingPiece > 0) {
//				this.hasCastledWhite = true;
//			} else
//				this.hasCastledBlack = true;
//		}
//		if (movingPieceType == 6) {
//			if (this.onMove.equals(WHITE)) {
//				this.castleShortWhite = false;
//				this.castleLongWhite = false;
//			} else {
//				this.castleShortBlack = false;
//				this.castleLongBlack = false;
//			}
//		} else if (movingPieceType == 4)
//			if (this.onMove.equals(WHITE)) {
//				if (move.from == 18) {
//					this.castleShortWhite = false;
//				} else if (move.from == 11) {
//					this.castleLongWhite = false;
//				}
//			} else if (move.from == 88) {
//				this.castleShortBlack = false;
//			} else if (move.from == 81)
//				this.castleLongBlack = false;
//		int p = this.board[11];
//		if (p != 4)
//			this.castleLongWhite = false;
//		p = this.board[18];
//		if (p != 4)
//			this.castleShortWhite = false;
//		p = this.board[81];
//		if (p != -4)
//			this.castleLongBlack = false;
//		p = this.board[88];
//		if (p != -4)
//			this.castleShortBlack = false;
//		this.onMove = Boolean.valueOf(!this.onMove.boolValue());
//		if (!EdenBrain.withinAlphabeta) {
//			if (updateDrawCount) {
//				EdenBrain.threeDrawsTable.clear();
//			} else {
//				long myZobrist = getZobrist();
//				Long zobi = new Long(myZobrist);
//				if (EdenBrain.threeDrawsTable.containsKey(zobi)) {
//					Integer count = (Integer) EdenBrain.threeDrawsTable.get(zobi);
//					EdenBrain.threeDrawsTable.remove(zobi);
//					if (count.intValue() >= 2)
//						throw new IllegalStateException("three-fold repetition!");
//					count = new Integer(count.intValue() + 1);
//					EdenBrain.threeDrawsTable.put(zobi, count);
//				} else {
//					Integer count = new Integer(1);
//					EdenBrain.threeDrawsTable.put(zobi, count);
//				}
//			}
//		} else if (updateDrawCount) {
//			EdenBrain.alphaBetaDraws.clear();
//		} else {
//			long myZobrist = getZobrist();
//			Long zobi = new Long(myZobrist);
//			int total = 0;
//			if (EdenBrain.alphaBetaDraws.containsKey(zobi)) {
//				total += ((Integer) EdenBrain.alphaBetaDraws.get(zobi)).intValue();
//
//				if (EdenBrain.threeDrawsTable.containsKey(zobi)) {
//					total += ((Integer) EdenBrain.threeDrawsTable.get(zobi)).intValue();
//				} else {
//					Integer count = new Integer(1);
//					EdenBrain.alphaBetaDraws.put(zobi, count);
//				}
//				EdenBrain.alphaBetaDraws.remove(zobi);
//				if (total >= 2)
//					throw new ThreeRepetitionsAB("three-fold repetition!");
//				Integer count = new Integer(total + 1);
//				EdenBrain.alphaBetaDraws.put(zobi, count);
//			}
//		}
//	}
//
//	void makeMove(String moveString)  {
//		Move m = Move.create(this, moveString);
//		makeMove(m.from, m.to, m.capturedPiece);
//		this.isGivingCheck = null;
//		this.isReceivingCheck = null;
//	}
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
//	void makeTestMove(Move move) {
//		this.isGivingCheck = null;
//		this.legalMoves = null;
//		setStartPosition(false);
//		int movingPiece = moveRaw(move);
//		int movingPieceType = Math.abs(movingPiece);
//		if ((movingPieceType == 1) && (move.to == enPassant()))
//			testClearEnPassantCapture(move, this.board);
//		if ((movingPieceType == 1) && (Math.abs(move.to - move.from) == 20)) {
//			this.enPassantSquare = ((move.from + move.to) / 2);
//		} else
//			this.enPassantSquare = 0;
//		if ((movingPieceType == 6) && (Math.abs(move.from - move.to) == 2)) {
//			int rookTo;
//			int rookFrom;
//			if (move.to == 17) {
//				rookFrom = 18;
//				rookTo = 16;
//			} else {
//				if (move.to == 87) {
//					rookFrom = 88;
//					rookTo = 86;
//				} else {
//					if (move.to == 13) {
//						rookFrom = 11;
//						rookTo = 14;
//					} else {
//						if (move.to == 83) {
//							rookFrom = 81;
//							rookTo = 84;
//						} else {
//							rookFrom = -1;
//							rookTo = -1;
//							System.out.println("move.from: " + move.from);
//							throw new RuntimeException("move.to.getIndex: " + move.to + " which is impossible!");
//						}
//					}
//				}
//			}
//			Move rookJump = new Move(this, rookFrom, rookTo);
//			moveRaw(rookJump);
//			if (movingPiece > 0) {
//				this.hasCastledWhite = true;
//			} else
//				this.hasCastledBlack = true;
//		}
//		if (movingPieceType == 6) {
//			if (this.onMove.equals(WHITE)) {
//				this.castleShortWhite = false;
//				this.castleLongWhite = false;
//			} else {
//				this.castleShortBlack = false;
//				this.castleLongBlack = false;
//			}
//		} else if (movingPieceType == 4)
//			if (this.onMove.equals(WHITE)) {
//				if (move.from == 18) {
//					this.castleShortWhite = false;
//				} else if (move.from == 11) {
//					this.castleLongWhite = false;
//				}
//			} else if (move.from == 88) {
//				this.castleShortBlack = false;
//			} else if (move.from == 81)
//				this.castleLongBlack = false;
//		int p = this.board[11];
//		if (p != 4)
//			this.castleLongWhite = false;
//		p = this.board[18];
//		if (p != 4)
//			this.castleShortWhite = false;
//		p = this.board[81];
//		if (p != -4)
//			this.castleLongBlack = false;
//		p = this.board[88];
//		if (p != -4)
//			this.castleShortBlack = false;
//		this.onMove = Boolean.valueOf(!this.onMove.boolValue());
//	}
//
//	int moveRaw(Move move) {
//		int movingPiece = 0;
//		Integer fromSquare = new Integer(move.from);
//		Integer capturedSquare = new Integer(move.to);
//		int capturedPiece = this.board[move.to];
//		if (capturedPiece > 0) {
//			this.whitePieces.remove(capturedSquare);
//			if (capturedPiece == 6) {
//				this.whiteKing = -1;
//			}
//		} else if (capturedPiece < 0) {
//			this.blackPieces.remove(capturedSquare);
//			if (capturedPiece == -6)
//				this.blackKing = -1;
//		}
//		if (move.promotedTo == 0) {
//			movingPiece = this.board[move.from];
//			if (movingPiece > 0) {
//				this.whitePieces.add(capturedSquare);
//				this.whitePieces.remove(fromSquare);
//				if (movingPiece == 6) {
//					this.whiteKing = move.to;
//				}
//			} else {
//				this.blackPieces.add(capturedSquare);
//				this.blackPieces.remove(fromSquare);
//				if (movingPiece == -6)
//					this.blackKing = move.to;
//			}
//			this.board[move.to] = movingPiece;
//			clearSquare(move.from, 0, this.board);
//		} else {
//			movingPiece = move.promotedTo;
//			if (this.board[move.from] < 0)
//				movingPiece *= -1;
//			this.board[move.to] = movingPiece;
//			clearSquare(move.from, 0, this.board);
//			if (movingPiece > 0) {
//				this.whitePieces.add(new Integer(move.to));
//				this.whitePieces.remove(fromSquare);
//				if (movingPiece == 6) {
//					this.whiteKing = move.to;
//				}
//			} else {
//				this.blackPieces.add(new Integer(move.to));
//				this.blackPieces.remove(fromSquare);
//				if (movingPiece == -6)
//					this.blackKing = move.to;
//			}
//		}
//		return movingPiece;
//	}
//
//	//Move getNextCaptureMove() {
//	//	updateCaptureMove();
//	//	if (this.nextCaptureMove == null) {
//	//		throw new NoSuchElementException("next without hasnext");
//	//	}
//
//	//	Move retVal = new Move(this.nextCaptureMove);
//	//	this.nextCaptureMove = null;
//	//	return retVal;
//	//}
//
//	//Move nextNonCaptureMove() {
//	//	updateNonCaptureMove();
//	//	if (this.nextNonCaptureMove == null) {
//	//		throw new NoSuchElementException("next without hasnext");
//	//	}
//
//	//	Move retVal = new Move(this.nextNonCaptureMove);
//	//	this.nextNonCaptureMove = null;
//	//	return retVal;
//	//}
//
//	bool noMoves() {
//		Collection moves = generateLegalMoves();
//		return moves.size() == 0;
//	}
//
//	bool onDiagonal(int moveFrom, int kingPosition) {
//		int diff = moveFrom - kingPosition;
//		return (diff % 11 == 0) || (diff % 9 == 0);
//	}
//
//	bool onFile(int moveFrom, int kingPosition) {
//		int diff = moveFrom - kingPosition;
//		return diff / 10 == 0;
//	}
//
//	Boolean getOnMove() {
//		return this.onMove;
//	}
//
//	bool onRank(int moveFrom, int kingPosition) {
//		int col1 = moveFrom / 10;
//		int col2 = moveFrom / 10;
//		return col1 == col2;
//	}
//
//	Piece pieceOn(int index) {
//		return Piece.makePiece(index, this.board);
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
//	void removeIllegalMoves(SortedSet moves) {
//		Collection markForDelete = new TreeSet();
//		for (Iterator it = moves.iterator(); it.hasNext();) {
//			Move move = (Move) it.next();
//			Info.ensureLegalNodes += 1;
//			Position nextPos = createTestPosition(this, move);
//			if (isReceivingCheck()) {
//				if (nextPos.isGivingCheck()) {
//					markForDelete.add(move);
//				}
//			} else {
//				int movingPiece = Math.abs(this.board[move.from]);
//				switch (movingPiece) {
//				default:
//					break;
//
//				case 6:
//					if (nextPos.isGivingCheck())
//						markForDelete.add(move);
//					break;
//
//				case 1:
//
//				case 2:
//
//				case 3:
//
//				case 4:
//
//				case 5:
//					if (nextPos.isGivingCheckNonKingMoving(move.from)) {
//						markForDelete.add(move);
//					}
//					break;
//				}
//			}
//		}
//		moves.removeAll(markForDelete);
//		for (Iterator it1 = markForDelete.iterator(); it1.hasNext();) {
//			Move m = (Move) it1.next();
//			for (Iterator it2 = moves.iterator(); it2.hasNext();) {
//				Move m2 = (Move) it2.next();
//				if (m.getText().equals(m2.getText())) {
//					it2.remove();
//					break;
//				}
//			}
//		}
//	}
//
//	void setBestMove(Move bestMove) {
//		this.bestMove = bestMove;
//	}
//
//	void setBestValue(int bestValue) {
//		this.bestValue = bestValue;
//	}
//
//	void setFENPosition(String fenString) {
//		clearBoard();
//		String[] fenFields = fenString.split(" ");
//		String fenPosition = fenFields[0];
//		String[] ranks = fenPosition.split("/");
//		for (int i = 0; i < 8; i++) {
//			String currentRank = ranks[(7 - i)];
//			fillRank(i, currentRank);
//		}
//
//		String fenOnMove = fenFields[1];
//		if (fenOnMove.equals("w")) {
//			this.onMove = WHITE;
//		} else if (fenOnMove.equals("b"))
//			this.onMove = BLACK;
//		String fenCastling = fenFields[2];
//		this.castleShortWhite = (fenCastling.indexOf('K') != -1);
//		this.castleLongWhite = (fenCastling.indexOf('Q') != -1);
//		this.castleShortBlack = (fenCastling.indexOf('k') != -1);
//		this.castleLongBlack = (fenCastling.indexOf('k') != -1);
//		String fenEnPassant = fenFields[3];
//		if (fenEnPassant.equals("-")) {
//			this.enPassantSquare = 0;
//		} else {
//			this.enPassantSquare = decodeSquare(fenEnPassant);
//		}
//	}
//
//	void setOnMove(Boolean onMove) {
//		this.onMove = onMove;
//	}
//
//	void setStartPosition(bool startPosition) {
//		this.isStartPosition = startPosition;
//	}
//
//	void setToStartPosition() {
//		clearBoard();
//		addStartPieces();
//		this.castleShortWhite = true;
//		this.castleLongWhite = true;
//		this.castleShortBlack = true;
//		this.castleLongBlack = true;
//		this.enPassantSquare = 0;
//		this.onMove = WHITE;
//		this.isGivingCheck = null;
//		this.isReceivingCheck = null;
//		setStartPosition(true);
//	}
//
//	void testClearEnPassantCapture(Move move, int board[] ) {
//		if (move.to > move.from) {
//			clearSquare(move.to, -10, board);
//			this.blackPieces.remove(new Integer(move.to - 10));
//		} else {
//			clearSquare(move.to, 10, board);
//			this.whitePieces.remove(new Integer(move.to + 10));
//		}
//	}
//
//	String toString() {
//		return this.board.toString();
//	}
//
//	bool tryMoveNonCapture(Set moves, int from, int next, Boolean color) {
//		if (invalidSquare(next))
//			return true;
//		int type = this.board[next];
//		if (type != 0) {
//			return true;
//		}
//
//		Move m = new Move(this, from, next, 0, type);
//		moves.add(m);
//		return false;
//	}
//
//	int typeOn(int nextIndex) {
//		return this.board[nextIndex];
//	}
//
//	void updateCaptureMove() {
//		if (this.nextCaptureMove != null)
//			return;
//		Boolean color = null;
//		bool finished = false;
//		while (!finished) {
//			if (this.persistentSquareForCapture > 88)
//				return;
//			int p = this.board[this.persistentSquareForCapture];
//			int type = Math.abs(p);
//			if ((type < 1) || (type > 6)) {
//				this.persistentSquareForCapture += 1;
//			} else {
//				color = EdenBrain.convertColor(p);
//				if (!color.equals(onMove())) {
//					this.persistentSquareForCapture += 1;
//				} else {
//					Move nextCapture = generateNextCaptureMove(this.persistentSquareForCapture, p, color);
//					if (nextCapture != null) {
//						this.nextCaptureMove = nextCapture;
//						finished = true;
//						break;
//					}
//					initializeCaptureMoveCounters();
//					this.persistentSquareForCapture += 1;
//				}
//			}
//		}
//	}
//
//	void updateNonCaptureMove() {
//		if (this.nextNonCaptureMove != null)
//			return;
//		Boolean color = null;
//		bool finished = false;
//		while (!finished) {
//			if (this.persistentSquareForNonCapture > 88)
//				return;
//			int p = this.board[this.persistentSquareForNonCapture];
//			int type = Math.abs(p);
//			if ((type < 1) || (type > 6)) {
//				this.persistentSquareForNonCapture += 1;
//			} else {
//				color = EdenBrain.convertColor(p);
//				if (!color.equals(onMove())) {
//					this.persistentSquareForNonCapture += 1;
//				} else {
//					Move nextNonCapture = generateNextNonCaptureMove(this.persistentSquareForNonCapture, p, color);
//					if (nextNonCapture != null) {
//						this.nextNonCaptureMove = nextNonCapture;
//						finished = true;
//						break;
//					}
//					initializeNonCaptureMoveCounters();
//					this.persistentSquareForNonCapture += 1;
//				}
//			}
//		}
//	}
//
//	long updatePawnZobristForMove(Move move, long pzobrist) {
//		int sourceType = this.board[move.from];
//		long zoFrom = 0L;
//		long zoTo = 0L;
//		if ((sourceType == 1) || (sourceType == -1)) {
//			zoFrom = kleinerZobristEntfernen(move.from);
//			if (move.promotedTo == 0)
//				zoTo = kleinerZobristSetzen(sourceType, move.to);
//		}
//		long zoKick = 0L;
//		if ((this.board[move.to] == 1) || (this.board[move.to] == -1))
//			zoKick = kleinerZobristEntfernen(move.to);
//		pzobrist ^= zoFrom;
//		pzobrist ^= zoTo;
//		pzobrist ^= zoKick;
//		return pzobrist;
//	}
//
//	void updateZobristEnPassant() {
//		this.zobrist ^= EdenBrain.enPassantZobrist;
//	}
//
//	long updateZobristForMove(Move move, long z) {
//		int sourceType = this.board[move.from];
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
//		if (move.isCastling(Math.abs(this.board[move.from]))) {
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
//			zoRookJumpTo = kleinerZobristSetzen(this.board[rookJumpFrom], rookJumpTo);
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