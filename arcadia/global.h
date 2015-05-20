#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
const string VERSION = "0.0.4dev";
#define USE_UNDERPROMOTION
vector<string> &split(const string &s, char delim, vector<string> &elems);

vector<string> split(const string &s, char delim);

bool invalidSquare(int next);

bool convertColor(int piece);

string encodeSquare(int square);
int decodeSquare(string square);
int decodePiece(string promotedTo);
long calculateTimePerMove(long t, long inc, int movesToGo);
