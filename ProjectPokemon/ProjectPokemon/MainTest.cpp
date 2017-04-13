#pragma once
#include "mapList.h"
#include <iostream>
int main(){
	UsefulTypes usefulTypes;
	MapList();
	std::string name = usefulTypes.getBase().getName();
	std::cout << "tile is not recognised as NPC, cannot assign ID. \n" + name;
	std::cin >> name;
}
