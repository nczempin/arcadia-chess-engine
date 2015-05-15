#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems);

vector<string> split(const string &s, char delim);