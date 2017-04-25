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

//sets the size of the map and allocates an unpassable wall as defalt
Map::Map(int xDim, int yDim){	
	TileType wall = TileType();
	wall.setName("wall");
	addTile(wall);
	mapComp.resize(xDim);
	for (int i = 0; i < xDim; i++){
		mapComp[i].resize(yDim);
		for (int j = 0; j < yDim; j++){
			mapComp[i][j] = "wall"; 
		}		
	}
}

//sets the size of the map and allocates an unpassable wall as defalt and the encounter code
Map::Map(int xDim, int yDim, int encounter){	
	TileType wall = TileType();
	wall.setName("wall");
	addTile(wall);
	setEncounterCode(encounter);
	mapComp.resize(xDim);
	for (int i = 0; i < xDim; i++){
		mapComp[i].resize(yDim);
		for (int j = 0; j < yDim; j++){
			mapComp[i][j] = "wall";
		}
	}
}

void Map::setSpace(int xCord, int yCord, string setSpace){	//sets a specific co-ordinate
	if (customTiles.count(setSpace)){
		mapComp[xCord][yCord] = setSpace;
	}
	else{
		//keep as is, maybe throw error or log
	}
}

//sets all the spaces for a given x co-ordinate
void Map::setSpaces(int  xCord, vector<string> spaces){	
	for (int i = 0; i < spaces.size(); i++){
		if (customTiles.count(spaces[i])){
			mapComp[xCord][i] = spaces[i];
		}
		else {
			//keep as is, maybe throw error or log
		}
	}
}

void Map::setEncounterCode(int encounter){ encounterCode = encounter; }

void Map::addTile(TileType tile){
	customTiles.insert(pair<string, TileType>(tile.getName(), tile));
}
	
TileType Map::getTile(int x, int y){
	return customTiles[mapComp[x][y]];
}
