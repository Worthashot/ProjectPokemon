#pragma once#include <map>
#include "Map.h"
#include "Helper.h"
#include <string>
class MapList
{
private:

	//A map of each Map with their respective name
	std::map<std::string, Map> maps; 

public:

	//creates a list of maps from the expected header location
	MapList();

	//creates a list of maps from the given header location
	MapList(std::string);

	//returns the Map assigned to the given string
	Map getMap(std::string);

	//returns the number of stored Maps
	int mapCount();

	//returns a list of names of the stores Maps
	std::vector<std::string> listOfMaps();
};

