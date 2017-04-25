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
	int location;  //these are only assigned when appropriate flags are true
	int npcID;
	string tileset;

public:
	TileType();
	void setAll(string, int, int, int, int, int, int, int, int, string);
	void setAll(vector<string>);
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
};

