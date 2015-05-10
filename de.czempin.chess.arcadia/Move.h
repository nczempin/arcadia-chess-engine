#pragma once
#include <iostream>

using namespace std;

class Move{
public:
	Move(int from, int to, int captured = 0, int promoted = 0){
		this->from = from;
		this->to = to;
		this->captured = captured;
		this->promoted = promoted;
	}
	void print(){
		cout << Position::encodeSquare(from) << "-" << Position::encodeSquare(to) << endl;
	}
private:
	int from;
	int to;
	int captured;
	int promoted;
};