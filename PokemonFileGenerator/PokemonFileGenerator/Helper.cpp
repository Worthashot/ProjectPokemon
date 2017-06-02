#include "Helper.h"

Helper::Helper()
{
}

//functions shamelessly copied from stackoverflow comments
std::vector<std::string> split(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

// trim from start (in place)
void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		not1(std::ptr_fun<int, int>(isspace))));
}

// trim from end (in place)
void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

bool doesFileExist(std::string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

bool isNumber(std::string line, int* tileCount){
	Helper::trim(line);
	int iLine = atoi(line.c_str());
	if (iLine == 0 && line != "0"){
		tileCount = NULL;

		return false;
	}
	*tileCount = iLine;
	return true;
}

bool isNumber(std::string line){
	Helper::trim(line);
	int iLine = atoi(line.c_str());
	if (iLine == 0 && line != "0"){
		return false;
	}
	return true;
}