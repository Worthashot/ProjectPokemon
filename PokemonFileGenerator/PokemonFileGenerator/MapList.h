#pragma once#include <map>
#include "Map.h"
#include "Helper.h"
#include <string>
#include <vector>
class MapList
{
private:

	//A map of each currently loaded Map with their respective name 
	std::map<std::string, Map> maps; 

	//A vector of all Maps able to be loaded
	std::vector<std::string> mapNames;

	//The file location of all stored maps
	std::string location;


public:

	//Finds all valid maps from the header at the expected location
	MapList();

	//Finds all valid maps from the header at a given location
	MapList(std::string);

	//returns the Map assigned to the given string
	Map getMap(std::string);

	//loads the given list of maps
	void loadMaps(std::vector<std::string>);

	//loads the given address to the deck and checks that it's a valid map
	void loadMap(std::string, std::deque<std::string>&);

	//returns the number of stored Maps
	int mapCount();

	//returns a list of currently loaded maps
	std::vector<std::string> listOfMaps();

	//tests the format of a given string
	bool testValidTileType(std::string);

	//loads the given and any adjacent maps
	void loadAdjacentMaps(Map);
};

