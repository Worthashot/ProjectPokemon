#include "TileType.h"
#include <iostream>
#include <string>
#include "Helper.h"
using namespace std;


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
	doorwayLocation = 0;
	npcID = 0;
	tileset = "";
	}

void TileType::setName(string name){ this->name = name; }

void TileType::setPass(int passable){ this->passable = passable; }

void TileType::setSurf(int surfable){ this->surfable = surfable; }

void TileType::setDoor(int doorway){ this->doorway = doorway; }

void TileType::setTalk(int talkable){ this->talkable = talkable; }

void TileType::setPush(int pushable){ this->pushable = pushable; }

void TileType::setCut(int cutable){ this->cutable = cutable; }

void TileType::setDoorway(int location){
	if (doorway){ doorwayLocation = location; }
}

void TileType::setIdentity(int person){
	if (talkable){ npcID = person; }
}

void TileType::setTileset(string tileset){ this->tileset; }

void TileType::setAll(string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, string tileset){
	setName(name);
	setPass(passable);
	setSurf(surfable);
	setDoor(doorway);
	setTalk(talkable);
	setPush(pushable);
	setCut(cutable);
	setDoorway(location);
	setIdentity(person);
	setTileset(tileset);
}

void TileType::setAll(vector<string> par){
	int pars [Helper::tilePars - 1];
	for (int i = 1; i < 9; i++){
		pars[i - 1] = atoi(par[i].c_str());
	}

	setAll(par[0], pars[0], pars[1], pars[2], pars[3], pars[4], pars[5], pars[6], pars[7], par[9]);
}
std::string TileType::getName(){ return name; }

bool TileType::getPass(){ return passable; }

bool TileType::getSurf(){ return surfable; }

bool TileType::getDoor(){ return doorway; }

bool TileType::getTalk(){ return talkable; }

bool TileType::getPush(){ return pushable; }

int TileType::getDestination(){
	if (doorway){ return doorwayLocation; 
	} else {
		cout << "tile is not recognised as doorway, cannot return ID. " ; 
		return 0;
	}
}

int TileType::getPerson(){
	if (talkable){ return npcID; 
	} else {
		cout << "tile is not recognised as npc, cannot return ID. "; 
		return 0;
	}
}

string TileType::getTileset(){ return tileset; }
