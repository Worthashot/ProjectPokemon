#include "Map.h"

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

//sets the size of the map from string and allocates an unpassable wall as defalt
Map::Map(std::string xDimS, std::string yDimS){
	int xDim = Helper::toInt(xDimS);
	int yDim = Helper::toInt(yDimS);
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
		std::cout << "tile not recognised\n";
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

std::vector<int> Map::getDimention(){
	std::vector<int> output;
	output[0] = mapComp.size();
	output[1] = mapComp[0].size();
	return output;
}

std::vector<std::string> Map::getTiles(){
	std::vector<std::string> v;
	for (std::map<std::string, TileType>::iterator it = customTiles.begin(); it != customTiles.end(); ++it) {
		v.push_back(it->first);
	}
	return v;
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

void Map::setTile(std::string par){
	std::vector<std::string> pars = Helper::split(par, ' ');

	//expecting every par to have enough paramaters to create a new tiletype
	if (pars.size() != Helper::tilePars){
		std::cerr << "invalid number of paramaters in map";
		throw("invalid number of paramarets");
	}

	TileType newType = TileType();
	newType.setAll(pars);
	addTile(newType);
}



//info is expected to be a deque containing all information from the relavent file
Map::Map(std::deque<std::string>  info) : Map(Helper::split(info[0], ' ')[0], Helper::split(info[0], ' ')[1]){
	//line 0 is used to construct the Map this constructor uses causing the real starting line to be 1
	int currentLine = 1;

	//line 1 contains the number of custom tiles
	int c = Helper::toInt(info[1]);
	int j = 1;
	for (int i = 2; i < c + 2; i++){

		//next c lines contains the paramaters to a new tiletype
		setTile(info[i]);
		currentLine = i;
	}

	currentLine++;
	for (int i = currentLine, j=0; i < currentLine + mapComp.size(); i++, j++){
		//each of the next y-dimension number of lines will contain an x-dimension number of tile codes
		//Will trow error if trying to assign a type not yet registerd to the Map
		std::vector<std::string> tiles = Helper::split(info[i], ' ');
		setSpaces(j, tiles);
	}
}