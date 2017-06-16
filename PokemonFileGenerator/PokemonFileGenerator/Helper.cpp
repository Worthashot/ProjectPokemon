#include "Helper.h"

//functions shamelessly copied from stackoverflow comments
std::vector<std::string> Helper::split(const std::string &text, char sep) {
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
void Helper::ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		not1(std::ptr_fun<int, int>(isspace))));
}

// trim from end (in place)
void Helper::rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
}

// trim from both ends (in place)
void Helper::trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

bool Helper::doesFileExist(std::string fileName)
{
	std::ifstream infile(fileName);
	bool output = infile.good();
	infile.close();
	return output;
}

/*
//This may be pointless
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
*/

bool Helper::isNumber(std::string line){
	Helper::trim(line);
	int iLine = atoi(line.c_str());
	if (iLine == 0 && line != "0"){
		return false;
	}
	return true;
}


int Helper::toInt(std::string s){
	trim(s);
	return  std::atoi(s.c_str());
}

std::vector<int> Helper::toInt(std::vector<std::string> s){
	std::vector<int> output;
	for (std::vector<std::string>::iterator it = s.begin(); it != s.end(); ++it) {
		output.push_back(toInt(*it));
	}
	return output;
}

