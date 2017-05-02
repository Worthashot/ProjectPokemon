#include "Helper.h"
#include "MapList.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <set>
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
	int choiceI = 0;
	while (choiceI != 1){
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
			cout << "Please chose a number between 0 and " + to_string(count + 1) + "\n";
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


			if (Helper::doesFileExist(location + choice + ".txt")){
				if (isValidMap(choice)){
					cout << "map already exists, linking\nCaution, map may contain tiles that it does not recognise\n";
					ofstream header(location + "header.txt");
					header << choice + "\n";
					header.close();
				}
				else{ 
					cout << "map exasits but is invalid";
				}
			}
			else{
				ofstream userMap(location + choice + ".txt");
				if (!userMap.is_open()){
					cout << "unable to create file, try again\n";
				}
				else {
					if (generateMap(userMap));
					userMap.close();
					cout << "map created, linking to header\n";
					ofstream header(location + "header.txt");
					header << choice + "\n";
					header.close();
					cout << "map linked to header\n";
				}
			}

			//TODO allow editing previous map
		}
	}
}

bool isValidMap(string location){
	ifstream map(location + ".txt");
	string line;
	int iLine;
	vector < string > lineVector;
	int dims[2];
	int tileCount;

	getline(map, line);
	lineVector = Helper::split(line, ' ');
	if (lineVector.size != 2){
		return false;
	}

	for (int i = 0; i < 2; i++){
		Helper::trim(lineVector[i]);
		dims[i] = atoi(lineVector[i].c_str());
		if (dims[i] == 0 && lineVector[i] != "0"){
			return false;
		}
	}
	
	getline(map, line);
	Helper::trim(line);
	iLine = atoi(line.c_str());
	if (iLine == 0 && line != "0"){
		return false;
	}

	tileCount = iLine;
	for (int i = 0; i < tileCount; i++){
		getline(map, line);
		Helper::trim(line);
		lineVector = Helper::split(line, ' ') ;
		if (lineVector.size != Helper::tilePars){
			return false;
		}

		for (int j = 1; j < Helper::tilePars - 1; j++){
			Helper::trim(lineVector[j]);
			iLine = atoi(lineVector[j].c_str());
			if (iLine == 0 && lineVector[i] != "0"){
				return false;
			}
		}
	}

	for (int i = 0; i < dims[1]; i++){
		getline(map, line);
		lineVector = Helper::split(line, ' ');
		if (lineVector.size() != dims[0]){
			return false;
		}
	}

	return true;
}

bool generateMap(ofstream map){
	string line;
	vector<string> lineVector;

	bool truth;
	int tileCount;
	int dims[2];
	int area;

	set<string> tiles;

	cout << "please enter x and y dimensions of map\n";
	cin >> line;
	lineVector = Helper::split(line, ' ');
	truth = lineVector.size() == 2;

	if (truth){
		Helper::trim(lineVector[0]);
		Helper::trim(lineVector[1]);
		truth && (atoi(lineVector[0].c_str()) != 0 || lineVector[0] == "0") && (atoi(lineVector[1].c_str()) != 0 || lineVector[1] == "0");
	}

	while (!truth){
		cout << "dimensions must have 2 arguments\n";
		cin >> line;
		lineVector = Helper::split(line, ' ');
		Helper::trim(lineVector[0]);
		Helper::trim(lineVector[1]);
		if (lineVector.size() == 2){
			truth = (atoi(lineVector[0].c_str()) != 0 || lineVector[0] == "0") && (atoi(lineVector[1].c_str()) != 0 || lineVector[1] == "0");
		}
	}
	dims[0] = atoi(lineVector[0].c_str());
	dims[1] = atoi(lineVector[1].c_str());
	map << line + "\n";

	cout << "please enter number of custom tiles\n";
	cin >> line;
	Helper::trim(line);
	tileCount = atoi(line.c_str());
	while ((tileCount == 0) && (lineVector[0] != "0")){
		cout << "please enter a valid numberan";
		cin >> line;
		Helper::trim(line);
		tileCount = atoi(line.c_str());
	}
	map << line + "\n";

	for (int i = 0; i < tileCount; i++){
		cout << "Creating tile " + to_string(i + 1) + "\n";
		cout << "Enter the name and " + to_string(Helper::tilePars) + " paramaters\n";
		cin >> line;
		Helper::trim(line);
		lineVector = Helper::split(line, ' ');
		truth = lineVector.size == Helper::tilePars;
		if (truth){
			for (int j = 1; j < 9; j++){
				truth = truth && (atoi(lineVector[j].c_str()) != 0) || (lineVector[j] == "0");
			}
		}
		while (!truth){
			cout << "Please enter " + to_string(Helper::tilePars) + " paramaters\n";
			cin >> line;
			Helper::trim(line);
			lineVector = Helper::split(line, ' ');
			truth = lineVector.size == Helper::tilePars;
			if (truth){
				for (int j = 1; j < 9; j++){
					truth = truth && (atoi(lineVector[j].c_str()) != 0) || (lineVector[j] == "0");
				}
			}
		}
		tiles.insert(line);
		map << line + "\n";
	}

	area = dims[0] * dims[1];
	for (int i = 0; i < area;){
		int startSquare = i;
		cout << "Assigning tiles from co-ordinates " + findDims(i, dims[0], dims[1]) + " to map\n";
		cout << "Please enter the number of tiles followed by its name\n";
		cin >> line;
		Helper::trim(line);
		lineVector = Helper::split(line, ' ');
		truth = lineVector.size == 2;
		if (truth){
			truth = (atoi(lineVector[0].c_str()) != 0) && tiles.find(lineVector[1]) != tiles.end();
		}
		while (!truth){
			cout << "please enter a number above 0 and a valid tile name\n";
			cin >> line;
			Helper::trim(line);
			lineVector = Helper::split(line, ' ');
			if (lineVector.size() == 2){
				truth = (atoi(lineVector[0].c_str()) != 0) && (tiles.find(lineVector[1]) != tiles.end()) 
					&& (atoi(lineVector[0].c_str()) + i < area);
			}
		}
		i += atoi(lineVector[0].c_str());
		map << assignSquares(startSquare, i, lineVector[1], dims[0], dims[1]);
	}
	return true;
}

string findDims(int position, int dimx, int dimy){
	int x = 0;
	int y = 0;
	int count = 0;
	while (y < position && y * dimx < position){
		count++;
		y = y * dimx;
	}
	x = position - count * dimx;
	return to_string(x) + " " + to_string(y) + "\n";

	//calculates the co-ordinates on a 0 start grid given the x + (y*x) possition
}

string assignSquares(int start, int end, string tile, int dimx, int dimy){
	int currentYDim = atoi(Helper::split(findDims(start, dimx, dimy), ' ')[1].c_str());
	int endYDim = atoi(Helper::split(findDims(end, dimx, dimy), ' ')[1].c_str());
	string result = "";

	for (int i = start; i < end; i++){
		if (currentYDim = dimy){
			result = result + "\n" + tile;
			currentYDim = 0;
		}
		else {
			result = result + " " + tile;
			currentYDim++;
		}
	}
	return result;
}
//gives a string with the string in tile, seperated by either spaces or newlines
	//the difference between start and end times. A newline is present when the current
	//y co-ordiante is greater than the new y co-ordinate. The current y co-ordiante is
	//found by 