#pragma once
#include <iostream>
#include <string>

#include "global.h"

using namespace std;

class Move{
public:
	Move(int from=-1, int to=-1, unsigned int captured = 0, unsigned int promoted = 0){
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
	bool operator != (const Move &i) const {
		return from != i.from || to != i.to;
	}
	//bool operator> (const Move & other)const{
	//	return value > other.value;
	//}
	bool operator< (const Move & other)const{
		if (value != other.value){
			return value < other.value;
		}
		if (captured != other.captured){
			return captured < other.captured;
		}
		if (promoted != other.promoted){
			return promoted < other.promoted;
		}
		if (from!=other.from){
			return from < other.from;
		}
		if (to!=other.to){
			return 	to < other.to;
		}
		//TODO else???
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
		string retVal =  encodeSquare(from) + (captured==0?"-":"x") + encodeSquare(to)+encodePromoted();//+" ("+to_string(value)+")";
		return retVal;
	}
	int from;
	int to;
	unsigned int captured;
	unsigned int promoted;

	int value;

private:
};