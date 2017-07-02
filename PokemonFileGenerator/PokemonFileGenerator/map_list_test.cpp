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
	std::remove(hs.c_str());
	

	ofstream h(hs);
	h << "map data1";
	h.close();

	std::string h1 = directory + "map data1.txt";
	std::remove(h1.c_str());

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


TEST_CASE("MapList::initiateList(string headerName) general test 1", "[MapList::initiateList(string headerName)]"){
	//Test with the given header name not created

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList initiateList test\\";

	MapList l = MapList(directory);

	REQUIRE_THROWS_WITH(l.initiateList("header.txt"), "cannot open file");
}

TEST_CASE("MapList::initiateList(string headerName) general test 2", "[MapList::initiateList(string headerName)]"){
	//Test with every name in the header file created

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	std::string hs = directory + "header.txt";
	std::remove(hs.c_str());

	ofstream h(hs);
	h << "map data1";
	h.close();

	REQUIRE_THROWS_WITH(l.initiateList("header.txt"), "given map name does not exist");

	std::remove(hs.c_str());

}

TEST_CASE("MapList::initiateList(string headerName) general test 3", "[MapList::initiateList(string headerName)]"){
	//Test with the first name in the header file not created but all of the other are

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	std::vector<std::string> v = { "map data1" };

	std::string hs = directory + "header.txt";
	std::string h1 = directory + "map data1.txt";

	std::remove(hs.c_str());
	std::remove(h1.c_str());

	ofstream h(hs);
	h << "map data1";
	h.close();

	ofstream t1(directory + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	l.initiateList("header.txt");

	REQUIRE(l.getDirectory() == directory);
	REQUIRE(l.getNames() == "map data1");
	REQUIRE(l.listOfMaps() == v);

	std::remove(hs.c_str());
	std::remove(h1.c_str());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadMap(string filename, deque<string> queue) general test 1", "[MapList::loadMap(string filename, deque<string> queue)]"){
	//Test when file is wrong form, returns false and clears queue

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	std::string hs = directory + "header.txt";
	std::string h1 = directory + "map data1.txt";

	std::remove(hs.c_str());
	std::remove(h1.c_str());

	ofstream t1(directory + "map data1.txt");
	t1 << "5 \n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	deque<string> queue;

	REQUIRE(l.loadMap("map data1.txt", queue) == false);
	std::remove(hs.c_str());
	std::remove(h1.c_str());
}

TEST_CASE("MapList::loadMap(string filename, deque<string> queue) general test 2", "[MapList::loadMap(string filename, deque<string> queue)]"){
	//Test when file is right form, returns true and writes data to queue

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	std::string hs = directory + "header.txt";
	std::string h1 = directory + "map data1.txt";

	std::remove(hs.c_str());
	std::remove(h1.c_str());

	ofstream t1(directory + "map data1.txt");
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	deque<std::string> queue;
	deque<std::string> data = { "5 5", "1", "t1 1 1 1 1 1 1 1 1 ts1", "t1 t1 t1 t1 t1",
		"t1 t1 t1 t1 t1", "t1 t1 t1 t1 t1", "t1 t1 t1 t1 t1", "t1 t1 t1 t1 t1", };

	REQUIRE(l.loadMap("map data1", queue) == true);
	REQUIRE(queue == data);

	std::remove(hs.c_str());
	std::remove(h1.c_str());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadMaps(vector<string> mapsToLoad) general test 1", "[MapList::loadMaps(vector<string> mapsToLoad)]"){
	//Test when list is empty, the map list is cleared of loaded maps

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);
	std::vector<std::string> s;
	s.clear();

	l.loadMaps(s);
	REQUIRE(l.getNames().empty() == true);
}

TEST_CASE("MapList::loadMaps(vector<string> mapsToLoad) general test 2", "[MapList::loadMaps(vector<string> mapsToLoad)]"){
	//Test when list has some elements, the appropriate maps are loaded

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	std::string h1 = directory + "map data1.txt";
	std::string h2 = directory + "map data2.txt";

	std::remove(h1.c_str());
	std::remove(h2.c_str());

	ofstream t1(h1);
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	ofstream t2(h2);
	t2 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t2.close();

	std::vector<std::string> v = { "map data1", "map data2" };

	l.loadMaps(v);
	REQUIRE(l.listOfLoadedMaps() == v);

	std::remove(h1.c_str());
	std::remove(h2.c_str());
}

TEST_CASE("MapList::loadMaps(vector<string> mapsToLoad) general test 3", "[MapList::loadMaps(vector<string> mapsToLoad)]"){
	//Test when list has some elements, the appropriate maps are loaded

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string hs = directory + "header.txt";
	std::string h1 = directory + "map data1.txt";	
	std::string h2 = directory + "map data2.txt";

	std::remove(hs.c_str());
	std::remove(h1.c_str());
	std::remove(h2.c_str());

	ofstream h(hs);
	h << "map data1";
	h.close();

	ofstream t1(h1);
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	MapList l = MapList(directory);

	std::vector<std::string> v = { "map data1" };
	REQUIRE(l.listOfLoadedMaps() == v);

	ofstream t2(h2);
	t2 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t2.close();

	v = { "map data2" };
	l.loadMaps(v);
	REQUIRE(l.listOfLoadedMaps() == v);

	std::remove(hs.c_str());
	std::remove(h1.c_str());
	std::remove(h2.c_str());
}

TEST_CASE("MapList::loadMaps(vector<string> mapsToLoad) general test 4", "[MapList::loadMaps(vector<string> mapsToLoad)]"){
	//Test when list had files formated wrong, they are not loaded

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 \n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	std::vector<std::string> v = { "map data1" };

	v = { "map data1" };
	l.loadMaps(v);
	REQUIRE(l.listOfLoadedMaps().empty() == true);

	std::remove(h1.c_str());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::loadAdjacentMaps(Map currentMap) general test 1", "[MapList::loadAdjacentMaps(Map currentMap)]"){
	//As of now, does nothing
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testMap(string mapName) general test 1", "[MapList::testMap(string mapName)]"){
	//If the file specified does not exist, returns false.

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	MapList l = MapList(directory);

	REQUIRE(l.testMap("map data1") == false);
}

TEST_CASE("MapList::testMap(string mapName) general test 3", "[MapList::testMap(string mapName)]"){
	//If the first line of the file is not 2 spaced integers, returns false.

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 \n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	REQUIRE(l.testMap("map data1") == false);
	std::remove(h1.c_str());
}

TEST_CASE("MapList::testMap(string mapName) general test 4", "[MapList::testMap(string mapName)]"){
	//If the second line of the file is not 1 integer, returns false.


	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 5\n1 1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	REQUIRE(l.testMap("map data1") == false);
	std::remove(h1.c_str());
}

TEST_CASE("MapList::testMap(string mapName) general test 5", "[MapList::testMap(string mapName)]"){
	//If the TileType lines are not TileTypes, returns false

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 5\n1\nnot a tile type\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	REQUIRE(l.testMap("map data1") == false);
	std::remove(h1.c_str());
}

TEST_CASE("MapList::testMap(string mapName) general test 6", "[MapList::testMap(string mapName)]"){
	//If the map composition lines are not valid size and strings, returns false

	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nshort t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	REQUIRE(l.testMap("map data1") == false);
	std::remove(h1.c_str());
}

TEST_CASE("MapList::testMap(string mapName) general test 7", "[MapList::testMap(string mapName)]"){
	//If the file is too large, returns false


	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\n moreeee";
	t1.close();

	REQUIRE(l.testMap("map data1") == false);
	std::remove(h1.c_str());
}

TEST_CASE("MapList::testMap(string mapName) general test 8", "[MapList::testMap(string mapName)]"){
	//If everything is valid, returns true.


	std::string directory = Helper::getDirectory() + "\\PokemonFileGenerator\\Debug\\MapList InitiateList test\\";
	_mkdir(directory.c_str());

	std::string h1 = directory + "map data1.txt";

	std::remove(h1.c_str());

	MapList l = MapList(directory);

	ofstream t1(h1);
	t1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1.close();

	REQUIRE(l.testMap("map data1") == true);
	std::remove(h1.c_str());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getMap(string map) general test 1", "[MapList::getMap(string map)]"){
	//Tests that a loaded map returns a pointer to it
}

TEST_CASE("MapList::getMap(string map) general test 2", "[MapList::getMap(string map)]"){
	//Tests that a not loaded map returns a Null pointer
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getNames() general test 1", "[MapList::getNames()]"){
	//Tests the valid string is returned
}

TEST_CASE("MapList::getNames() general test 2", "[MapList::getNames()]"){
	//Tests an empty string is returned
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::getDirectory() general test 1", "[MapList::getDirectory()]"){
	//Tests the directory is returned
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testDimention(string line) general test 1", "[MapList::testDimention(string line)]"){
	//Test invalid size dimention returns false
}

TEST_CASE("MapList::testDimention(string line) general test 2", "[MapList::testDimention(string line)]"){
	//Test invalid type dimention returns false
}

TEST_CASE("MapList::testDimention(string line) general test 3", "[MapList::testDimention(string line)]"){
	//Test invalid value dimention returns false
}

TEST_CASE("MapList::testDimention(string line) general test 4", "[MapList::testDimention(string line)]"){
	//Test valid dimention returns true
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::generateMap(string fileName) general test 1", "[MapList::generateMap(string fileName)]"){
	//test an invalid Map file returns an empty map
}

TEST_CASE("MapList::generateMap(string fileName) general test 2", "[MapList::generateMap(string fileName)]"){
	//test a valid Map file returns a map
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::mapCount() general test 1", "[MapList::mapCount()]"){
	//Tests the size of the loaded maps is returnd
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::listOfMaps() general test 1", "[MapList::listOfMaps()]"){
	//Tests the list of loaded maps is returned
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("MapList::testValidTileType(string line) general test 1", "[MapList:testValidTileType(string line)]"){
	//Tests a wrong number of substrings returns false
}

TEST_CASE("MapList::testValidTileType(string line) general test 2", "[MapList:testValidTileType(string line)]"){
	//Test the wrong type of substrings returns false
}
TEST_CASE("MapList::testValidTileType(string line) general test 3", "[MapList:testValidTileType(string line)]"){
	//Tests if everything is right returns true
}









//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
