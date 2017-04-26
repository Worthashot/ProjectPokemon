#include "catch.hpp"
#include "MapList.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST_CASE("Test getting correct information from a file", "[MapList_create]"){
	ofstream th("header.txt");
	th << "test1\ntest2";
	th.close();

	ofstream t1("test1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	ofstream t2("test2.txt");
	t2 << "5 5\n5\nt1 1 1 1 1 1 1 1 1 ts1\nt2 1 1 1 1 1 1 1 1 ts2\nt3 1 1 1 1 1 1 1 1 ts3\nt4 1 1 1 1 1 1 1 1 ts4\nt5 1 1 1 1 1 1 1 1 ts5\nt1 t2 t3 t4 t5\nt1 t5 t4 t1 t2\nt2 t1 t3 t1 t4\nt3 t1 t4 t3 t5\nt1 t1 t1 t5 t1";
	t2.close();

	MapList test = MapList();
	vector<string> v1{ "t1", "1", "1", "1", "1", "1", "1", "1", "1", "ts1" };
	vector<string> v2{ "t2", "1", "1", "1", "1", "1", "1", "1", "1", "ts2" };
	vector<string> v3{ "t3", "1", "1", "1", "1", "1", "1", "1", "1", "ts3" };
	vector<string> v4{ "t4", "1", "1", "1", "1", "1", "1", "1", "1", "ts4" };
	vector<string> v5{ "t5", "1", "1", "1", "1", "1", "1", "1", "1", "ts5" };
	REQUIRE(test.getMap("test1").getTile(1, 1).getAll() == v1);
	REQUIRE(test.getMap("test2").getTile(0, 0).getAll() == v1);
	REQUIRE(test.getMap("test2").getTile(1, 4).getAll() == v2);
	REQUIRE(test.getMap("test2").getTile(2, 2).getAll() == v3);
	REQUIRE(test.getMap("test2").getTile(3, 2).getAll() == v4);
	REQUIRE(test.getMap("test2").getTile(4, 3).getAll() == v5);
}

//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
