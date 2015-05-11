#pragma once
#include <iostream>
#include <string>
using namespace std;
string encodeSquare(int square);
int decodeSquare(string square);
int decodePiece(string promotedTo);
class Move{
public:
	Move(int from, int to, int captured = 0, int promoted = 0){
		this->from = from;
		this->to = to;
		this->captured = captured;
		this->promoted = promoted;
	}
	
	 Move(string move) {
		int from = decodeSquare(move.substr(0, 2));
		int to = decodeSquare(move.substr(2, 4));
		string promotedTo = move.substr(4);
		if (promotedTo!="") {
			promoted = 5; //TODO underpromotion
			}
			this->from = from;
		this->to = to;
		//FIXME what about captured?
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