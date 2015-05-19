#pragma once

#include "Position.h"
#include "global.h"

class Evaluator
{
public:
	Evaluator(void);
	~Evaluator(void);
	static Position position;



	static int pieceValues[];

	static int bishopSquareValues[];

	static int blackPawnSquareValues[];

	static int kingEndgameSquareValues[];

	static int kingEndgameSquareValuesKBNKLight[];

	static int kingEndgameSquareValuesKBNKDark[];

	static int knightSquareValues[];


	static int whitePawnSquareValues[];

	static int passedPawnProgression[];
	/*int getPieceEndgameValue(int square, int piece, int file) {
	int retValue = 0;
	switch (piece) {
	case -6:

	case 6:
	retValue = getKingEndgameValue(square, piece);
	break;

	case -5:

	case 5:
	retValue = -25;
	break;

	case -4:

	case 4:
	retValue = 25;
	break;

	case -3:

	case 3:
	retValue = 3;
	break;

	case -2:

	case 2:
	retValue = -3;
	break;

	case -1:

	case 1:
	retValue = getPawnEndgameValue(square, piece, file);
	break;

	case 0:

	default:
	retValue = 0;
	}

	return retValue;
	}
	*/
	static int getPieceMaterialValue(int piece) {
		//if (piece == 0) {
		//	System.out.println("moveStack: " + EdenBrain.moveStack);
		//	throw new IllegalStateException("piece==0");
		//}

		int retVal = pieceValues[(abs(piece) - 1)];
		return retVal;
	}

	static int getPieceMidgameValue(int square, int piece, int file) {
		int retValue = 0;
		switch (piece) {
		case -6:

		case 6:
			retValue = getKingMidgameValue(square, piece, file);
			break;

		case -5:

		case 5:
			retValue = getQueenValue(piece, square, file);
			break;

		case -4:

		case 4:
			retValue = getRookValue(piece, square, file);
			break;

		case -3:

		case 3:
			retValue = getBishopValue(square, piece);
			break;

		case -2:

		case 2:
			retValue = getKnightValue(piece, square);
			break;

		case -1:

		case 1:
			retValue = getPawnMidgameValue(square, piece, file);
			break;

		case 0:

		default:
			retValue = 0;
		}

		return retValue;
	}

	static int getQueenValue(int plusminus, int square, int file) {
		int retValue = getRookValue(plusminus, square, file) / 4;
		return retValue;
	}

	static int getRookValue(int plusminus, int square, int file) {
		int retVal = 0;//isOnOpenFile(square, file) ? 12 : 0;
		//int x = getHorizontalKingTropism(plusminus, square);
		//int y = getVerticalKingTropism(plusminus, square);
		//int minTropism = min(x, y);
		//retVal -= minTropism / 4;
		return retVal;
	}
	//int getKingEndgameValue(int square, int piece) {
	//	return kingEndgameSquareValues[(square - 10)];
	//}

	static int getKingMidgameValue(int square, int piece, int file) {
		int retValue = 0;
		int openFiles = 0;
		int halfOpenFiles = 0;
		int rank = square / 10;
		/*		if (isOnOpenFile(square, file)) {
		openFiles++;
		} else if (isOnOpenOrHalfOpenFile(piece, file, rank))
		halfOpenFiles++;
		if (isOnOpenFile(square, file - 1)) {
		openFiles++;
		} else if (isOnOpenOrHalfOpenFile(piece, file - 1, rank))
		halfOpenFiles++;
		if (isOnOpenFile(square, file + 1)) {
		openFiles++;
		} else if (isOnOpenOrHalfOpenFile(piece, file + 1, rank))
		halfOpenFiles++;
		retValue = (int) (retValue - 30.0 * Math.pow(2.0, openFiles));
		retValue = (int) (retValue - 5.0 * Math.pow(2.0, halfOpenFiles));*/
		if (piece == 6) {
			if ((square > 13) && (square < 17))
				retValue -= 35;
			if (square > 20) {
				retValue -= 55;
			} else {
				if ((square == 17) || (square == 18)) {
					if (position.board[26] != 1)
						retValue -= 10;
					if ((position.board[27] != 1) && (position.board[27] != 3)) {
						retValue -= 10;
						if (position.board[37] != 1)
							retValue -= 10;
					}
					if (position.board[28] != 1) {
						retValue -= 6;
						if (position.board[38] != 1) {
							retValue -= 11;
						}
					}
				} else if ((square == 12) || (square == 11) || (square == 13)) {
					if (position.board[23] != 1)
						retValue -= 10;
					if ((position.board[22] != 1) && (position.board[22] != 3)) {
						retValue -= 10;
						if (position.board[32] != 1)
							retValue -= 10;
					}
					if (position.board[21] != 1) {
						retValue -= 10;
						if (position.board[31] != 1)
							retValue -= 10;
					}
				}
				if (square == 13)
					retValue -= 37;
			}
		}
		if (piece == -6) {
			if ((square > 83) && (square < 87))
				retValue -= 35;
			if (square < 80) {
				retValue -= 55;
			} else if ((square == 87) || (square == 88)) {
				if (position.board[76] != -1)
					retValue -= 10;
				if ((position.board[77] != -1) && (position.board[77] != -3)) {
					retValue -= 10;
					if (position.board[67] != -1)
						retValue -= 10;
				}
				if (position.board[78] != -1) {
					retValue -= 6;
					if (position.board[68] != -1) {
						retValue -= 11;
					}
				}
			} else if ((square == 82) || (square == 81) || (square == 83)) {
				if (position.board[73] != -1)
					retValue -= 10;
				if ((position.board[72] != -1) || (position.board[72] != -3)) {
					retValue -= 10;
					if (position.board[62] != -1)
						retValue -= 10;
				}
				if (position.board[71] != -1) {
					retValue -= 10;
					if (position.board[61] != -1)
						retValue -= 10;
				}
				if (square == 83)
					retValue -= 37;
			}
		}
		return retValue;
	}

	static	int getKnightValue(int piece, int square) {
		int retVal =knightSquareValues[(square - 10)];
		//int x = getHorizontalKingTropism(piece, square);
		//int y = getVerticalKingTropism(piece, square);
		//int manhattanTropism = x + y;
		//retVal -= manhattanTropism / 3;
		return retVal;
	}
	static 	int getBishopValue(int i, int plusminus) {
		int retValue = bishopSquareValues[(i - 10)];
		if (plusminus > 0) {
			if (i == 16) {
				if (position.board[25] > 0)
					retValue -= 3;
				if (position.board[27] > 0)
					retValue--;
			}
			if ((i == 34) && (position.board[24] == 1)) {
				retValue -= 25;
			}
		} else {
			if (i == 86) {
				if (position.board[75] < 0)
					retValue -= 3;
				if (position.board[77] < 0)
					retValue--;
			}
			if ((i == 64) && (position.board[74] == -1))
				retValue -= 25;
		}
		return retValue;
	}
	//int evaluatePawnStructureMidgame() {
	//		/Info.pawnStructureProbes += 1;
	//		//Long pz = getPawnZobrist();
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
	static int getMidgameValue() {
		int whiteValue = 0;
		int blackValue = 0;
		int whiteMValue = 0;
		int blackMValue = 0;
		int whiteCValue = 0;
		int blackCValue = 0;	
		//bool possibleBishopPairWhite = false;
		//bool possibleBishopPairBlack = false;
		//int pawnStructureValue = evaluatePawnStructureMidgame();
		int p;
		for (int i = 11; i< 89; ++i){
			int file = i % 10;
			p = position.board[i];
			if (p == 0){
				continue;
			}else if (p > 0){ //WHITE
				whiteMValue += getPieceMaterialValue(p);
				whiteCValue += getPieceMidgameValue(i, p, file);
			} else { //BLACK
				blackMValue += getPieceMaterialValue(p);
				blackCValue += getPieceMidgameValue(i, p, file);
			}
		}
		//int whiteCValue = 0;
		//int whiteMValue = 0;
		//	int whiteSquare = ((Integer) whiteIt.next()).intValue();
		//	int whitePiece = board[whiteSquare];
		//	if (whitePiece != 1) {
		//		whiteMValue += getPieceMaterialValue(whitePiece);
		//		if (whitePiece == 3) {
		//			if (possibleBishopPairWhite)
		//				whiteCValue += 50;
		//			possibleBishopPairWhite = true;
		//		}
		//		int file = whiteSquare % 10;
		//		whiteCValue += getPieceMidgameValue(whiteSquare, whitePiece, file);
		//	}
		//}
		//Iterator blackIt = blackPieces.iterator();
		//int blackCValue = 0;
		//int blackMValue = 0;
		//while (blackIt.hasNext()) {
		//	int blackSquare = ((Integer) blackIt.next()).intValue();
		//	int blackPiece = board[blackSquare];
		//	if (blackPiece != -1) {
		//		blackMValue += getPieceMaterialValue(blackPiece);
		//		if (blackPiece == -3) {
		//			if (possibleBishopPairBlack)
		//				blackCValue += 50;
		//			possibleBishopPairBlack = true;
		//		}
		//		int file = blackSquare % 10;
		//		blackCValue += getPieceMidgameValue(blackSquare, blackPiece, file);
		//	}
		//}

		blackValue += blackCValue;
		whiteValue += whiteCValue;

		//if (!hasCastledBlack)
		//	blackValue -= 61;
		//if (!hasCastledWhite)
		//	whiteValue -= 61;
		if (whiteMValue > blackMValue + 105) {
			int diff = whiteMValue + blackMValue - 500;
			int bonus = (8000 - diff) / 100;
			if (bonus > 74)
				bonus = 74;
			whiteValue += bonus;
		} else if (blackMValue > whiteMValue + 105) {
			int diff = blackMValue + whiteMValue - 500;
			int bonus = (8000 - diff) / 100;
			if (bonus > 74)
				bonus = 74;
			blackValue += bonus;
		}
		int retVal = whiteValue + whiteMValue  - blackValue - blackMValue;
		if (position.onMove == BLACK)
			retVal = -retVal;
		return retVal;
	}

	//int getPawnEndgameValue(int i, int plusminus, int file) {
	//	int retValue = 0;
	//	if (plusminus > 0) {
	//		retValue = whitePawnSquareValues[(79 - i)] / 2;
	//	} else
	//		retValue = blackPawnSquareValues[(i - 20)] / 2;
	//	int rank = i / 10;
	//	if (isPassed(i, plusminus, file, rank))
	//		if (plusminus > 0) {
	//			retValue = (int) (retValue + 1.5 * passedPawnProgression[(rank - 2)]);
	//		} else
	//			retValue = (int) (retValue + 1.5 * passedPawnProgression[(7 - rank)]);
	//		if (isIsolated(i, file))
	//			retValue -= 15;
	//		if (isDoubled(i, file))
	//			retValue -= 18;
	//		return retValue;
	//}

	static int getPawnMidgameValue(int i, int plusminus, int file) {
		int retValue;

		if (plusminus > 0) {
			retValue = whitePawnSquareValues[(79 - i)];
		} else
			retValue = blackPawnSquareValues[(i - 20)];
		int rank = i / 10;
		//if (isPassed(i, plusminus, file, rank)) {
		//	int passedValue = 0;
		//	if (plusminus > 0) {
		//		passedValue += passedPawnProgression[(rank - 2)];
		//	} else
		//		passedValue += passedPawnProgression[(7 - rank)];
		//	retValue += passedValue;
		//}
		//if (isIsolated(i, file))
		//	retValue -= 12;
		//if (isDoubled(i, file))
		//	retValue -= 16;
		return retValue;
	}

	static	int getValue(Position p) {
		position = p;
		//wpc = countWhitePieces();
		//bpc = countBlackPieces();
		//if (isInsufficientMaterial(wpc, bpc))
		//	return 0;
		//if (isInsufficientMaterial(bpc, wpc))
		//	return 0;
		//if (isEndgame()) {
		//	return getEndgameValue();
		//}
		return getMidgameValue();
	}

};

