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
	int i = 0;
	int c = atoi(line.c_str());
	while (i < c){
		getline(file, line);
		Helper::split(line, ' ');
		//TODO use line of paramaters to create the custom tile tipes for this map
	}
}

//first lookup header file. This tells the number of maps and their names.
//lookup the map with that code, create the tiles located at the start of the file then create the map useing these tiles
//frst draft file format
//first line - number of custom tiles
//each custom tile peramater will be seperated by a space and assigned a number, each tile will be seperated by a newline
//after custom tiles, the next line will give dimentions of the map x*y
//the next y lines will have x numbers. These corespond to the tiles id assigned previously. Each tile will be seperated by a space

//TODO put npcs, npc vision, encounters and others



//TODO find way to parse String into specified TileType, write python script to generate map into text and import text into program.



