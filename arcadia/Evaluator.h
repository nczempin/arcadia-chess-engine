#pragma once

#include "Position.h"

class Evaluator
{
public:
	Evaluator(void);
	~Evaluator(void);
	static int getValue(Position position);
};

