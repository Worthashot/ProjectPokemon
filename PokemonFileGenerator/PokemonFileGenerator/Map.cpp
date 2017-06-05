#include "Map.h"
#include "TileType.h"
#include <iostream>
#include <string>
#include <vector>
#include "Helper.h"
#include <map>

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


void Map::setSpace(int xCord, int yCord, std::string setSpace){	//sets a specific co-ordinate
	if (customTiles.count(setSpace)){
		mapComp[xCord][yCord] = setSpace;
	}
	else{
		//keep as is, maybe throw error or log
	}
}

//sets all the spaces for a given x co-ordinate
void Map::setSpaces(int  xCord, std::vector<std::string> spaces){
	for (int i = 0; i < spaces.size(); i++){
		if (customTiles.count(spaces[i])){
			mapComp[xCord][i] = spaces[i];
		}
		else {
			std::cout << "tile not recognised\n";
			//keep as is, maybe throw error or log
		}
	}
}

void Map::setEncounterCode(int encounter){ encounterCode = encounter; }

void Map::addTile(TileType tile){
	customTiles.insert(std::pair<std::string, TileType>(tile.getName(), tile));
}
	
TileType Map::getTile(int x, int y){
	return customTiles[mapComp[x][y]];
}

int* Map::getDimention(){
	int output[2];
	output[0] = mapComp.size();
	output[1] = mapComp[0].size();
	return output;
}

std::vector<std::string> Map::getTiles(){
	std::vector<std::string> v;
	for (std::map<std::string, TileType>::iterator it = customTiles.begin(); it != customTiles.end(); ++it) {
		v.push_back(it->first);
	}
}

void Map::readTile(Map *map, std::string par){
	std::vector<std::string> pars = Helper::split(par, ' ');

	//expecting every par to have enough paramaters to create a new tiletype
	if (pars.size() != Helper::tilePars){
		std::cerr << "invalid number of paramaters in map";
		throw("invalid number of paramarets");
	}

	TileType newType = TileType();
	newType.setAll(pars);

	//adds a new tiletype to the map idendified by its name
	map->addTile(newType);
}

//BIG TODO - Create a container which all relevent information is read in to. this container will then be passed
//to a constructor http://www.cplusplus.com/reference/deque/deque/
Map::Map(std::string  locationString){
	std::ifstream map(locationString);
	if (!map.is_open()){

	}
	std::string line;
	getline(map, line);
	int dimensions[2];

	//the first line will contain the x and y co-ordinates of the map
	std::vector<std::string> dims = Helper::split(line, ' ');
	if (dims.size() != 2){
		std::cerr << "first line of map not expected dimension";
		throw("unable to load map dimensions");
	}

	dimensions[0] = std::atoi(dims[0].c_str());
	dimensions[1] = std::atoi(dims[1].c_str());
	Map output = Map(dimensions[0], dimensions[1]);

	int i = 0;

	//second line contains the number of custom tiles
	getline(map, line);
	int c = atoi(line.c_str());

	if ((c == 0 && line != "0") || c < 0){
		std::cerr << "second line of not valid number";
		throw("unexpected paramater");
	}

	while (i < c){
		getline(map, line);
		//each line contains the paramaters to a new tiletype
		readTile(&output, line);
		i++;
	}

	for (int i = 0; i < dimensions[1]; i++){

		//next of the next y-dimension number of lines will contain an x-dimension number of tile codes
		getline(map, line);
		std::vector<std::string> tiles = Helper::split(line, ' ');
		if (tiles.size() != dimensions[0]){
			std::cerr << "invalid map";
			throw("map size does not match expected size");
		}

		//assigns all y co-ordinates for the current x co-ordinate
		output.setSpaces(i, tiles);
	}
}
//I Think what I was going for was to relocate the creation of a map from file to the Map class from the map list class.
//This would allow for other methods to make their own isolated maps rather than being forced to use the rigid definition
//forced by the mapList