#pragma once#include <map>
#include "Map.h"
#include "Helper.h"
#include <string>
class MapList
{
private:
	map<string, Map> maps; // A list of maps
	Map readMap(string);
	void readTile(Map, string); //adds a tile type to the map given based on the string of paramaters given
public:
	MapList();
	~MapList();
};

