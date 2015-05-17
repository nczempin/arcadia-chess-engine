#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
const string VERSION = "0.0.1dev";
vector<string> &split(const string &s, char delim, vector<string> &elems);

vector<string> split(const string &s, char delim);

bool invalidSquare(int next);

bool convertColor(int piece);