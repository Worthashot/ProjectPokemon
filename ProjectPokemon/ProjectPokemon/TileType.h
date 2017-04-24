#pragma once
#include <string>
#include <vector>
using namespace std;

class TileType
{
private:
	string name;
	bool passable;		 //can tile be walked through normaly
	bool surfable;
	bool doorway;
	bool talkable;		 //is tile an npc
	bool pushable;       //can tile be infulenced by strength
	bool cutable;
	int doorwayLocation;  //these are only assigned when appropriate flags are true
	int npcID;
	string tileset;

public:
	TileType();
	void setAll(string, int, int, int, int, int, int, int, int, string);
	void setAll(vector<string>);
	void setName(std::string name);
	void setPass(int passable);
	void setSurf(int surfable);
	void setDoor(int doorway);
	void setTalk(int talkable);
	void setPush(int pushable);
	void setCut(int cutable);
	void setDoorway(int location);
	void setIdentity(int person);
	void setTileset(std::string tileset);
	std::string getName();
	bool getPass();
	bool getSurf();
	bool getDoor();
	bool getTalk();
	bool getPush();
	int getDestination();
	int getPerson();
	std::string getTileset();
};

