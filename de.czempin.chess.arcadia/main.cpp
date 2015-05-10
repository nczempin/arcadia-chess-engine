//  main.cpp


#include <iostream>
#include <string>

#include "Position.h"
#include "MoveGenerator.h"
using namespace std;


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
		}else if (mystr == ""){
			cout << "Moves: " << endl;
			Position p = Position();
			p.board[11] = 6;
			p.onMove = true;
			MoveGenerator mg;
			mg.generateAllMoves(p);
		}
	}
	return 0;
}

