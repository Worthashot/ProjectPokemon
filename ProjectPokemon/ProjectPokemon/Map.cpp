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

void Map::setSpace(int xCord, int yCord, TileType setSpace){	//sets a specific co-ordinate
	mapComp[xCord][yCord] = setSpace; }

void Map::setSpaces(int size, int * xCord, int * yCord, TileType * spaces){	//sets a list of co-ordiantes
	for (int i = 0; i < size; i++){
		setSpace(*xCord++, *yCord++, *spaces++); 
	}
}

void Map::setEncounterCode(int encounter){ encounterCode = encounter; }

void Map::addTile(string name, TileType tile){
	customTiles.insert(pair<string, TileType>(name, tile));
}
	
