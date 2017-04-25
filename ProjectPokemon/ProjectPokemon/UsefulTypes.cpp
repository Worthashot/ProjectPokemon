//probably useless
/*
#include "UsefulTypes.h"
#include "TileType.h"
#include <iostream>
#include <string>
using namespace std;


void UsefulTypes::initilizeBase(){
	base.setName("Base");
	base.setPassable(1); 
}

void UsefulTypes::initilizeWall(){ 
	wall.setName("Wall"); 
}

void UsefulTypes::initilizeNpc(){
	npc.setName("NPC");
	npc.setTalkable(1);
}
void UsefulTypes::initilizeWater(){
	water.setName("Water");
	water.setSurfable(1); 
}

void UsefulTypes::initilizeTree(){
	tree.setName("Tree");
	tree.setCutable(1);
}
	
void UsefulTypes::initilizeDoor(){
	door.setName("Door");
	door.setDoorway(1);
}

UsefulTypes::UsefulTypes(){
	initilizeBase();
	initilizeWall();
	initilizeNpc();
	initilizeWater(); 
	initilizeTree();
	initilizeDoor();
}

TileType UsefulTypes::getBase(){
	return base; 
}

TileType UsefulTypes::getWall(){
	return wall; 
}

TileType UsefulTypes::getNpc(){
	return npc; 
}

TileType UsefulTypes::getNpc(int personId){
	TileType iNpc = npc;
	iNpc.setPerson(personId);
	iNpc.setName("IdentifiedNPC");
	return iNpc; 
}

TileType UsefulTypes::getWater(){
	return water; 
}
*/