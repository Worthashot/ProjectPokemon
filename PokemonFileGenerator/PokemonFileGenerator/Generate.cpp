#include "Helper.h"
#include "MapList.h"
#include <set>


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

bool userGenerateMap(std::string choice){
	std::string mapString = choice + ".txt";
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
		std::cout << "Enter the name and " + std::to_string(Helper::tilePars) + " paramaters\n";
		std::cin >> line;
		Helper::trim(line);
		lineVector = Helper::split(line, ' ');
		truth = lineVector.size() == Helper::tilePars;
		if (truth){
			for (int j = 1; j < 9; j++){
				truth = truth && (atoi(lineVector[j].c_str()) != 0) || (lineVector[j] == "0");
			}
		}
		while (!truth){
			std::cout << "Please enter " + std::to_string(Helper::tilePars) + " paramaters\n";
			std::cin >> line;
			Helper::trim(line);
			lineVector = Helper::split(line, ' ');
			truth = lineVector.size() == Helper::tilePars;
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
		truth = lineVector.size() == 2;
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


int main(){

	std::cout << "starting file generator\nloading header\n";
	MapList theList;
	//opens the header again for future read/write
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	pos = std::string(buffer).substr(0, pos).find_last_of("\\");
	std::string dir = std::string(buffer).substr(0, pos);
	theList = MapList(dir + "\\ProjectPokemon\\Debug\\");

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

			while (!theList.getMap(choice)){
				std::cout << "Map name already in use, name another map\n";
				std::cin >> choice;
				Helper::trim(choice);
			}


			if (Helper::doesFileExist(choice)){
				if (theList.testMap(choice)){
					std::cout << "map already exists, linking\nCaution, map may contain tiles that it does not recognise\n";
					std::ofstream header(theList.getDirectory() + "header.txt");
					header << choice + "\n";
					header.close();
				}
				else{
					std::cout << "map exisits but is invalid. Delete previous file manually to re-allocate\n";
				}
			}
			else{
				if (userGenerateMap(theList.getDirectory() + choice)){
					std::cout << "map created, linking to header\n";
					std::ofstream header(theList.getDirectory() + "header.txt");
					header << choice + "\n";
					header.close();
					std::cout << "map linked to header\n";
				}
				else {
					std::cout << "uncable to generate map\n";
				}
			}
		}
		else {
			std::cout << "Loading map data\n";
			Map currentMap = *theList.getMap(mapStrings[choiceI-2]);
			std::cout << "Map data loaded\n";
			std::vector<int> dims = currentMap.getDimention();

			std::vector<std::string> tiles = currentMap.getTiles();
			std::cout << "Tiles\n";
			for (int i = 0; i < tiles.size(); i++){
				std::cout << " " + tiles[i];
			}

				std::cout << "Layout\n";
				//TODO ADD GRAPHICS TO DISPLAY WHEN ABLE
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

				//TODO add more choices
				std::cout << "1.    add new tile\n";
				std::cout << "2.    change map dimensions\n";
				std::cout << "3.    change";

				//TODO Figure out what i was doing, then do it
				std::ofstream newUserMap(theList.getDirectory() + mapStrings[choiceI] + ".txt");


		}

	}
}

