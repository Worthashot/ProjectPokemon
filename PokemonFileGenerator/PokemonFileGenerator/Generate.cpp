#include "Helper.h"
#include "MapList.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	cout << "starting file generator\nloading header\n";

	MapList theList = MapList();

	//opens the header again for future read/write
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\");
	pos = string(buffer).substr(0, pos).find_last_of("\\");
	pos = string(buffer).substr(0, pos).find_last_of("\\");
	string dir = string(buffer).substr(0, pos);
	string location = dir + "\\ProjectPokemon\\Debug\\";

	vector<string> mapStrings = theList.listOfMaps();
	int count = theList.mapCount();
	string choice;
	int choiceI;
	cout << "Chose old map or create a new one\n";
	cout << "1.    End\n";
	cout << "2.    Add Map\n";
	for (int i = 0; i < count; i++){
		cout << to_string(i + 3) + "    " + mapStrings[i] + "\n";
	}

	cin >> choice;
	Helper::trim(choice);
	choiceI = atoi(choice.c_str());
	while (choiceI < 1 || choiceI > count + 2){
		cout << "Please chose a number between 0 and " + to_string(count) + "\n";
		cin >> choice;
		Helper::trim(choice);
		choiceI = atoi(choice.c_str());
	}

	if (choiceI == 2){
		cout << "Name the map\n";
		cin >> choice;
		Helper::trim(choice);
		while (find(mapStrings.begin(), mapStrings.end(), choice) != mapStrings.end()){
			cout << "Map name already in use, name another map\n";
			cin >> choice;
			Helper::trim(choice);
		}
		ofstream header(location + "header.txt");
		header << choice + "\n";
		header.close();
	}
}

