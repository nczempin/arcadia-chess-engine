//  main.cpp


#include <iostream>
#include <chrono>
#include <future>
#include <thread>

#include "global.h"
#include "Position.h"
#include "MoveGenerator.h"
#include "Searcher.h"
#include "Evaluator.h"

using namespace std;

Position p;
Searcher s;
static string extractPosition(string);
static string extractMoves(string);
future<Move> fut;
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
long calculateTimePerMove(long t, long inc, int movesToGo){
	if ((t <= 0L) && (inc <= 0L))
		return -1L;
	long overhead = min(100L, max(30L, t / 4));
	long avail = max(2L, t - overhead);
	int slice = (movesToGo > 0) ? (movesToGo + 5) : 30;
	long retVal = avail / slice + inc / 2;
	long maxAllowed = max(5L, avail / 4);
	if (retVal > maxAllowed)
		retVal = maxAllowed;
	long minAllowed = max(2L, min(10L, avail / 6));
	if (retVal < minAllowed)
		retVal = minAllowed;
	return retVal;
}

void resetClock(){
	Info::start = chrono::system_clock::now();
}


long timePerMove;
bool timeUp()
{
	if (timePerMove <= 0L)
		return false;
	auto now = chrono::system_clock::now(); 
	chrono::duration<double> elapsed_seconds = now-Info::start; 
	return elapsed_seconds.count() >= timePerMove/1000.0;
}

bool softTimeUp()
{
	if (timePerMove <= 0L)
		return false;
	auto now = chrono::system_clock::now(); 
	chrono::duration<double> elapsed_seconds = now-Info::start; 
	return elapsed_seconds.count() >= (timePerMove * 0.5)/1000.0;
}


static string extractMoves(string parameters)
{
	string pattern = " moves ";
	size_t index = parameters.find(pattern);
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
	size_t index = parameters.find(pattern);
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
	vector<Move> moves = mg.generateLegalMoves(position);
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
	size_t movesFoundAt =  retValue.find("moves ");
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

Move asyncAnalyze(){
	Move bestmove = s.analyze(p);
	s.printInfo();
	cout << "bestmove " << bestmove.toString() << endl << flush;
	return bestmove;
}

void stopBrain()
{
	s.done = true; // ask the thread to finish
	if (fut.valid()) {
		fut.get(); //wait until the thread is finished
	}
}
void printInfo(){
	while(!s.done){
		s.printInfo();
		this_thread::sleep_for (chrono::seconds(1));
	}
}
void startBrain() {
	if (fut.valid()) {
		s.done = true;
		fut.get();
	}
	s.done = false;
	fut = async(launch::async, asyncAnalyze);
}


int extractIntValue(string parameters, string s){
	string padded = " " + parameters + " ";
	string token = " " + s + " ";
	size_t index = padded.find(token);
	if (index == string::npos) {
		return 0;
	}
	size_t searchFrom = index + token.length();
	if (searchFrom >= padded.length()) {
		return 0;
	}
	string extracted = padded.substr(searchFrom);
	vector<string> parts = split(extracted, ' ');
	for (const string& part : parts) {
		if (!part.empty()) {
			try {
				return stoi(part);
			} catch (...) {
				return 0;
			}
		}
	}
	return 0;
}
void parse(string toParse) {
	// for debugging
	if (toParse=="."){
		toParse = "position fen r3r1k1/1p3nqp/2pp4/p4p2/Pn3P1Q/2N4P/1PPR2P1/3R1BK1 w - - 0 1";
	}
    if (toParse=="ps"){
        toParse="position startpos";
    }
	if (toParse == "uci"){
		cout << "id name Arcadia "+VERSION<< endl;
		cout << "id author Nicolai Czempin" << endl;
		cout << "uciok" << endl << flush;
	}else if (toParse == "ucinewgame" || startsWith("setoption", toParse)){
		if (toParse == "ucinewgame") {
			stopBrain();
			p.clear();
			p.setToStart();
			s.gameHistory.clear();
			s.gameHistory.push_back(p.getHash());
		}
	}else if (startsWith("perft ",toParse)){
		int perftDepth = extractIntValue(toParse, "perft");
		if (perftDepth <= 0 && toParse.length() > 6) {
			perftDepth = Character::getNumericValue(toParse[6]);
		}

		chrono::time_point<chrono::system_clock> end;

		for (int i = 0; i< perftDepth; ++i){
			Info::start = chrono::system_clock::now();
			int nodes = perft (p, i+1);
			end = chrono::system_clock::now();
			chrono::duration<double> elapsed_seconds = end-Info::start;
			cout << i+1 << ", " << nodes << " @ "  << elapsed_seconds.count()<<endl;
		}
		cout << "Done." << endl;

	}else if (startsWith("divide ",toParse)){
		char perftDepthParameter = toParse[7];
		int perftDepth = Character::getNumericValue(perftDepthParameter);
		MoveGenerator mg;
		vector<Move> moves = mg.generateLegalMoves(p);
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
		cout << "readyok" << endl << flush;
	}else if (toParse == "eval"){
		int v = Evaluator::getValue(p);
		cout << "Value: " << v << endl;
	}else if (startsWith("go", toParse)){
		stopBrain();
		int wtime = extractIntValue(toParse, "wtime");
		int btime = extractIntValue(toParse, "btime");
		int winc = extractIntValue(toParse, "winc");
		int binc = extractIntValue(toParse, "binc");
		int mtg = extractIntValue(toParse, "movestogo");
		int movetime = extractIntValue(toParse, "movetime");
		int depth = extractIntValue(toParse, "depth");
		if (mtg == 0){
			mtg = 25;
		}
		s.maxIdDepth = (depth > 0) ? depth : 64;

		long tpm;
		if (movetime > 0) {
			tpm = max(5L, static_cast<long>(movetime) - 15L);
		} else if (toParse.find("infinite") != string::npos) {
			tpm = -1L;
		} else if (wtime == 0 && btime == 0 && winc == 0 && binc == 0 && depth > 0) {
			tpm = -1L;
		} else if (p.onMove) {
			tpm = calculateTimePerMove(wtime, winc, mtg);
		} else {
			tpm = calculateTimePerMove(btime, binc, mtg);
		}
		timePerMove = tpm;

		startBrain();
	}else if (startsWith("stop", toParse)){
		stopBrain();
	}else if (startsWith("quit", toParse)){
		stopBrain();
		exit(0);
	}else if (startsWith("position", toParse)){
		stopBrain();
		p.clear();
		string positionString = extractPosition(toParse);
		if (startsWith("startpos",positionString)) {
			p.setToStart();
		}else if (startsWith("fen",positionString)){
			string positionFen = extractFen(positionString);
			p.setFenPosition(positionFen);
		}
		s.gameHistory.clear();
		s.gameHistory.push_back(p.getHash());
		string movesString =extractMoves(toParse);
		vector<string> moves = split(movesString,' ');
		if ((movesString != "") && (moves.size() != 0))
		{
			for (string move:moves) {
				if (!move.empty()) {
					Move parsed(move);
					bool irreducible = (abs(p.board[parsed.from]) == 1) || (p.board[parsed.to] != 0);
					p.makeMove(move);
					if (irreducible) {
						s.gameHistory.clear();
					}
					s.gameHistory.push_back(p.getHash());
				}
			}
		}
	}else if (toParse == "sp"){	
		p.print();
	}else if (toParse == "sm"){			
		cout << "Moves: " << endl;
		MoveGenerator mg;
		vector<Move> moves =mg.generateLegalMoves(p);
		for (Move move:moves){
			move.print();
		}
	}else {
		// Ignore unknown UCI commands silently
	}
}	 
int decodePiece(string promotedTo) {
	int retValue = 0;
	if (promotedTo=="q" || promotedTo=="Q") {
		retValue = 5;
	} else if (promotedTo=="r" || promotedTo=="R") {
		retValue = 4;
	} else if (promotedTo=="b" || promotedTo=="B") {
		retValue = 3;
	} else if (promotedTo=="n" || promotedTo=="N") {
		retValue = 2;
	}
	return retValue;
}

int main()
{
	p.clear();
	p.setToStart();
	cout << "Welcome to Arcadia, a chess engine by Nicolai Czempin. This is version "<< VERSION << endl << flush;
	string mystr;
	while (getline (cin, mystr)){
		if (!mystr.empty() && mystr.back() == '\r') {
			mystr.pop_back();
		}
		if (mystr.empty()) {
			continue;
		}
		parse(mystr);
	}
	stopBrain();
	return 0;
}
