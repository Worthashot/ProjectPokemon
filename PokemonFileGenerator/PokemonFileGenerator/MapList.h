#pragma once
#include "Map.h"
#include <windows.h>
#include <stdio.h>
#include <direct.h>

class MapList

{
private:

	//A map of each currently loaded Map with their respective name 
	std::map<std::string, Map> maps; 

	//A vector of all Maps able to be loaded
	std::vector<std::string> mapNames;

	//The file location of all stored maps. All maps in the same MapList must be in the same directory
	std::string directory;


public:

	//Finds all valid maps from the header at the expected location
	MapList();

	//Finds all valid maps from the header at a given location
	MapList(std::string);

	//using the given file name as a base, loads in all maps specified by that file
	void initiateList(std::string);

	//loads the given address to the deck and checks that it's a valid map
	bool loadMap(std::string, std::deque<std::string>&);

	//loads the given list of maps
	void loadMaps(std::vector<std::string>);

	//TODO loads the given and any adjacent maps
	void loadAdjacentMaps(Map);

	//TEMP, loads all maps
	void loadAdjacentMaps();

	//given the name of a map, searches for a file with that name in the directory and tests that its the correct form
	bool testMap(std::string);

	//returns the Map assigned to the given string
	Map* getMap(std::string);

	//returns a list of all loaded maps
	std::string getNames();

	//returns the directory
	std::string getDirectory();

	//tests if a string is a valid 
	bool testDimention(std::string);

	//returns a Map loaded from the given name at the MapList directory
	Map generateMap(std::string);

	//returns the number of stored Maps
	int mapCount();

	//returns a list of currently loaded maps
	std::vector<std::string> listOfMaps();

	//tests the format of a given string
	bool testValidTileType(std::string);

	std::vector<std::string> listOfLoadedMaps();

};

