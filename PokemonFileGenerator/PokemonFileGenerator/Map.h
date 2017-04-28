#pragma once
#include <vector>
#include "TileType.h"
#include <map>
using namespace std;
class Map
{

private:
	std::vector<std::vector<string> >  mapComp;
	int encounterCode;
	map<string, TileType> customTiles;

public:
	Map();
	Map(int xDim, int yDim);
	Map(int xDim, int yDim, int encounter);
	void setSpace(int xCord, int yCord, string setSpace);
	void setSpaces(int xCord, vector<string> spaces);
	void setEncounterCode(int encounter);
	void addTile(TileType);
	TileType getTile(int, int);
};

//TODO Add the relevent map properties such as tilesets, list of tileTypes ect