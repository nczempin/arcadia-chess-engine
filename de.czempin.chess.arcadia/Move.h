#pragma once
#include <iostream>

using namespace std;

class Move{
public:
	Move(int from, int to){
		this->from = from;
		this->to = to;
	}
	Move(int from, int to, int promoted, int captured){}
	Move(int from, int to, int promoted){}
	Move(){}
	void print(){
		cout << this->from << "-" << this->to << endl;
	}
private:
	int from;
	int to;
};