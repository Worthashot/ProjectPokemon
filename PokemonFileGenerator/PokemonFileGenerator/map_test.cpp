#pragma once
#include "catch.hpp"
#include "Map.h"
#include <string>
using namespace std;

//Tests for constructor Map::Map()

TEST_CASE("Map::Map() general test", "[Map::Map()]"){
	//As of now, does nothing
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


//Tests for constructor Map::Map(int xDim, int Ydim)
//This should create an object with the specified dimension, TileType and Map Composition.
//Each aspect is tested seperatly

//These test for correct dimension
TEST_CASE("Map::Map(int xDim, int Ydim) test 1", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 0);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 2", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(5, 5);
	std::vector<int> d = { 5, 5 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 3", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 150);
	std::vector<int> d = { 150, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 4", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(2, 7);
	std::vector<int> d = { 2, 7 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 5", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 17);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 6", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(17, 0);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 7", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(1, 150);
	std::vector<int> d = { 1, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 8", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 1);
	std::vector<int> d = { 150, 1 };
	REQUIRE(m.getDimention() == d);
}


//These test for correct TileType registration
TEST_CASE("Map::Map(int xDim, int Ydim) test 9", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 10", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 17);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 11", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(17, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 12", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(170, 170);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}


//These will test the map composition is correct
//Refactor TileType before implementing
TEST_CASE("Map::Map(int xDim, int Ydim) test 13", "[Map::Map(int xDim, int Ydim)]"){
}

TEST_CASE("Map::Map(int xDim, int Ydim) test 14", "[Map::Map(int xDim, int Ydim)]"){


}

TEST_CASE("Map::Map(int xDim, int Ydim) test 15", "[Map::Map(int xDim, int Ydim)]"){

}

TEST_CASE("Map::Map(int xDim, int Ydim) test 16", "[Map::Map(int xDim, int Ydim)]"){


}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


//Tests for constructor Map::Map(int xDim, int Ydim)
//This should create an object with the specified dimension, TileType and Map Composition.
//Each aspect is tested seperatly

//These Test for correct dimension
TEST_CASE("Map::Map(string xDimS, string yDimS) general test 1", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("0", "0");
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 2", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("5", "5");
	std::vector<int> d = { 5, 5 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 3", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("150", "150");
	std::vector<int> d = { 150, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 4", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("2", "7");
	std::vector<int> d = { 2, 7 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 5", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("0", "17");
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 6", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("17", "0");
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 7", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("1", "150");
	std::vector<int> d = { 1, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 8", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map("150", "1");
	std::vector<int> d = { 150, 1 };
	REQUIRE(m.getDimention() == d);
}

//These correct for Correct TileTypes
TEST_CASE("Map::Map(string xDimS, string yDimS) general test 9", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map("0", "0");

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 10", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map("0", "17");

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 11", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map("17", "0");

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 12", "[Map::Map(string xDimS, string yDimS)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map("170", "170");

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}


//These will test the map composition is correct
TEST_CASE("Map::Map(string xDimS, string yDimS) general test 13", "[Map::Map(string xDimS, string yDimS)]"){
	Map m = Map("1", "1");

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 14", "[Map::Map(string xDimS, string yDimS)]"){
	Map m = Map("1", "200");

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 40).getAll() == t.getAll());
	REQUIRE(m.getTile(0,80).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 120).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 199).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 1).getAll() != t.getAll());
	REQUIRE(m.getTile(0, 201).getAll() != t.getAll());
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 15", "[Map::Map(string xDimS, string yDimS)]"){
	Map m = Map("200", "1");

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(40, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(80, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(120, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(199, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 1).getAll() != t.getAll());
	REQUIRE(m.getTile(201, 0).getAll() != t.getAll());
}

TEST_CASE("Map::Map(string xDimS, string yDimS) general test 16", "[Map::Map(string xDimS, string yDimS)]"){
	Map m = Map("250", "250");

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(40, 40).getAll() == t.getAll());
	REQUIRE(m.getTile(120, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 120).getAll() == t.getAll());
	REQUIRE(m.getTile(160, 160).getAll() == t.getAll());
	REQUIRE(m.getTile(249, 249).getAll() == t.getAll());
	REQUIRE(m.getTile(251, 251).getAll() != t.getAll());
	REQUIRE(m.getTile(-5, -5).getAll() != t.getAll());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


//Tests for constructor Map::Map(int xDim, int Ydim, int encounter)
//This should create an object with the specified dimension, TileType, Map Composition and encounter code.
//Each aspect is tested seperatly

//These Test for correct dimension
TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 1", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 0, 0);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 2", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(5, 5, 0);
	std::vector<int> d = { 5, 5 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 3", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 150, 0);
	std::vector<int> d = { 150, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 4", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(2, 7, 0);
	std::vector<int> d = { 2, 7 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 5", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 17, 0 );
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 6", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(17, 0, 0);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 7", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(1, 150, 0);
	std::vector<int> d = { 1, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 8", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 1, 0);
	std::vector<int> d = { 150, 1 };
	REQUIRE(m.getDimention() == d);
}

//These correct for Correct TileTypes
TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 9", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 0, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 10", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 17, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 11", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(1, 0, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 12", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(170, 170, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}


//These will test the map composition is correct
TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 13", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(1, 1, 0);

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 14", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(1, 200, 0);

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 40).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 80).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 120).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 199).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 1).getAll() != t.getAll());
	REQUIRE(m.getTile(0, 201).getAll() != t.getAll());
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 15", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(200, 1, 0);

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(40, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(80, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(120, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(199, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 1).getAll() != t.getAll());
	REQUIRE(m.getTile(201, 0).getAll() != t.getAll());
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 16", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(250, 250, 0);

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(40, 40).getAll() == t.getAll());
	REQUIRE(m.getTile(120, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 120).getAll() == t.getAll());
	REQUIRE(m.getTile(160, 160).getAll() == t.getAll());
	REQUIRE(m.getTile(249, 249).getAll() == t.getAll());
	REQUIRE(m.getTile(251, 251).getAll() != t.getAll());
	REQUIRE(m.getTile(-5, -5).getAll() != t.getAll());
}

//These test that the encounter code is set correctly

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 17", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(0, 0, 1222);

	REQUIRE(m.getEncounterCode() == 1222);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 18", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(5, 5, 1222);

	REQUIRE(m.getEncounterCode() == 1222);
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test 19", "[Map(int xDim, int yDim, int encounter)]"){
	Map m = Map(700, 700, 1222);

	REQUIRE(m.getEncounterCode() == 1222);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


//Tests for constructor Map::Map(deque<string> info) general test
//This should create an object with set dimention, TileTypes and mapComp specified by info.
//Each aspect is tested seperatly


//These Test for correct dimension
TEST_CASE("Map::Map(deque<string> info) general test 1", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1" };
	std::vector<int> d = { 1, 1 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 2", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "0 0", "1", "name1 0 0 0 0 0 0 0 0 tile1" };
	std::vector<int> d = { 0, 0 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 3", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "1 5", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1 name1 name1 name1 name1" };
	std::vector<int> d = { 1, 5 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 4", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "5 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1", "name1", "name1", "name1", "name1" };
	std::vector<int> d = { 5, 1 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 5", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "5 5", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1", "name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1", "name1 name1 name1 name1 name1" };
	std::vector<int> d = { 5, 5 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 6", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "0 17", "1", "name1 0 0 0 0 0 0 0 0 tile1"};
	std::vector<int> d = { 0, 0 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 7", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "17 0", "1", "name1 0 0 0 0 0 0 0 0 tile1" };
	std::vector<int> d = { 0, 0 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(deque<string> info) general test 8", "[Map::Map(deque<string> info)]"){
	//Test that this creates map with the correct dimension.

	std::deque<string> info = { "20 20", "1", "name1 0 0 0 0 0 0 0 0 tile1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1"
		, "name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1 name1" };
	std::vector<int> d = { 20, 20 };
	Map m = Map(info);
	REQUIRE(m.getDimention() == d);
}

//These correct for Correct TileTypes
TEST_CASE("Map::Map(deque<string> info) general test 9", "[Map::Map(deque<string> info)]"){
	//Test that this creates a map with the specified TileTypes

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1", };
	Map m = Map(info);

	std::vector<string> tile = { "name1", "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == tile.size());
}

TEST_CASE("Map::Map(deque<string> info) general test 10", "[Map::Map(deque<string> info)]"){
	//Test that this creates a map with the specified TileTypes

	std::deque<string> info = { "1 1", "0", "wall", };
	Map m = Map(info);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == tile.size());
}

TEST_CASE("Map::Map(deque<string> info) general test 11", "[Map::Map(deque<string> info)]"){
	//Test that this creates a map with the specified TileTypes

	std::deque<string> info = { "1 1", "5", "name1 0 0 0 0 0 0 0 0 tile1", "name2 0 0 0 0 0 0 0 0 tile2",
		 "name3 0 0 0 0 0 0 0 0 tile3", "name4 0 0 0 0 0 0 0 0 tile4", "name5 0 0 0 0 0 0 0 0 tile5", "name1", };
	Map m = Map(info);

	std::vector<string> tile = { "name1", "name2", "name3", "name4", "name5", "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == tile.size());
}

TEST_CASE("Map::Map(deque<string> info) general test 12", "[Map::Map(deque<string> info)]"){
	//Test that this creates a map with the specified TileTypes

	std::deque<string> info = { "1 0", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1", };
	Map m = Map(info);

	std::vector<string> tile = {  };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == tile.size());
}

TEST_CASE("Map::Map(deque<string> info) general test 13", "[Map::Map(deque<string> info)]"){
	//Test that this creates a map with the specified TileTypes

	std::deque<string> info = { "0 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1", };
	Map m = Map(info);

	std::vector<string> tile = { };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == tile.size());
}

//These will test the map composition is correct
TEST_CASE("Map::Map(deque<string> info) general test 14", "[Map::Map(deque<string> info)]"){

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1", };
	Map m = Map(info);

	TileType t = TileType({ "name", "tileset" }, { "name1", "tile1" });
	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::Map(deque<string> info) general test 15", "[Map::Map(deque<string> info)]"){
	std::deque<string> info = { "10 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", 
		"name1", "name1", "name1", "name1", "name1", "name1", "name1", "name1", "name1", "name1" };
	Map m = Map(info);

	TileType t = TileType({ "name", "tileset" }, { "name1", "tile1" });
	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(2, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(4, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(8, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(9, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 1).getAll() != t.getAll());
	REQUIRE(m.getTile(201, 0).getAll() != t.getAll());
}

TEST_CASE("Map::Map(deque<string> info) general test 16", "[Map::Map(deque<string> info)]"){

	std::deque<string> info = { "1, 10", "1", "name1 0 0 0 0 0 0 0 0 tile1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1" };
	Map m = Map(info);

	TileType t = TileType({ "name", "tileset" }, { "name1", "tile1" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 4).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 6).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 8).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 10).getAll() != t.getAll());
	REQUIRE(m.getTile(0, 201).getAll() != t.getAll());
}

TEST_CASE("Map::Map(deque<string> info) general test 17", "[Map::Map(deque<string> info)]"){

	std::deque<string> info = { "10, 10", "1", "name1 0 0 0 0 0 0 0 0 tile1",
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1",
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", 
		"name1 name1 name1 name1 name1 name1 name1 name1 name1 name1", };
	Map m = Map(info);

	TileType t = TileType({ "name", "tileset" }, { "name1", "tile1" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(5, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(9, 0).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 5).getAll() == t.getAll());
	REQUIRE(m.getTile(0, 9).getAll() == t.getAll());
	REQUIRE(m.getTile(5, 5).getAll() == t.getAll());
	REQUIRE(m.getTile(9, 9).getAll() == t.getAll());
	REQUIRE(m.getTile(10, 0).getAll() != t.getAll());
	REQUIRE(m.getTile(0, 10).getAll() != t.getAll());
	
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::addTile(string par) general test 1", "[Map::setTile(string par)]"){
	//Test adding to a map with no custom maps

	std::deque<string> info = { "1 1", "0", "wall" };
	Map m = Map(info);

	std::vector<std::string> v = { "name1", "wall" };
	m.addTile("name1 0 0 0 0 0 0 0 0 tile1");
	REQUIRE(m.getTiles() == v);
}

TEST_CASE("Map::addTile(string par) general test 2", "[Map::setTile(string par)]"){
	//Test adding to a map with some custom maps

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	std::vector<std::string> v = { "name1", "wall" };
	m.addTile("name1 0 0 0 0 0 0 0 0 tile1");

	REQUIRE(m.getTiles() == v);

}

TEST_CASE("Map::addTile(string par) general test 3", "[Map::setTile(string par)]"){
	//Test a TileType may be added to a map with that TileType already

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	m.addTile(t);

	std::vector<std::string> v = { "name1", "wall" };

	REQUIRE(m.getTiles() == v);

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::addTile(TileType tile) general test 1", "[Map::addTile(TileType tile)]"){
	//Test a TileType may be added to a map with no Tiles

	std::deque<string> info = { "1 1", "0", "wall" };
	Map m = Map(info);

	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	m.addTile(t);

	std::vector<std::string> v = { "name1", "wall" };

	REQUIRE(m.getTiles() == v);
}

TEST_CASE("Map::addTile(TileType tile) general test 2", "[Map::addTile(TileType tile)]"){
	//Test a TileType may be added to a map with Tiles

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	TileType t = TileType({ "all" }, { "name2 0 0 0 0 0 0 0 0 tile2" });
	m.addTile(t);

	std::vector<std::string> v = { "name1", "name2", "wall" };

	REQUIRE(m.getTiles() == v);

}

TEST_CASE("Map::addTile(TileType tile) general test 3", "[Map::addTile(TileType tile)]"){
	//Test a TileType may be added to a map with that TileType already

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	m.addTile(t);

	std::vector<std::string> v = { "name1", "wall" };

	REQUIRE(m.getTiles() == v);

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setSpace(int xCord, int yCord, string setSpace) general test 1", "[Map::setSpace(int xCord, int yCord, string setSpace)]"){
	//Test that it is possible to set a tile to wall
	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1" };
	Map m = Map(info);
	TileType t = TileType({ "name" }, { "wall" });

	m.setSpace(0, 0, "wall");
	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::setSpace(int xCord, int yCord, string setSpace) general test 2", "[Map::setSpace(int xCord, int yCord, string setSpace)]"){
	//Test that it is possible to set a tile to a Type made via map construction
	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);
	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });

	m.setSpace(0, 0, "name1");
	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::setSpace(int xCord, int yCord, string setSpace) general test 3", "[Map::setSpace(int xCord, int yCord, string setSpace)]"){
	//Test that it is possible to set a tile to a Type made after map construction

	std::deque<string> info = { "1 1", "0", "wall" };

	Map m = Map(info);
	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	m.addTile("name1 0 0 0 0 0 0 0 0 tile1");

	m.setSpace(0, 0, "name1");
	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setSpaces(int xCord, vector<string> spaces) general test 1", "[Map::setSpaces(int xCord, vector<string> spaces)]"){
	//Test its possible to set all tiles to the default wall

	std::deque<string> info = { "5 5", "1", "name1 0 0 0 0 0 0 0 0 tile1", 
		"name1, name1, name1, name1, name1",
		"name1, name1, name1, name1, name1", 
		"name1, name1, name1, name1, name1", 
		"name1, name1, name1, name1, name1", 
		"name1, name1, name1, name1, name1", };

	Map m = Map(info);
	TileType t = TileType({ "name" }, { "wall" });
	std::vector<std::string> v = { "wall", "wall", "wall", "wall", "wall" };

	m.setSpaces(0, v);
	m.setSpaces(1, v);
	m.setSpaces(2, v);

	REQUIRE(m.getTile(0, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(2, 2).getAll() == t.getAll());
}

TEST_CASE("Map::setSpaces(int xCord, vector<string> spaces) general test 2", "[Map::setSpaces(int xCord, vector<string> spaces)]"){
	//Test its possible to set all tiles to a tile made on construction

	std::deque<string> info = { "5 5", "1", "name1 0 0 0 0 0 0 0 0 tile1",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall" };

	Map m = Map(info);
	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	std::vector<std::string> v = { "name1", "name1", "name1", "name1", "name1" };

	m.setSpaces(0, v);
	m.setSpaces(1, v);
	m.setSpaces(2, v);

	REQUIRE(m.getTile(0, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(2, 2).getAll() == t.getAll());

}

TEST_CASE("Map::setSpaces(int xCord, vector<string> spaces) general test 3", "[Map::setSpaces(int xCord, vector<string> spaces)]"){
	//Test its possible to set all tiles to a tile made after construction
	std::deque<string> info = { "5 5", "0",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall",
		"wall, wall, wall, wall, wall" };

	Map m = Map(info);
	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });
	m.addTile(t);
	std::vector<std::string> v = { "name1", "name1", "name1", "name1", "name1" };

	m.setSpaces(0, v);
	m.setSpaces(1, v);
	m.setSpaces(2, v);

	REQUIRE(m.getTile(0, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(1, 2).getAll() == t.getAll());
	REQUIRE(m.getTile(2, 2).getAll() == t.getAll());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setEncounterCode(int encounter) general test 1", "[Map::setEncounterCode(int encounter)]"){
	//Test is the encounter code is set

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	m.setEncounterCode(10);
	REQUIRE(m.getEncounterCode() == 10);

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getTile(int x, int y) general test 1", "[Map::getTile(int x, int y)]"){
	//Test will return the default wall

	std::deque<string> info = { "1 1", "0", "wall" };
	Map m = Map(info);

	TileType t = TileType({ "name" }, { "wall" });

	REQUIRE(m.getTile(0,0).getAll() == t.getAll());
}

TEST_CASE("Map::getTile(int x, int y) general test 2", "[Map::getTile(int x, int y)]"){
	//Test will return a custom Type

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1" };	
	Map m = Map(info);

	TileType t = TileType({ "all" }, { "name1 0 0 0 0 0 0 0 0 tile1" });

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}

TEST_CASE("Map::getTile(int x, int y) general test 3", "[Map::getTile(int x, int y)]"){
	//Test will return a blank Type

	Map m = Map(0, 0);

	TileType t = TileType({}, {});

	REQUIRE(m.getTile(0, 0).getAll() == t.getAll());
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getDimention() general test 1", "[Map::getDimention()]"){
	//tests a map with a set dimension

	Map m = Map(4, 4);
	std::vector<int> v = { 4, 4 };
	REQUIRE(m.getDimention() == v);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getTiles() general test 1", "[Map::getTiles()]"){
	//Tests with several pre-made Types

	std::deque<string> info = { "1 1", "2", "name1 0 0 0 0 0 0 0 0 tile1", "name2 0 0 0 0 0 0 0 0 tile2", "name1" };
	Map m = Map(info);

	std::vector<std::string> v = { "name1", "name2", "wall" };

	REQUIRE(m.getTiles() == v);
}

TEST_CASE("Map::getTiles() general test 2", "[Map::getTiles()]"){
	//Tests with no pre-made types

	std::deque<string> info = { "1 1", "0", "wall"};
	Map m = Map(info);

	std::vector<std::string> v = { "wall"};

	REQUIRE(m.getTiles() == v);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::empty() general test 1", "[Map::empty()]"){
	//tests on an empty map

	Map m = Map(0, 0);

	REQUIRE(m.empty() == true);
}


TEST_CASE("Map::empty() general test 2", "[Map::empty()]"){
	//tests on a not empty map

	Map m = Map(1, 1);

	REQUIRE(m.empty() == false);
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

//100th test case. woo.
TEST_CASE("Map::readTile(string par) general test 1", "[Map::readTile(string par)]"){
	//Test with valid tile
	Map m = Map(1, 1);

	m.readTile("name1 0 0 0 0 0 0 0 0 tile1");

	std::vector<std::string> v = { "name1", "wall" };
	
	REQUIRE(m.getTiles() == v);
}

TEST_CASE("Map::readTile(string par) general test 2", "[Map::readTile(string par)]"){
	//Test with invalid tile
	Map m = Map(1, 1);

	m.readTile("name1 one 0 0 0 0 0 0 0 tile1");

	std::vector<std::string> v = { "wall" };

	REQUIRE(m.getTiles() == v);
}

TEST_CASE("Map::readTile(string par) general test 3", "[Map::readTile(string par)]"){
	//Test with already existing tile
	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "name1" };
	Map m = Map(info);

	m.readTile("name1 0 0 0 0 0 0 0 0 tile1");

	std::vector<std::string> v = { "name1", "wall" };

	REQUIRE(m.getTiles() == v);
}