#pragma once

class Move{
public:
	Move(int from, int to){}
	Move(int from, int to, int promoted, int captured){}
	Move(int from, int to, int promoted){}
	Move(){}
};