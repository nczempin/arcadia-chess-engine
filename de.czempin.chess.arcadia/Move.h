#pragma once
#include <iostream>
#include <string>
using namespace std;
string encodeSquare(int square);

class Move{
public:
	Move(int from, int to, int captured = 0, int promoted = 0){
		this->from = from;
		this->to = to;
		this->captured = captured;
		this->promoted = promoted;
	}
	Move(string moveString){
	}
	void print(){
		cout << encodeSquare(from) << "-" << encodeSquare(to) << endl;
	}	
	int from;
	int to;
	int captured;
	int promoted;

private:
};