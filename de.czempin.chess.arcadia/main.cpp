//  main.cpp


#include <iostream>
#include <string>

#include "Position.h"
#include "MoveGenerator.h"
using namespace std;
bool startsWith(string smallString, string bigString){
	return bigString.compare(0, smallString.length(), smallString)==0;
}
Position p;
string extractPosition(string);
int main()
{
	cout << "Welcome to Arcadia, a chess engine by Nicolai Czempin. This is version 0.0.1" << endl;

	string mystr;
	while (true){
		getline (cin, mystr);
		if (mystr == "uci"){
			cout << "id name Arcadia 0.0.1RC"<< endl;
			cout << "id author Nicolai Czempin" << endl;
			cout << "uciok" << endl;
		}else if (mystr == "isready"){
			cout << "readyok" << endl;
		}else if (startsWith("position", mystr)){
			p.clear();
			string positionString = "TODO";//extractPosition(mystr);
			if (positionString =="startpos") {
				p.setToStart();
			}else if (startsWith("fen",positionString)){
				// String positionFen = extractFen(positionString);
				// this.brain.setFENPosition(positionFen);
				cout << "TODO: fen" << endl;
			}
		}else if (mystr == ""){			
			cout << "Moves: " << endl;
			p.setToStart();
			p.onMove = false;

			MoveGenerator mg;
			mg.generateAllMoves(p);
		}
	}
	return 0;
}

