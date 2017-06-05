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
			maps[line] = Map(location + line);
		}
	}
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


