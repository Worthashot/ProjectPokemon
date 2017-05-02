#include "Helper.h"
using namespace std;

Helper::Helper()
{
}

//functions shamelessly copied from stackoverflow comments
vector<string> Helper::split(const string &text, char sep) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

// trim from start (in place)
void ltrim(string &s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(),
		not1(ptr_fun<int, int>(isspace))));
}

// trim from end (in place)
void rtrim(string &s) {
	s.erase(find_if(s.rbegin(), s.rend(),
		not1(ptr_fun<int, int>(isspace))).base(), s.end());
}

// trim from both ends (in place)
void trim(string &s) {
	ltrim(s);
	rtrim(s);
}

bool doesFileExist(string fileName)
{
	ifstream infile(fileName);
	return infile.good();
}
