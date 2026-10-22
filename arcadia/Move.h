#pragma once
#include <iostream>
#include <string>

#include <cassert>

#include "global.h"

using namespace std;

class Move{
public:
	Move(int from=-1, int to=-1, int captured=0 , int promoted = 0){
//		if (captured < 0){
//			cout << "oops!" << endl;
//		}
//		assert(captured>=0);
//		assert(promoted>=0);
		this->from = from;
		this->to = to;
		this->captured = captured;
		this->promoted = promoted;
		this->value = 0;
	}

	Move(string move) {
		int from = decodeSquare(move.substr(0, 2));
		int to = decodeSquare(move.substr(2, 2));
		string promotedTo = move.length() > 4 ? move.substr(4, 1) : "";
		promoted = 0;
		if (promotedTo!="") {
			promoted = decodePiece(promotedTo);
		}
		this->from = from;
		this->to = to;
		captured = 0;
		value = 0;
	}
	bool operator == (const Move &i) const {
		return from == i.from && to == i.to && promoted == i.promoted;
	}
	bool operator != (const Move &i) const {
		return from != i.from || to != i.to || promoted != i.promoted;
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
        return false; //TODO else???
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
	string toString() const {
		if (from < 11 || to < 11) {
			return "0000";
		}
		string retVal = encodeSquare(from) + encodeSquare(to) + const_cast<Move*>(this)->encodePromoted();
		return retVal;
	}
	int from;
	int to;
	unsigned int captured;
	unsigned int promoted;

	int value;

private:
};