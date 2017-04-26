#pragma once
#include<string>
#include<vector>
using namespace std;

class Helper
{
public:
	Helper();
	static vector<string> split(const string&, char);
	static const int tilePars = 10;
};

