#pragma once
#include<string>
#include<vector>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <fstream>
#include <deque>
#include <iostream>

class Helper
{
public:
	Helper();
	static std::vector<std::string> split(const std::string&, char);
	static const int tilePars = 10;
	static void ltrim(std::string);
	static void rtrim(std::string);
	static void trim(std::string);
	static bool doesFileExist(std::string);
	static bool isNumber(std::string, int*);
	static bool isNumber(std::string);
	static int toInt(std::string);
	static void readMap(std::string, std::deque<std::string>&);

};

