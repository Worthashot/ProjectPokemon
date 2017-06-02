#include "Helper.h"
#include "MapList.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <set>


int main(){
	start();
	return 0;
}

void start(){
	std::cout << "starting file generator\nloading header\n";

	MapList theList = MapList();

	//opens the header again for future read/write
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);
	std::string location = dir + "\\ProjectPokemon\\Debug\\";

	std::vector<std::string> mapStrings = theList.listOfMaps();
	int count = theList.mapCount();
	std::string choice;
	int choiceI = 0;
	while (choiceI != 1){
		std::cout << "Chose old map or create a new one\n";
		std::cout << "1.    End\n";
		std::cout << "2.    Add Map\n";
		for (int i = 0; i < count; i++){
			std::cout << std::to_string(i + 3) + "    " + mapStrings[i] + "\n";
		}

		std::cin >> choice;
		Helper::trim(choice);
		choiceI = atoi(choice.c_str());
		while (choiceI < 1 || choiceI > count + 2){
			std::cout << "Please chose a number between 0 and " + std::to_string(count + 1) + "\n";
			std::cin >> choice;
			Helper::trim(choice);
			choiceI = atoi(choice.c_str());
		}

		if (choiceI == 2){
			std::cout << "Name the map\n";
			std::cin >> choice;
			Helper::trim(choice);

			while (find(mapStrings.begin(), mapStrings.end(), choice) != mapStrings.end()){
				std::cout << "Map name already in use, name another map\n";
				std::cin >> choice;
				Helper::trim(choice);
			}


			if (Helper::doesFileExist(location + choice + ".txt")){
				if (isValidMap(choice)){
					std::cout << "map already exists, linking\nCaution, map may contain tiles that it does not recognise\n";
					std::ofstream header(location + "header.txt");
					header << choice + "\n";
					header.close();
				}
				else{
					std::cout << "map exasits but is invalid";
				}
			}
			else{
				std::ofstream userMap(location + choice + ".txt");
				if (!userMap.is_open()){
					std::cout << "unable to create file, try again\n";
				}
				else {
					userMap.close();
					generateMap(location + choice + ".txt");
					std::cout << "map created, linking to header\n";
					std::ofstream header(location + "header.txt");
					header << choice + "\n";
					header.close();
					std::cout << "map linked to header\n";
				}
			}
		}
		else {
			std::ifstream userMap(location + mapStrings[choiceI] + ".txt");
			if (!userMap.is_open()){
				std::cout << "cannot open map, please try again\n";
			}
			else {
				std::cout << "Loading map data\n";
				Map currentMap = MapList::readMap(&userMap);
				userMap.close();
				std::cout << "Map data loaded\n";
				int* dims = currentMap.getDimention();

				std::vector<std::string> tiles = currentMap.getTiles();
				std::cout << "Tiles";
				for (int i = 0; i < tiles.size(); i++){
					std::cout << " " + tiles[i];
				}

				std::cout << "Layout\n";
				//ADD GRAPHICS TO DISPLAY WHEN ABLE
				for (int j = 0; j < dims[0]; j++){
					std::cout << std::to_string(j) + "        ";
				}
				std::cout << "\n";
				for (int i = 0; i < dims[1]; i++){
					std::cout << std::to_string(i);
					for (int j = 0; j < dims[0]; j++){
						std::cout << " | " + currentMap.getTile(i, j).getName();
					}
					std::cout << "\n";
				}
				std::cout << "1.    add new tile\n";
				std::cout << "2.    change map dimensions\n";
				std::cout << "3.    change";
				std::ofstream newUserMap(location + mapStrings[choiceI] + ".txt");


			}

		}
	}
}
bool isValidMap(std::string location){
	std::ifstream map(location + ".txt");
	std::string line;
	int iLine;
	std::vector < std::string > lineVector;
	int * tileCount;
	int * dims; 
	bool truth = true;

	getline(map, line);
	if (!validDimention(line, dims)){
		return false;
	}

	getline(map, line);
	if (!Helper::isNumber(line, tileCount)){
		return false;
	}
	
	for (int i = 0; i < *tileCount; i++){
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

//sets dims to a vector of 2 ints if the line is formatted properly, null if not
bool validDimention(std::string line, int* dims){

	std::vector < std::string > lineVector;
	lineVector = Helper::split(line, ' ');
	if (lineVector.size != 2){
		dims = NULL;
		return false;
	}

	for (int i = 0; i < 2; i++){
		Helper::trim(lineVector[i]);
		dims[i] = atoi(lineVector[i].c_str());
		if (dims[i] == 0 && lineVector[i] != "0"){
			dims = NULL;
			return false;
		}
	}
	return true;
}
bool generateMap(std::string mapString){
	std::ofstream map(mapString);
	std::string line;
	std::vector<std::string> lineVector;

	bool truth;
	int tileCount;
	int dims[2];
	int area;

	std::set<std::string> tiles;

	std::cout << "please enter x and y dimensions of map\n";
	std::cin >> line;
	lineVector = Helper::split(line, ' ');
	truth = lineVector.size() == 2;

	if (truth){
		Helper::trim(lineVector[0]);
		Helper::trim(lineVector[1]);
		truth && (atoi(lineVector[0].c_str()) != 0 || lineVector[0] == "0") && (atoi(lineVector[1].c_str()) != 0 || lineVector[1] == "0");
	}

	while (!truth){
		std::cout << "dimensions must have 2 arguments\n";
		std::cin >> line;
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

	std::cout << "please enter number of custom tiles\n";
	std::cin >> line;
	Helper::trim(line);
	tileCount = atoi(line.c_str());
	while ((tileCount == 0) && (lineVector[0] != "0")){
		std::cout << "please enter a valid number";
		std::cin >> line;
		Helper::trim(line);
		tileCount = atoi(line.c_str());
	}
	map << line + "\n";

	for (int i = 0; i < tileCount; i++){
		std::cout << "Creating tile " + std::to_string(i + 1) + "\n";
		std::cout << "Enter the name and " + to_string(Helper::tilePars) + " paramaters\n";
		std::cin >> line;
		Helper::trim(line);
		lineVector = Helper::split(line, ' ');
		truth = lineVector.size == Helper::tilePars;
		if (truth){
			for (int j = 1; j < 9; j++){
				truth = truth && (atoi(lineVector[j].c_str()) != 0) || (lineVector[j] == "0");
			}
		}
		while (!truth){
			std::cout << "Please enter " + to_string(Helper::tilePars) + " paramaters\n";
			std::cin >> line;
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
		std::cout << "Assigning tiles from co-ordinates " + findDims(i, dims[0], dims[1]) + " to map\n";
		std::cout << "Please enter the number of tiles followed by its name\n";
		std::cin >> line;
		Helper::trim(line);
		lineVector = Helper::split(line, ' ');
		truth = lineVector.size == 2;
		if (truth){
			truth = (atoi(lineVector[0].c_str()) != 0) && tiles.find(lineVector[1]) != tiles.end();
		}
		while (!truth){
			std::cout << "please enter a number above 0 and a valid tile name\n";
			std::cin >> line;
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

std::string findDims(int position, int dimx, int dimy){
	int x = 0;
	int y = 0;
	int count = 0;
	while (y < position && y * dimx < position){
		count++;
		y = y * dimx;
	}
	x = position - count * dimx;
	return std::to_string(x) + " " + std::to_string(y) + "\n";

	//calculates the co-ordinates on a 0 start grid given the x + (y*x) possition
}

std::string assignSquares(int start, int end, std::string tile, int dimx, int dimy){
	int currentYDim = atoi(Helper::split(findDims(start, dimx, dimy), ' ')[1].c_str());
	int endYDim = atoi(Helper::split(findDims(end, dimx, dimy), ' ')[1].c_str());
	std::string result = "";

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