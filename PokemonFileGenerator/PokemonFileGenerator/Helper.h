#pragma once
#include <string>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <fstream>
#include <deque>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <direct.h>

class Helper
{
public:
	static const int tilePars = 10;
	static std::vector<std::string> split(const std::string&, char);
	static void ltrim(std::string&);
	static void rtrim(std::string&);
	static void trim(std::string&);
	static bool doesFileExist(std::string);
	static void lower(std::string&);

	//checks if the sting is a valid number. If so, sets int* to that number. If not, sets int* to null.
	//static bool isNumber(std::string, int*)
	;
	static bool isNumber(std::string);
	static int toInt(std::string);
	static std::vector<int> toInt(std::vector<std::string> s);
	static std::string getDirectory();
};

