#include "MapList.h"
#include <windows.h>
#include <stdio.h>
#include "Map.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Helper.h"
#include <deque>

MapList::MapList(){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);
	location = dir + "\\ProjectPokemon\\Debug\\";
	std::ifstream header(location + "header.txt");

	if (!header.is_open()){
		std::cout << "no header found, creating\n";
		std::ofstream header(location + "header.txt");
		header.close();
		std::string a = location + "header.txt";
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
	}
}

MapList::MapList(std::string location){
	this->location = location;

}
Map MapList::getMap(std::string map){
	return maps[map];
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
			loadMap(location + mapsToLoad[i], queue);
			maps.insert(std::pair<std::string, Map>(mapsToLoad[i], Map(queue)));
		}
	}
}

void MapList::loadMap(std::string fileName, std::deque<std::string> &queue){
	std::ifstream file;
	file.open(location + fileName);
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
}

bool MapList::testValidTileType(std::string line){
	std::vector<std::string> pars = Helper::split(line, ' ');
	if (pars.size != 10){
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
void loadAdjacentMaps(Map currentMap){

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


