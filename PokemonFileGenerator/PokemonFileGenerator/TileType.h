#pragma once
#include "Helper.h"

class TileType
{
private:
	std::string name;
	bool passable;		 //can tile be walked through normaly
	bool surfable;
	bool doorway;
	bool talkable;		 //is tile an npc
	bool pushable;       //can tile be infulenced by strength
	bool cutable;
	int location;  //these are only assigned when appropriate flags are true
	int npcID;
	std::string tileset;
	
public:
	const int tilePars = 10;
	TileType();
	void setAll(std::string, int, int, int, int, int, int, int, int, std::string);
	void setAll(std::vector<std::string>);
	void setName(std::string name);
	void setPassable(int passable);
	void setSurfable(int surfable);
	void setDoorway(int doorway);
	void setTalkable(int talkable);
	void setPushable(int pushable);
	void setCutable(int cutable);
	void setLocation(int location);
	void setPerson(int person);
	void setTileset(std::string tileset);
	std::string getName();
	bool getPassable();
	bool getSurfable();
	bool getDoorway();
	bool getTalkable();
	bool getPushable();
	bool getCutable();
	int getLocation();
	int getPerson();
	std::string getTileset();
	std::vector<std::string> getAll();
	bool testValidTileType(std::string);

};

