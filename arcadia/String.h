#pragma once
#include <string>
using namespace std;
class String{
public:
	string content;
	bool equals(String other){
		return (content == other.content);
	}
	bool equals(std::string other){
		return content == other;
	}
	char charAt(int position){
		char c = content[position];
		return c;
	}
};