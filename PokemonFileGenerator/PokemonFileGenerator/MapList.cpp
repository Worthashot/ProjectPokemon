#include "MapList.h"
#include <windows.h>
#include <stdio.h>
#include "Map.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Helper.h"


MapList::MapList(){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);
	std::string location = dir + "\\ProjectPokemon\\Debug\\";
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
		std::cout << "header found, loading maps\n";
		for (std::string line; getline(header, line);){
			std::cout << "loading " + line + "\n";
			maps[line] = readMap(location + line);
		}
	}
}

Map MapList::readMap(std::string map){
	std::ifstream file(map + ".txt");
	if (!file.is_open()) {
		std::cerr << "unable to open map " + map;
		throw("unable to open map");
	}
	std::string line;
	std::getline(file, line);
	int dimensions[2];
	
	//the first line will contain the x and y co-ordinates of the map
	std::vector<std::string> dims = Helper::split(line, ' ');
	if (dims.size() != 2){
		std::cerr << "first line of map " + map + " not expected dimension";
		throw("unable to load map dimensions");
	}

	dimensions[0] = atoi(dims[0].c_str());
	dimensions[1] = atoi(dims[1].c_str());
	Map output = Map(dimensions[0], dimensions[1]);
	
	int i = 0;

	//second line contains the number of custom tiles
	getline(file, line);
	int c = atoi(line.c_str());

	if ((c == 0 && line != "0") || c < 0){
		std::cerr << "second line of " + map + " not valid number";
		throw("unexpected paramater");
	}

	while (i < c){
		getline(file, line);
		//each line contains the paramaters to a new tiletype
		readTile(&output, line);
		i++;
	}

	for (int i = 0; i < dimensions[1]; i++){

		//next of the next y-dimension number of lines will contain an x-dimension number of tile codes
		getline(file, line);
		std::vector<std::string> tiles = Helper::split(line, ' ');
		if (tiles.size() != dimensions[0]){
			std::cerr << "invalid map";
			throw("map size does not match expected size");
		}

		//assigns all y co-ordinates for the current x co-ordinate
		output.setSpaces(i, tiles);
	}

	return output;
}
 
Map MapList::readMap(std::ifstream *map){
	std::string line;
	std::getline(*map, line);
	int dimensions[2];

	//the first line will contain the x and y co-ordinates of the map
	std::vector<std::string> dims = Helper::split(line, ' ');
	if (dims.size() != 2){
		std::cerr << "first line of map not expected dimension";
		throw("unable to load map dimensions");
	}

	dimensions[0] = atoi(dims[0].c_str());
	dimensions[1] = atoi(dims[1].c_str());
	Map output = Map(dimensions[0], dimensions[1]);

	int i = 0;

	//second line contains the number of custom tiles
	getline(*map, line);
	int c = atoi(line.c_str());

	if ((c == 0 && line != "0") || c < 0){
		std::cerr << "second line of not valid number";
		throw("unexpected paramater");
	}

	while (i < c){
		getline(*map, line);
		//each line contains the paramaters to a new tiletype
		readTile(&output, line);
		i++;
	}

	for (int i = 0; i < dimensions[1]; i++){

		//next of the next y-dimension number of lines will contain an x-dimension number of tile codes
		getline(*map, line);
		std::vector<std::string> tiles = Helper::split(line, ' ');
		if (tiles.size() != dimensions[0]){
			std::cerr << "invalid map";
			throw("map size does not match expected size");
		}

		//assigns all y co-ordinates for the current x co-ordinate
		output.setSpaces(i, tiles);
	}

	return output;
}

void MapList::readTile(Map *map, std::string par){
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

//first lookup header file. This tells the number of maps and their names.
//lookup the map with that code, create the tiles located at the start of the file then create the map useing these tiles

//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile

//TODO put npcs, npc vision, encounters and others


