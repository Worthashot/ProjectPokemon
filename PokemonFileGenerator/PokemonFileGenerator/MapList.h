#pragma once#include <map>
#include "Map.h"
#include "Helper.h"
#include <string>
class MapList
{
private:
	std::map<std::string, Map> maps; // A list of maps
	Map readMap(std::string);

   //may be better in Map
	void static readTile(Map*, std::string); //adds a tile type to the map given based on the string of paramaters given
public:
	MapList();
	Map getMap(std::string);
	int mapCount();
	std::vector<std::string> listOfMaps();

	//may be better in Map
	//Also makes no sence, need to fix
	Map static readMap(std::ifstream *);
};

