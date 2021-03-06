#include "MapList.h"

MapList::MapList(){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);

	directory = dir + "\\ProjectPokemon\\Debug\\Maps\\";

	maps.clear();
	mapNames.clear();

	_mkdir(directory.c_str());

	if (Helper::doesFileExist(directory + "header.txt")){
		initiateList("header.txt");
	}
}

MapList::MapList(std::string directory){
	this->directory = directory;
	maps.clear();
	mapNames.clear();

	if (Helper::doesFileExist(directory  +  "header.txt")){
		initiateList("header.txt");
	}
}

void MapList::initiateList(std::string headerName){

	std::ifstream header(directory + headerName);
	if (!header.is_open()){
		std::cerr << "cannot open file " + headerName;
		throw("cannot open file");
	}

	int i = 0;
	for (std::string line; getline(header, line);){
		mapNames.push_back(line);
		i++;
	}

	if (!mapNames.empty()){
		//the first name will dictate what maps are loaded. Ie, this one and all adjecent 
		std::deque<std::string> queue;
		if (loadMap(mapNames[0], queue)){
			loadAdjacentMaps();
		}
		else {
			std::cerr << "given map name " + mapNames[0] + " does not exist";
			throw("given map name does not exist");
		}
	}
	header.close();
}

bool MapList::loadMap(std::string fileName, std::deque<std::string> &queue){
	if (!testMap(fileName)){
		queue.clear();
		return false;
	}

	std::ifstream file;
	file.open(directory + fileName + ".txt");

	if (!file.is_open()){
		return false;
	}

	else {

		std::string line;
		getline(file, line);
		int dimensions[2];

		//the first line will contain the x and y co-ordinates of the map
		std::vector<std::string> dims = Helper::split(line, ' ');
		queue.push_back(line);
		dimensions[0] = Helper::toInt(dims[0]);
		dimensions[1] = Helper::toInt(dims[1]);

		//second line contains the number of custom tiles
		getline(file, line);
		int numberOfCustomTileTypes = atoi(line.c_str());
		queue.push_back(line);

		//next c lines contains the paramaters to a new tiletype
		for (int i = 0; i < numberOfCustomTileTypes; i++){
			getline(file, line);
			queue.push_back(line);
		}

		//the next y-dimension number of lines will contain an x-dimension number of tile codes
		for (int i = 0; i < dimensions[1]; i++){
			getline(file, line);
			std::vector<std::string> tiles = Helper::split(line, ' ');
			queue.push_back(line);
		}
	}
	file.close();
	return true;
}

void MapList::loadMaps(std::vector<std::string> mapsToLoad){
	int size = mapsToLoad.size();

	//find and delete all no longer necacerry maps
	std::map<std::string, Map>::iterator itr = maps.begin();
	while (itr != maps.end()) {
		if (std::find(mapsToLoad.begin(), mapsToLoad.end(), itr->first) == mapsToLoad.end()){
			maps.erase(itr++);  // <--- Note the post-increment!
		}
		else {
			++itr;
		}
	}

	//load in all new maps
	for (int i = 0; i < size; i++){
		if (maps.find(mapsToLoad[i]) == maps.end()){
			std::deque<std::string> queue;
			if (loadMap(mapsToLoad[i], queue)){
				Map mapToInsert = Map(queue);
				maps.insert(std::pair<std::string, Map>(mapsToLoad[i], mapToInsert));
			}
		}
	}
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
		return false;
	}

	std::ifstream map(directory + mapName + ".txt");

	if (!map.is_open()){
		return false;
	}

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
	lineVector = Helper::split(line, ' ');

	if (!Helper::isNumber(line)){
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

	//should be at the end of the file
	if (!map.eof()){
		return false;
	}
	map.close();
	return true;
	//TODO add test for more information when added
}

Map* MapList::getMap(std::string map){
	if (find(mapNames.begin(), mapNames.end(), map) == mapNames.end()){
		return NULL;
	}
	return &maps[map];
}

std::string MapList::getNames(){
	std::string output = "";
	for (int i = 0; i < mapNames.size(); i++){
		output = output + mapNames[i];
		if (i + 1 != mapNames.size()){
			output = output + " ";
		}
	}
	return output;
}

std::string MapList::getDirectory(){
	return directory;
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

	if (Helper::toInt(lineVector[0]) <= 0 || Helper::toInt(lineVector[1]) <= 0){
		return false;
	}

	return true;
}

Map MapList::generateMap(std::string fileName){
	std::deque<std::string> queue;
	loadMap(fileName, queue);
	Map output = Map(queue);
	return output;
}

int MapList::mapCount(){
	return maps.size();
}

std::vector<std::string> MapList::listOfMaps(){
	return mapNames;
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

std::vector<std::string> MapList::listOfLoadedMaps(){
	std::vector<std::string> output;
	for (std::map<std::string, Map>::iterator i = maps.begin(); i != maps.end(); i++){
		output.push_back(i->first);
	}
	return output;
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


