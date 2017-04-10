#include "Helper.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

Helper::Helper()
{
}

vector<string> Helper::split(string const& input) {
	std::istringstream buffer(input);
	std::vector<std::string> ret;

	std::copy(std::istream_iterator<std::string>(buffer),
		std::istream_iterator<std::string>(),
		std::back_inserter(ret));
	return ret;
}

Helper::~Helper()
{
}
