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
	if ((t == 0L) && (inc == 0L))
		return -1L; //TODO Exception?
	int slice = movesToGo + 1;
	long retVal = (t - inc) / slice + inc - 500L;
	if (retVal < 100L)
		retVal = 100L;
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
	//return false;
	auto now = chrono::system_clock::now(); 
	chrono::duration<double> elapsed_seconds = now-Info::start; 
	return elapsed_seconds.count() >= timePerMove/1000.0;
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
	//cout << "info string after fut.get" << endl;
	cout << "bestmove " << bestmove.toString() << endl;
	return bestmove;
}

void stopBrain()
{
	s.done = true; // ask the thread to finish
	fut.get(); //wait until the thread is finished

	//if ((brainThread != null) && (brainThread.isAlive())) {
	//	String move = this.brain.getBestMoveSoFar();
	//	String toPrint; if (move == null) {
	//		toPrint = printMove(null);
	//	} else
	//		toPrint = printMove(move);
	//	System.out.println(toPrint);
	//	brainThread.stop();
	//}
	//if ((printInfoThread != null) && (printInfoThread.isAlive()))
	//	printInfoThread.stop();
}
void printInfo(){
	while(!s.done){
		s.printInfo();
		this_thread::sleep_for (chrono::seconds(1));
	}
}
void startBrain() {
	//stopBrain(false);

	fut = async(asyncAnalyze);
	//async(printInfo);
	//	this_thread::sleep_for (chrono::seconds(10));
	//Move bestMoveSoFar = s.bestMove;
	//cout << "best move so far " << bestMoveSoFar.toString() << endl;
	//this_thread::sleep_for (chrono::seconds(10));
	//Move move = fut.get();
	//cout << "info string after fut.get" << endl;
	//cout << "bestmove " << move.toString() << endl;

	/*printInfoThread = new Thread()
	{
	public void run() {
	while (AbstractEngine.brainThread.isAlive()) {
	Options.protocol.printInfo();
	try {
	Thread.sleep(1000L);
	} catch (InterruptedException e) {
	e.printStackTrace();
	}

	}

	}


	};*/
	//printInfoThread.start();
}


int extractIntValue(string parameters, string s){
	size_t index = parameters.find(s);
	if (index == string::npos) {
		return 0;
	}
	size_t searchFrom = index + s.length() + 1;
	string extracted = parameters.substr(searchFrom);
	string first = split(extracted,' ')[0];
	return stoi(extracted);
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
		cout << "uciok" << endl;
	}else if (startsWith("perft ",toParse)){
		char perftDepthParameter = toParse[6];//'4'; //TODO extract from toParse
		int perftDepth = Character::getNumericValue(perftDepthParameter);

		chrono::time_point<chrono::system_clock> end;


		//TODO do this more elegantly
		for (int i = 0; i< perftDepth; ++i){
			Info::start = chrono::system_clock::now();
			int nodes = perft (p, i+1);
			end = chrono::system_clock::now();
			chrono::duration<double> elapsed_seconds = end-Info::start;
			cout << i+1 << ", " << nodes << " @ "  << elapsed_seconds.count()<<endl;
			//time_t end_time = chrono::system_clock::to_time_t(end);
		}
		cout << "Done." << endl;

	}else if (startsWith("divide ",toParse)){
		char perftDepthParameter = toParse[7];
		int perftDepth = Character::getNumericValue(perftDepthParameter);
		//TODO do this more elegantly
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
		cout << "readyok" << endl;
	}else if (toParse == "eval"){
		int v = Evaluator::getValue(p);
		cout << "Value: " << v << endl;
	}else if (startsWith("go", toParse)){
		int wtime = extractIntValue(toParse, "wtime");
		int btime = extractIntValue(toParse, "btime");
		int winc = extractIntValue(toParse, "winc");
		int binc = extractIntValue(toParse, "binc");
		int mtg = extractIntValue(toParse, "movestogo");
		if (mtg == 0){
			mtg = 25;
		}

		long tpm;
		if (p.onMove) {
			tpm = calculateTimePerMove(wtime,winc,mtg);
		} else {
			tpm = calculateTimePerMove(btime, binc,mtg);
		}
		timePerMove = tpm;


		/*    this.engine.setMovesToGo(mtg);
		this.engine.setTimes(wtime, btime, winc, binc);
		int depth = extractIntValue(parameters, "depth");
		this.engine.setDepth(depth);*/
		startBrain();
	}else if (startsWith("stop", toParse)){
		stopBrain();
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
				//p.print();
				//cout << "making move: "<<move<<endl;
				p.makeMove(move);
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
	string mystr;
	while (true){
		getline (cin, mystr);
		parse(mystr);
	}
	return 0;
}
