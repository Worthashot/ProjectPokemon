#include "MapList.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Helper.h"

using namespace std;


MapList::MapList(){
	ifstream header("header.txt");

	if (!header.is_open()){
		cerr << "unable to open header";
		throw("unable to open header");
	}

	for (string line; getline(header, line);){
		maps.insert(pair<string, Map>(line, readMap(line)));
	}
}

Map MapList::readMap(string map){
	ifstream file(map + "txt");

	if (!file.is_open()) {
		cerr << "unable to open map";
		throw("unable to open map");
	}

	string line;
	getline(file, line);
	int dimensions[1];
	dimensions[0] = atoi(Helper::split(line, ' ')[0].c_str());
	dimensions[1] = atoi(Helper::split(line, ' ')[1].c_str());
	Map output = Map(dimensions[0], dimensions[1]);

	int i = 0;
	int c = atoi(line.c_str());
	while (i < c){
		getline(file, line);
		readTile(output, line);
	}

	for (int i = 0; i < dimensions[1]; i++){
		getline(file, line);
		vector<string> tiles = Helper::split(line, ' ');

		if (tiles.size() != dimensions[0]){
			cerr << "invalid map";
			throw("map size does not match expected size");
		}

		output.setSpaces(i, tiles);
	}

	return output;
}

void readTile(Map map, string par){
	vector<string> pars = Helper::split(par, ' ');
	if (pars.size() != Helper::tilePars){
		cerr << "invalid number of paramaters in map";
		throw("invalid number of paramarets");
	}
	TileType newType = TileType();
	newType.setAll(pars);
	map.addTile(pars[0], newType);
}
//first lookup header file. This tells the number of maps and their names.
//lookup the map with that code, create the tiles located at the start of the file then create the map useing these tiles
//frst draft file format
//first line - x*y co-ordinates separated by a space
//each custom tile peramater will be seperated by a space and assigned a number, each tile will be seperated by a newline
//after custom tiles, the next line will give dimentions of the map x*y
//the next y lines will have x numbers. These corespond to the tiles id assigned previously. Each tile will be seperated by a space

//TODO put npcs, npc vision, encounters and others



//TODO find way to parse String into specified TileType, write python script to generate map into text and import text into program.



