#include "Evaluator.h"


Evaluator::Evaluator(void)
{
}


Evaluator::~Evaluator(void)
{
}

int Evaluator::pieceValues[] = { 100, 325, 325, 500, 975, 250 };

int Evaluator::bishopSquareValues[] =  {
	0, -15, -10, -5, -10, -10, -6, -10, -15, 0,
	0, -7, 1, -1, 2, 3, -1, 2, -9, 0,
	0, 0, -1, -2, 3, 4, -1, 0, 1, 0,
	0, 1, 5, 7, 6, 6, 7, 5, 1, 0,
	0, 1, 5, 7, 6, 6, 7, 5, 1, 0,
	0, 0, -1, -2, 3, 4, -1, 0, 1, 0,
	0, -7, 1, -1, 2, 3, -1, 2, -9, 0, 
	0, -15, -10, -5, -10, -10,-6, -10, -15 };


int Evaluator::kingEndgameSquareValues[] = { 0, -5, -3, 1, 2, 2, 1, -3, -5, 0, 0, -3, 1, 2, 3, 3, 2, 1, -3, 0, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 0, 2, 3, 4, 5, 5,
	4, 3, 2, 0, 0, 2, 3, 4, 5, 5, 4, 3, 2, 0, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 0, -3, 1, 2, 3, 3, 2, 1, -3, 0, 0, -5, -3, 1, 2, 2, 1, -3, -5 };

int Evaluator::kingEndgameSquareValuesKBNKLight[] = { 0, -50, -40, -30, -20, -15, -8, -5, 0, 0, 0, -40, 1, 2, 3, 3, 2, 1, -5, 0, 0, -30, 2, 3, 4, 4, 3, 2, -8,
	0, 0, -20, 3, 4, 5, 5, 4, 3, -15, 0, 0, -15, 3, 4, 5, 5, 4, 3, -20, 0, 0, -8, 2, 3, 4, 4, 3, 2, -30, 0, 0, -5, 1, 2, 3, 3, 2, 1, -40, 0, 0, 0, -5,
	-6, -7, -8, -10, -40, -50 };

int Evaluator::kingEndgameSquareValuesKBNKDark[] = { 0, 0, -5, -8, -15, -20, -30, -40, -50, 0, 0, -5, 1, 2, 3, 3, 2, 1, -40, 0, 0, -8, 2, 3, 4, 4, 3, 2, -30,
	0, 0, -15, 3, 4, 5, 5, 4, 3, -20, 0, 0, -20, 3, 4, 5, 5, 4, 3, -15, 0, 0, -30, 2, 3, 4, 4, 3, 2, -8, 0, 0, -40, 1, 2, 3, 3, 2, 1, -5, 0, 0, -50,
	-40, -30, -20, -15, -8, -5 };

int Evaluator::knightSquareValues[] = { 
	0, -31, -8, -8, -8, -8, -8, -9, -31, 0,
	0, -9, -4, -2, 2, 3, -2, -4, -9, 0,
	0, -5, 0, 2, 1, 1, 4, 0, -5, 0, 
	0, -4, 1,2, 8, 8, 2, 1, -5, 0, 
	0, -4, 1, 2, 8, 8, 2, 1, -5, 0,
	0, -5, 0, 5, 1, 1, 6, 0, -5, 0, 
	0, -9, -4, -2, 2, 2, -2, -4, -9, 0,
	0, -31, -7, -8, -8, -8,-8, -8, -31 };

int Evaluator::whitePawnSquareValues[] = { 
	0, 16, 22, 35, 45, 45, 35, 22, 16, 0,
	0, 7, 14, 20, 24, 24, 20, 14, 7, 0,
	0, 3, 4, 5, 8, 6, 5, 4, 3, 0,
	0, 0, 0, 1, 90, 40, 3, 0, 0, 0,
	0, -2, 1, -2, 2, 1, -1, 1, -2, 0,
	0, 2, 2, 2, -11, -9, 1, 2, 2 };
int Evaluator::blackPawnSquareValues[] = { 
	0, 16, 22, 35, 45, 45, 35, 22, 16, 0,
	0, 7, 14, 20, 24, 24, 20, 14, 7, 0,
	0, 3, 4, 5, 8, 6, 5, 4, 3, 0,
	0, 0, 0, 1, 90, 40, 3, 0, 0, 0,
	0, -2, 1, -2, 2, 1, -1, 1, -2, 0,
	0, 2, 2, 2, -11, -9, 1, 2, 2 };

int Evaluator::passedPawnProgression[] = { 7, 14, 27, 38, 45, 60 };

Position Evaluator::position;