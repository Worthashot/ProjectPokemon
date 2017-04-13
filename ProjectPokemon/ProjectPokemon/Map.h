#pragma once
#include <vector>
#include "TileType.h"
#include "UsefulTypes.h"
#include <map>
using namespace std;
class Map
{

private:
	std::vector<std::vector<TileType> >  mapComp;
	UsefulTypes ut;
	int encounterCode;
	map<string, TileType> customTiles;
public:
	Map();
	Map(int xDim, int yDim);
	Map(int xDim, int yDim, int encounter);
	void setSpace(int xCord, int yCord, TileType setSpace);
	void setSpaces(int size, int * xCord, int * yCord, TileType * spaces);
	void setEncounterCode(int encounter);
	void addTile(string, TileType);
};

//TODO Add the relevent map properties such as tilesets, list of tileTypes ect