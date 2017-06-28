#pragma once
#include <direct.h>
#include "catch.hpp"
#include "MapList.h"
#include <iostream>
#include <fstream>
using namespace std;


TEST_CASE("MapList::MapList(string directory) general test 1", "[MapList::MapList(string directory)]"){
	//Test creation with no header

	std::string directory = Helper::getDirectory() +"\\PokemonFileGenerator\\Debug\\MapList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	REQUIRE(l.getDirectory() == directory);
	REQUIRE(l.getNames().empty());
	REQUIRE(l.listOfMaps().empty());
}


TEST_CASE("MapList::MapList(string directory) general test 2", "[MapList::MapList(string directory)]"){
	//Test creation with a header

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList test\\";
	_mkdir(directory.c_str());

	std::string hs = directory + "header.txt";
	ofstream h(hs);
	h << "map data1";
	h.close();

	std::string h1 = directory + "map data1.txt";
	ofstream t1(directory + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	MapList l = MapList(directory);
	std::vector<std::string> v = { "map data1" };

	REQUIRE(l.getDirectory() == directory);
	REQUIRE(l.getNames() == "map data1");
	REQUIRE(l.listOfMaps() == v);

	std::remove(hs.c_str());
	std::remove(h1.c_str());

}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::initiateList(string headerName) general test", "[MapList::initiateList(string headerName)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadMap(string filename, deque<string> queue) general test", "[MapList::loadMap(string filename, deque<string> queue)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadMaps(vector<string> mapsToLoad) general test", "[MapList::loadMaps(vector<string> mapsToLoad)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadAdjacentMaps(Map currentMap) general test", "[MapList::loadAdjacentMaps(Map currentMap)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadAdjacentMaps() general test", "[MapList::loadAdjacentMaps()]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testMap(string mapName) general test", "[MapList::testMap(string mapName)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getMap(string map) general test", "[MapList::getMap(string map)]"){
	//As of now, does nothing
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getNames() general test", "[MapList::getNames()]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getDirectory() general test", "[MapList::getDirectory()]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testDimention(string line) general test", "[MapList::testDimention(string line)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::generateMap(string fileName) general test", "[MapList::generateMap(string fileName)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::mapCount() general test", "[MapList::mapCount()]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::listOfMaps() general test", "[MapList::listOfMaps()]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testValidTileType(string line) general test", "[MapList:testValidTileType(string line)]"){
	//As of now, does nothing
}









TEST_CASE("Test MapList recognises the correct map format 1", "[testMap1]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string testFolder = (string)buffer + "testMap 1\\";
	_mkdir(testFolder.c_str());

	MapList test1 = MapList(testFolder);

	ofstream h(testFolder + "header.txt");
	h << "map data1\nmap data9";
	h.close();

	ofstream t1(testFolder + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	ofstream t2(testFolder + "map data2.txt");
	t2 << "bannanas\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t2.close();

	ofstream t3(testFolder + "map data3.txt");
	t3 << "5 5\nbannanas\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t3.close();

	ofstream t4(testFolder + "map data4.txt");
	t4 << "5 5\n1\nbannanas\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4.close();

	ofstream t5(testFolder + "map data5.txt");
	t5 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\ntbannanas\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t5.close();

	ofstream t6(testFolder + "map data6.txt");
	t6 << "0 0\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t6.close();

	ofstream t7(testFolder + "map data7.txt");
	t7 << "24\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t7.close();

	ofstream t8(testFolder + "map data8.txt");
	t8 << "5 5\n0\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t8.close();

	ofstream t9(testFolder + "map data9.txt");
	t9 << "5 5\n4\nt1 1 1 1 1 1 1 1 1 ts1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t9.close();

	REQUIRE(test1.testMap("map data1") == true);
	REQUIRE(test1.testMap("map data2") == false);
	REQUIRE(test1.testMap("map data3") == false);
	REQUIRE(test1.testMap("map data4") == false);
	REQUIRE(test1.testMap("map data5") == false);
	REQUIRE(test1.testMap("map data6") == false);
	REQUIRE(test1.testMap("map data7") == false);
	REQUIRE(test1.testMap("map data8") == false);
	REQUIRE(test1.testMap("map data9") == true);
}


TEST_CASE("Test getting correct information from a file 1", "[MapList_create1]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string testFolder = (string)buffer + "MapList_create 1\\";
	_mkdir(testFolder.c_str());

	ofstream h(testFolder + "header.txt");
	h << "map data1\nmap data2";
	h.close();

	ofstream t1(testFolder + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	ofstream t2(testFolder + "map data2.txt");
	t2 << "5 5\n5\nt1 1 1 1 1 1 1 1 1 ts1\nt2 1 1 1 1 1 1 1 1 ts2\nt3 1 1 1 1 1 1 1 1 ts3\nt4 1 1 1 1 1 1 1 1 ts4\nt5 1 1 1 1 1 1 1 1 ts5\nt1 t2 t3 t4 t5\nt1 t5 t4 t1 t2\nt2 t1 t3 t1 t4\nt3 t1 t4 t3 t5\nt1 t1 t1 t5 t1";
	t2.close();

	MapList test1 = MapList(testFolder);
	vector<string> vlist{ "map data1", "map data2" };
	vector<string> v1{ "t1", "1", "1", "1", "1", "1", "1", "1", "1", "ts1" };
	vector<string> v2{ "t2", "1", "1", "1", "1", "1", "1", "1", "1", "ts2" };
	vector<string> v3{ "t3", "1", "1", "1", "1", "1", "1", "1", "1", "ts3" };
	vector<string> v4{ "t4", "1", "1", "1", "1", "1", "1", "1", "1", "ts4" };
	vector<string> v5{ "t5", "1", "1", "1", "1", "1", "1", "1", "1", "ts5" };

	REQUIRE(test1.getMap("map data1")->getTile(1, 1).getAll() == v1);
	REQUIRE(test1.getMap("map data2")->getTile(0, 0).getAll() == v1);
	REQUIRE(test1.getMap("map data2")->getTile(1, 4).getAll() == v2);
	REQUIRE(test1.getMap("map data2")->getTile(2, 2).getAll() == v3);
	REQUIRE(test1.getMap("map data2")->getTile(3, 2).getAll() == v4);
	REQUIRE(test1.getMap("map data2")->getTile(4, 3).getAll() == v5);
	REQUIRE(test1.mapCount() == 2);
	REQUIRE(test1.listOfMaps() == vlist);
	_rmdir(testFolder.c_str());
}

TEST_CASE("Test getting correct information from a file 2", "[MapList_create2]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string testFolder = (string)buffer + "MapList_create 2\\";
	_mkdir(testFolder.c_str());

	ofstream h(testFolder + "header.txt");
	h << "map data1";
	h.close();

	ofstream t1(testFolder + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	MapList test1 = MapList(testFolder);
	vector<string> vlist{ "map data1" };
	REQUIRE(test1.mapCount() == 1);
	REQUIRE(test1.listOfMaps() == vlist);
	_rmdir(testFolder.c_str());
}

TEST_CASE("Test getting correct information from a file 3", "[MapList_create3]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string testFolder = (string)buffer + "MapList_create 3\\";
	_mkdir(testFolder.c_str());

	ofstream h(testFolder + "header.txt");
	h << "";
	h.close();

	MapList testList1 = MapList(testFolder);
	vector<string> vlist{  };
	REQUIRE(testList1.mapCount() == 0);
	REQUIRE(testList1.listOfMaps() == vlist);

}


TEST_CASE("Test getting correct information from a file 4", "[MapList_create4]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string testFolder = (string)buffer + "MapList_create 4\\";
	_mkdir(testFolder.c_str());

	ofstream h(testFolder + "header.txt");
	h << "map data1\nmap data2\nmap data3\nmap data4\nmap data5\nmap data6";
	h.close();

	ofstream t1(testFolder + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	ofstream t2(testFolder + "map data2.txt");
	t2 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t2.close();

	ofstream t3(testFolder + "map data3.txt");
	t3 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t3.close();

	ofstream t4(testFolder + "map data4.txt");
	t4 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4.close();

	ofstream t5(testFolder + "map data5.txt");
	t5 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t5.close();

	ofstream t6(testFolder + "map data6.txt");
	t6 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t6.close();

	MapList testList1 = MapList(testFolder);
	vector<string> v1_list{ "map data1","map data2","map data3","map data4","map data5","map data6" };
	REQUIRE(testList1.mapCount() == 6);
	REQUIRE(testList1.listOfMaps() == v1_list);

	_rmdir(testFolder.c_str());

}

TEST_CASE("Test Having a MapList with multiple TileTypes named the same", "[MapList Same TileType]"){
	//TODO
}
//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
