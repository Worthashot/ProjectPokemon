#pragma once#include <map>
#include "Map.h"
#include "Helper.h"

class MapList
{
private:
	map<string, Map> maps; // A list of maps
	Map readMap(string);

public:
	MapList();
};

