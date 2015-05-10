#pragma once
#include <iostream>

using namespace std;

class Move{
public:
	Move(int from, int to, int captured = 0){
		this->from = from;
		this->to = to;
		this->captured = captured;
	}
	//Move(int from, int to, int promoted, int captured){}
	Move(int from, int to){}
	Move(){}
	void print(){
		cout << Position::encodeSquare(from) << "-" << Position::encodeSquare(to) << endl;
	}
private:
	int from;
	int to;
	int captured;
};