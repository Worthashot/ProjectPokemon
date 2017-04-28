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


	//The correct directory should be 3 levels up

	/*
	ifstream header(dir + "\PokemonProject\PokemonProjext\header.exe");
	if (CustomTileFile.is_open()){

		//check the file is formated properly
		while (getline(CustomTileFile, line)){
			vector<string> pars = Helper::split(line, ' ');
			if (pars.size() == Helper::tilePars){
				for (int j = 2; j < 8; j++){
					if (pars[j] != "0" || pars[j] != "1"){
						cout << "line " + to_string(i) + " paramater " + to_string(j) + "is not a valid boolean";
						cerr << "invalid paramater";
					}
				}
				if (atoi(pars[8].c_str()) <= 0 && pars[8] != "0"){
					cout << "line " + to_string(i) + " paramater 8 is not a valid id";
					cerr << "invalid paramater";
				}

				if (atoi(pars[9].c_str()) <= 0 && pars[9] != "0"){
					cout << "line " + to_string(i) + " paramater 9 is not a valid id";
					cerr << "invalid paramater";
				}
			}

			else{
				cout << "line " + to_string(i) + " does not have enough paramaters";
				cerr << "not enough paramaters";
			}

			customFiles.push_back(line);
		}
		cout << "custom file loaded\n";
		CustomTileFile.close();
	}
	else {
		cout << "no custom tile file found\n";
	}
	*/

}
