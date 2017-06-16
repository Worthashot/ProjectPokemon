#pragma once
#include "TileType.h"
#include <map>

class Map
{

private:
	std::vector<std::vector<std::string> >  mapComp;
	int encounterCode;
	std::map<std::string, TileType> customTiles;
	
public:
	//TODO
	Map();

	//sets the size of the map and allocates an unpassable wall as defalt
	Map(int, int);

	//sets the size of the map from string and allocates an unpassable wall as default
	Map(std::string, std::string);

	//TODO
	Map(int, int, int);

	void setTile(std::string);
	//loads in a Map from file via the contance of that file
	Map(std::deque<std::string>);

	//Sets an individual x,y cordinate to the corresponding tileType specified by the String, checking that
	//the TileType is registerd in the Map
	void setSpace(int xCord, int yCord, std::string setSpace);

	//Applies setSpace to a row of cordinates
	void setSpaces(int xCord, std::vector<std::string> spaces);

	//TODO
	void setEncounterCode(int encounter);

	//Adds the given TileType to the avalible TileTypes for this map
	void addTile(TileType);

	//Gives the TileType assigned to the given cordinates
	TileType getTile(int, int);

	//returns the dimention of the map
	std::vector<int> getDimention();

	//returns a list of the names of the registerd TileTypes
	std::vector<std::string> getTiles();


	void readTile(Map*, std::string);
};

//TODO Add the relevent map properties such as tilesets, list of tileTypes ect