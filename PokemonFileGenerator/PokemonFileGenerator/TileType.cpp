#include "TileType.h"
#include <iostream>
#include <string>
#include "Helper.h"
#include <fstream>



	//TODO maybe add trainer sight radius, will see how it turns out


	//MAYBE change this structure to simply a vector of strings and add more functions when its necasery 
TileType::TileType(){
	name = "";
	passable = 0;
	surfable = 0;
	doorway = 0;
	talkable = 0;
	pushable = 0;
	cutable = 0;
	location = 0;
	npcID = 0;
	tileset = "";
	}

void TileType::setName(std::string name){ this->name = name; }

void TileType::setPassable(int passable){ this->passable = passable; }

void TileType::setSurfable(int surfable){ this->surfable = surfable; }

void TileType::setDoorway(int doorway){ this->doorway = doorway; }

void TileType::setTalkable(int talkable){ this->talkable = talkable; }

void TileType::setPushable(int pushable){ this->pushable = pushable; }

void TileType::setCutable(int cutable){ this->cutable = cutable; }

void TileType::setLocation(int location){
	if (doorway){ this->location = location; }
}

void TileType::setPerson(int person){
	if (talkable){ npcID = person; }
}

void TileType::setTileset(std::string tileset){ this->tileset = tileset; }

void TileType::setAll(std::string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, std::string tileset){
	setName(name);
	setPassable(passable);
	setSurfable(surfable);
	setDoorway(doorway);
	setTalkable(talkable);
	setPushable(pushable);
	setCutable(cutable);
	setLocation(location);
	setPerson(person);
	setTileset(tileset);
}

//Maybe make able to add new paramaters easily
void TileType::setAll(std::vector<std::string> par){
	int pars [Helper::tilePars];
	for (int i = 1; i < 9; i++){
		pars[i - 1] = atoi(par[i].c_str());
	}

	setAll(par[0], pars[0], pars[1], pars[2], pars[3], pars[4], pars[5], pars[6], pars[7], par[9]);
}
std::string TileType::getName(){ return name; }

bool TileType::getPassable(){ return passable; }

bool TileType::getSurfable(){ return surfable; }

bool TileType::getDoorway(){ return doorway; }

bool TileType::getTalkable(){ return talkable; }

bool TileType::getPushable(){ return pushable; }

bool TileType::getCutable(){ return cutable; }

int TileType::getLocation(){
	if (doorway){ return location; 
	} else {
		//some sort of logging
		return 0;
	}
}

int TileType::getPerson(){
	if (talkable){ return npcID; 
	} else {
		//some sort of logging
		return 0;
	}
}

std::string TileType::getTileset(){ return tileset; }

std::vector <std::string> TileType::getAll(){
	std::vector <std::string> output{ getName(), std::to_string(getPassable()), std::to_string(getSurfable()), std::to_string(getDoorway()),
		std::to_string(getTalkable()), std::to_string(getPushable()), std::to_string(getCutable()), std::to_string(getLocation()),
		std::to_string(getPerson()), getTileset() };
	return output;
}

