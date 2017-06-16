#include "MapList.h"

MapList::MapList(){
	std::cout << "MapList v 1 start\n";
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);
	directory = dir + "\\ProjectPokemon\\Debug\\";
	std::ifstream header(directory + "header.txt");

	if (!header.is_open()){
		std::cout << "no header found, creating\n";
		std::ofstream header(directory + "header.txt");
		header.close();
		std::string a = directory + "header.txt";
		std::rename(a.c_str(), "header.txt");
	}
	else {
		//every line will give the name of a map
		int i = 0;
		for (std::string line; getline(header, line);){
			mapNames[i] = line;
			i++;
		}		
		//the first name will dictate what maps are loaded. Ie, this one and all adjecent 
		std::deque<std::string> queue;
		loadMap(mapNames[0], queue);
		loadAdjacentMaps(Map(queue));
		std::cout << "MapList v 1 end\n";
	}
	header.close();
}

MapList::MapList(std::string directory){
	std::cout << "MapList v 2 start\n";
	this->directory = directory;
	
	std::ifstream header(directory + "header.txt");
	
	if (!header.is_open()){
		std::cout << "no header found, creating\n";
		std::ofstream header(directory + "header.txt");
		header.close();
		std::string a = directory + "header.txt";
		std::rename(a.c_str(), "header.txt");
	}
	else {
		
		//every line will give the name of a map
		int i = 0;
		for (std::string line; getline(header, line);){
			mapNames.push_back(line);
			i++;	
		}

		if (!mapNames.empty()){
			//the first name will dictate what maps are loaded. Ie, this one and all adjecent 
			std::deque<std::string> queue;
			loadMap(mapNames[0], queue);
			loadAdjacentMaps();
			std::cout << "MapList v 2 end\n";
		}
	}
}

Map* MapList::getMap(std::string map){
	if (find(mapNames.begin(), mapNames.end(), map) == mapNames.end()){
		return NULL;
	}
	
	return &maps[map];
}

int MapList::mapCount(){
	return maps.size();
}

std::vector<std::string> MapList::listOfMaps(){
	std::vector<std::string> output;
	for (std::map<std::string, Map>::iterator it = maps.begin(); it != maps.end(); ++it) {
		output.push_back(it->first);
	}
	return output;
}

std::string MapList::getNames(){
	std::string output = "";
	for (int i = 0; i < mapNames.size(); i++){
		output = output + mapNames[i];
	}
	return output;
}

void MapList::loadMaps(std::vector<std::string> mapsToLoad){
	int size = mapsToLoad.size();

	//find and delete all no longer necacerry maps
	for (std::map<std::string, Map>::iterator it=maps.begin(); it!=maps.end(); ++it){
		if (std::find(mapsToLoad.begin(), mapsToLoad.end(), it->first) == mapsToLoad.end()){
			maps.erase(it);
		}
	}

	//load in all new maps
	for (int i = 0; i < size; i++){
		if (maps.find(mapsToLoad[i]) == maps.end()){
			std::deque<std::string> queue;
			maps.insert(std::pair<std::string, Map>(mapsToLoad[i], generateMap(mapsToLoad[i])));
		}
	}
}

void MapList::loadMap(std::string fileName, std::deque<std::string> &queue){
	std::ifstream file;
	file.open(directory + fileName + ".txt");
	if (!file.is_open()){
		std::cerr << "Error opening file.";
		throw("Error opening file.");
	}
	else {
		
		std::string line;
		getline(file, line);
		int dimensions[2];

		//the first line will contain the x and y co-ordinates of the map
		std::vector<std::string> dims = Helper::split(line, ' ');
		if (dims.size() != 2 && Helper::isNumber(dims[0]) && Helper::isNumber(dims[1])){
			std::cerr << "first line of map " + fileName + " not expected dimension";
			throw("unable to load map dimensions");
		}
		queue.push_back(line);
		dimensions[0] = Helper::toInt(dims[0]);
		dimensions[1] = Helper::toInt(dims[1]);

		//second line contains the number of custom tiles
		getline(file, line);
		int c = atoi(line.c_str());
		if ((c == 0 && line != "0") || c < 0){
			std::cerr << "second line of map " + fileName + " not valid number";
			throw("unexpected paramater");
		}
		queue.push_back(line);

		//next c lines contains the paramaters to a new tiletype
		int i = 0;
		while (i < c){
			getline(file, line);
			if (!testValidTileType(line)){
				std::cerr << "Line number " + std::to_string(i + 2) + " of map " + fileName + " is not a valid TileType";
				throw("unable to load TileType");
			}
			queue.push_back(line);
			i++;
		}

		//the next y-dimension number of lines will contain an x-dimension number of tile codes
		for (int i = 0; i < dimensions[1]; i++){
			getline(file, line);
			std::vector<std::string> tiles = Helper::split(line, ' ');
			if (tiles.size() != dimensions[0]){
				std::cerr << "invalid map";
				throw("map size does not match expected size");
			}

			queue.push_back(line);
		}
	}
	file.close();
}

Map MapList::generateMap(std::string fileName){
	std::deque<std::string> queue;
	loadMap(fileName, queue);
	Map output = Map(queue);
	return output;
}

bool MapList::testValidTileType(std::string line){
	std::vector<std::string> pars = Helper::split(line, ' ');
	if (pars.size() != 10){
		return false;
	}
	for (int i = 1; i < 9; i++){
		if (!Helper::isNumber(pars[i])){
			return false;
		}
	}
	return true;
}

//TODO Add the adjecent map feild to Maps and implement this function
void MapList::loadAdjacentMaps(Map currentMap){

}
	
//TEMP loads all maps at once
void MapList::loadAdjacentMaps(){
	loadMaps(mapNames);
}

bool MapList::testMap(std::string mapName){
	if (!Helper::doesFileExist(directory + mapName + ".txt")){
		std::cerr << "map does not exist.\n";
		throw("Map does not exist");
		return false;
	}

	std::ifstream map(directory + ".txt");
	std::string line;
	std::vector < std::string > lineVector;
	int  tileCount;
	bool truth = true;
	std::vector<int> dims;
	//line should be 2 dimentional
	getline(map, line);
	if (!testDimention(line)){
		return false;
	}
	
	dims = Helper::toInt(Helper::split(line, ' '));

	//line should be number of custom TileTypes
	getline(map, line);
	if (Helper::isNumber(line)){
		return false;
	}
	tileCount = Helper::toInt(line);

	//each line should be a TileType
	for (int i = 0; i < tileCount; i++){
			getline(map, line);
			Helper::trim(line);
			if (!testValidTileType(line)){
				return false;
			}
		}

	//each line should be a set amount of strings seperated by spaces
	for (int i = 0; i < dims[1]; i++){
		getline(map, line);
		lineVector = Helper::split(line, ' ');
		if (lineVector.size() != dims[0]){
			return false;
		}
	}
	map.close();
	return true;
	//TODO add test for more information when added
}

bool MapList::testDimention(std::string line){

	std::vector < std::string > lineVector;
	lineVector = Helper::split(line, ' ');
	if (lineVector.size() != 2){
		return false;
	}

	Helper::trim(lineVector[0]);
	Helper::trim(lineVector[1]);
	if (!(Helper::isNumber(lineVector[0]) && Helper::isNumber(lineVector[1]))){
		return false;
	}
	return true;
}

std::string MapList::getDirectory(){
	return directory;
}
//first lookup header file. This tells the number of maps and their names.
//lookup the map with that code, create the tiles located at the start of the file then create the map useing these tiles

//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
//after the map, will give a number z of ajacent maps
//the next z lines will give the names of these maps

//TODO put npcs, npc vision, encounters and others


