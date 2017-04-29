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
	cout << "Chose old map or create a new one\n";
	int count = theList.mapCount();
	for (int i = 0; i < count; i++){
		cout << to_string(i) + "    " + 


