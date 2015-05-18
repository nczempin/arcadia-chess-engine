//  main.cpp


#include <iostream>

#include "global.h"
#include "Position.h"
#include "MoveGenerator.h"
#include "Searcher.h"

using namespace std;

Position p;
string extractPosition(string);
string extractMoves(string);

bool done;
vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

bool convertColor(int piece){
	return piece > 0;
}
int decodeSquare(string square) {
	char letter = square[0];
	char digit = square[1];
	int one = letter-'a' + 1;
	int ten =digit-'1'+1;
	int index = 10 * ten + one;
	return index;
}

string encodeSquare(int square) {
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
	static string command = "fen ";
	string retValue = positionString.substr(command.length()); // remove "fen " TODO: more fail-safe / defensive
	//remove moves
	int movesFoundAt =  retValue.find("moves ");
	if (movesFoundAt != string::npos){
		retValue = retValue.substr(0,movesFoundAt);
	}
	return retValue;
}

bool invalidSquare(int next) {
	bool isInvalid = false;
	if ((next < 11) || (next > 88))
		isInvalid = true;
	int mod = next % 10;
	if ((mod == 0) || (mod == 9))
		isInvalid = true;
	return isInvalid;
}

void parse(string toParse) {
	// for debugging
	if (toParse=="."){
		toParse = "position fen n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1";
	}
	if (toParse == "uci"){
		cout << "id name Arcadia "+VERSION<< endl;
		cout << "id author Nicolai Czempin" << endl;
		cout << "uciok" << endl;
	}else if (startsWith("perft ",toParse)){
		char perftDepthParameter = toParse[6];//'4'; //TODO extract from toParse
		int perftDepth = Character::getNumericValue(perftDepthParameter);
		//TODO do this more elegantly
		for (int i = 0; i< perftDepth; ++i){
			int nodes = perft (p, i+1);
			cout << i+1 << ", " << nodes << endl;
		}
		cout << "Done." << endl;

	}else if (startsWith("divide ",toParse)){
		char perftDepthParameter = toParse[7];//'4'; //TODO extract from toParse
		int perftDepth = Character::getNumericValue(perftDepthParameter);
		//TODO do this more elegantly
		MoveGenerator mg;
		list<Move> moves = mg.generateLegalMoves(p);
		int count = 0;
		Position tmpPos = p;
		for(Move move: moves){
			tmpPos = p; //simple but inefficient way to undo the move
			tmpPos.makeMove(move);

			count = perft(tmpPos, perftDepth -1);
			cout << move.toString() << ": " << count << endl;
		}

		cout << "Done." << endl;

	}else if (toParse == "isready"){
		cout << "readyok" << endl;
	}else if (startsWith("go", toParse)){
		Searcher s;
		Move bestmove = s.analyze(p);
		cout << "bestmove " << bestmove.toString() << endl;
	}else if (startsWith("stop", toParse)){ //TODO this is not really how 'stop' is supposed to work
		Searcher s;
		Move bestmove = s.analyze(p);
		cout << "bestmove " << bestmove.toString() << endl;

	}else if (startsWith("quit", toParse)){
		exit(0); //TODO more elegance
	}else if (startsWith("position", toParse)){
		p.clear();
		string positionString = extractPosition(toParse);
		if (startsWith("startpos",positionString)) {
			p.setToStart();
		}else if (startsWith("fen",positionString)){
			string positionFen = extractFen(positionString);
			p.setFenPosition(positionFen);
			p.print();
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
}	 
int decodePiece(string promotedTo) {
	int retValue = 0;
	if (promotedTo=="q") {
		retValue = 5;
	} else if (promotedTo=="r") {
		retValue = 4;
	} else if (promotedTo=="b") {
		retValue = 3;
	} else if (promotedTo=="n")
		retValue = 2;
	return retValue;
}

int main()
{
	cout << "Welcome to Arcadia, a chess engine by Nicolai Czempin. This is version "<< VERSION << endl;
	done = false;
	string mystr;
	while (!done){
		getline (cin, mystr);
		parse(mystr);
	}
	return 0;
}
