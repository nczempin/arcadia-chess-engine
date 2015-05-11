//  main.cpp


#include <iostream>
#include <string>
#include <sstream>
#include <vector>


#include "Position.h"
#include "MoveGenerator.h"

using namespace std;

Position p;
string extractPosition(string);
string extractMoves(string);

bool done;
	static string encodeSquare(int square) {
		int ten =square / 10;
		int one = square - ten * 10;
		char letter = (int)'a' + one - 1;	
		char number = (int)'1' + ten - 1;	
		string retVal;
		retVal+=letter;
		retVal+=number;

		return retVal;
	}
bool startsWith(string smallString, string bigString){
	return bigString.compare(0, smallString.length(), smallString)==0;
}


  static string extractMoves(string parameters)
   {
     string pattern = " moves ";
     int index = parameters.find(pattern);
     if (index == string::npos)
     {
       return ""; //not found
     }
     
     string moves = parameters.substr(index + pattern.length());
     return moves;
   }
   


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

void parse(string toParse) {
	if (toParse == "uci"){
		cout << "id name Arcadia 0.0.1RC"<< endl;
		cout << "id author Nicolai Czempin" << endl;
		cout << "uciok" << endl;
	}else if (toParse == "isready"){
		cout << "readyok" << endl;
	}else if (startsWith("position", toParse)){
		p.clear();
		string positionString = "startpos";//extractPosition(mystr);
		if (positionString =="startpos") {
			p.setToStart();
		}else if (startsWith("fen",positionString)){
			// String positionFen = extractFen(positionString);
			// this.brain.setFENPosition(positionFen);
			cout << "TODO: fen" << endl;
		}
		string movesString =extractMoves(toParse);
		vector<string> moves = split(movesString,' ');
		//p.clearThreeDraws();
		if ((movesString != "") && (moves.size() != 0))
		{
			for (string move:moves) {
				cout << "making move: "<<move<<endl;
				p.makeMove(move);
			}
		}
	}else if (toParse == ""){			
		cout << "Moves: " << endl;
		MoveGenerator mg;
		mg.generateAllMoves(p);
	}
}
int main()
{
	cout << "Welcome to Arcadia, a chess engine by Nicolai Czempin. This is version 0.0.1" << endl;
	done = false;
	string mystr;
	while (!done){
		getline (cin, mystr);
		parse(mystr);
	}
	return 0;
}
