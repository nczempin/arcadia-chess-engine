//  main.cpp


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include < list>


#include "Position.h"
#include "MoveGenerator.h"

using namespace std;

Position p;
string extractPosition(string);
string extractMoves(string);

bool done;

static int decodeSquare(string square) {
	char letter = square[0];
	char digit = square[1];
	int one = letter-'a' + 1;
	int ten =digit-'1'+1;
	int index = 10 * ten + one;
	return index;
}

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
static string extractPosition(string parameters)
{
	string pattern = "position ";
	int index = parameters.find(pattern);
	if (index == string::npos)
	{
		return ""; //not found
	}
	string retVal = parameters.substr(index + pattern.length());
	return retVal;
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
static int perft(const Position position, int maxDepth){
	if (maxDepth==0){
		return 1;
	}
	MoveGenerator mg;
	list<Move> moves = mg.generateLegalMoves(position);
	int count = 0;
	Position tmpPos = position;
	for(Move move: moves){
		tmpPos = position;
		tmpPos.makeMove(move);
		count += perft(tmpPos, maxDepth -1);
	}
	return count;
}

string extractFen(string positionString){
	static string command = "position fen ";
	string retValue = positionString.substr(command.length()); // remove "fen " TODO: more fail-safe / defensive
	//remove moves
	int movesFoundAt =  retValue.find("moves ");
	if (movesFoundAt != string::npos){
		retValue = retValue.substr(0,movesFoundAt);
	}
	return retValue;
}
void parse(string toParse) {
	// for debugging
	if (toParse=="."){
		toParse = "position startpos moves e2e4 g7g5 f1c4 f7f6 d1h5";
	}
	if (toParse == "uci"){
		cout << "id name Arcadia 0.0.1dev"<< endl;
		cout << "id author Nicolai Czempin" << endl;
		cout << "uciok" << endl;
	}else if (startsWith(toParse,"perft")){
		string perftDepthParameter = "4"; //TODO extract from toParse
		int perftDepth = 4; // TODO extract from perftDepthParameter
		int nodes = perft (p, perftDepth);
		cout << perftDepth << ", " << nodes << endl;

	}else if (toParse == "isready"){
		cout << "readyok" << endl;
	}else if (startsWith("position", toParse)){
		p.clear();
		string positionString = extractPosition(toParse);
		if (startsWith("startpos",positionString)) {
			p.setToStart();
		}else if (startsWith("position fen",positionString)){
			string positionFen = extractFen(positionString);
			//p.setFENPosition(positionFen);
			cout << "TODO: fen" << positionFen << endl;
		}
		string movesString =extractMoves(toParse);
		vector<string> moves = split(movesString,' ');
		//p.clearThreeDraws();
		if ((movesString != "") && (moves.size() != 0))
		{
			for (string move:moves) {
				p.print();
				cout << "making move: "<<move<<endl;
				p.makeMove(move);
			}
		}
	}else if (toParse == "sp"){	
		p.print();
	}else if (toParse == "sm"){			
		cout << "Moves: " << endl;
		MoveGenerator mg;
		list<Move> moves =mg.generateLegalMoves(p);
		for (Move move:moves){
			move.print();
		}
	}else {
		cout << "???" << endl;
	}
}	 static int decodePiece(string promotedTo) {
	int retValue = 0;
	if (promotedTo=="q") {
		retValue = 5;
	} 
	//TODO underpromotion
	//else if (promotedTo.equals("r")) {
	//	retValue = 4;
	//} else if (promotedTo.equals("b")) {
	//	retValue = 3;
	//} else if (promotedTo.equals("n"))
	//	retValue = 2;
	return retValue;
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
