#pragma once
#include <iostream>
#include <string>
using namespace std;
string encodeSquare(int square);
int decodeSquare(string square);
int decodePiece(string promotedTo);
class Move{
public:
	Move(int from, int to, unsigned int captured = 0, unsigned int promoted = 0){
		this->from = from;
		this->to = to;
		this->captured = captured;
		this->promoted = promoted;
	}

	Move(string move) {
		int from = decodeSquare(move.substr(0, 2));
		int to = decodeSquare(move.substr(2, 4));
		string promotedTo = move.substr(4);
		promoted = 0;
		if (promotedTo!="") {
			promoted = decodePiece(promotedTo);
		}
		this->from = from;
		this->to = to;
		captured = 0;
	}
	bool operator == (const Move &i) const {
		return from == i.from && to == i.to;
	}
	
	bool isCastling(int piece) {
		return (piece == 6) && (abs(from - to) == 2);
		}
	void print(){
		cout << toString() << endl;
	}	
	static string encodePiece(int piece){
		static const string pieces = "-pnbrqk";
		return string(1,pieces[piece]);
	}
	string encodePromoted(void){
		string retVal = "";
		retVal +=promoted==0?"":encodePiece(promoted);
		return retVal;
	}
	string toString(){
		string retVal =  encodeSquare(from) + (captured==0?"-":"x") + encodeSquare(to)+encodePromoted();
		return retVal;
	}
	int from;
	int to;
	unsigned int captured;
	unsigned int promoted;

private:
};