#include "Map.h"
#include "UsefulTypes.h"
#include "TileType.h"
#include <iostream>
#include <string>
#include <vector>
#include "Helper.h"
#include <map>
using namespace std;

Map::Map(){
}

Map::Map(int xDim, int yDim){	//sets the size of the map and allocates an unpassable wall as defalt
	ut = UsefulTypes();
	mapComp.resize(xDim);
	for (int i = 0; i < xDim; i++){
		mapComp[i].resize(yDim);
		for (int j = 0; j < yDim; j++){
			mapComp[i][j] = ut.getWall(); 
		}		
	}
}

Map::Map(int xDim, int yDim, int encounter){	//sets the size of the map and allocates an unpassable wall as defalt and the encounter code
	setEncounterCode(encounter);
	ut = UsefulTypes();
	mapComp.resize(xDim);
	for (int i = 0; i < xDim; i++){
		mapComp[i].resize(yDim);
		for (int j = 0; j < yDim; j++){
			mapComp[i][j] = ut.getWall();
		}
	}
}

void Map::setSpace(int xCord, int yCord, string setSpace){	//sets a specific co-ordinate
	mapComp[xCord][yCord] = customTiles[setSpace];
}

//sets all the spaces for a given x co-ordinate
void Map::setSpaces(int  xCord, vector<string> spaces){	
	for (int i = 0; i < spaces.size(); i++){
		setSpace(xCord, i, spaces[i]); 
	}
}

void Map::setEncounterCode(int encounter){ encounterCode = encounter; }

void Map::addTile(string name, TileType tile){
	customTiles.insert(pair<string, TileType>(name, tile));
}
	
