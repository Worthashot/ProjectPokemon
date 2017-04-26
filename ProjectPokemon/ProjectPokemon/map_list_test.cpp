#include "catch.hpp"
#include "MapList.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST_CASE("Test getting correct information from a file", "[MapList_create]"){
	ofstream th("header.txt");
	th << "test1";
	th.close();

	ofstream t1("test1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();
	MapList test = MapList();
	vector<string> v1{ "t1", "1", "1", "1", "1", "1", "1", "1", "1", "ts1" };
	REQUIRE(test.getMap("test1").getTile(1, 1).getAll() ==  v1);
}

//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
