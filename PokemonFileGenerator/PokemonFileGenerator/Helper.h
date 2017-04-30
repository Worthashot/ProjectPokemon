#pragma once
#include<string>
#include<vector>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

class Helper
{
public:
	Helper();
	static vector<string> split(const string&, char);
	static const int tilePars = 10;
	static void ltrim(string);
	static void rtrim(string);
	static void trim(string);
};

