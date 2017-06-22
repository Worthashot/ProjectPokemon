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


TEST_CASE("Map::setTile(string par) general test", "[Map::setTile(string par)]"){

}

TEST_CASE("Map::setTile(string par) general test 1", "[Map::setTile(string par)]"){
	//Test adding to a map with no custom maps

	std::deque<string> info = { "1 1", "0", "wall" };
	Map m = Map(info);

	std::vector<std::string> v = { "name1", "wall" };
	m.setTile("name1 0 0 0 0 0 0 0 0 tile1");
	REQUIRE(m.getTiles() == v);
}


TEST_CASE("Map::setTile(string par) general test 2", "[Map::setTile(string par)]"){
	//Test adding to a map with some custom maps

	std::deque<string> info = { "1 1", "1", "name1 0 0 0 0 0 0 0 0 tile1", "wall" };
	Map m = Map(info);

	std::vector<std::string> v = { "name1", "name2", "wall" };
	m.setTile("name2 0 0 0 0 0 0 0 0 tile2");
	REQUIRE(m.getTiles() == v);

}




//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setSpace(int xCord, int yCord, string setSpace) general test", "[Map::setSpace(int xCord, int yCord, string setSpace)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setSpaces(int xCord, vector<string> spaces) general test", "[Map::setSpaces(int xCord, vector<string> spaces)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::setEncounterCode(int encounter) general test", "[Map::setEncounterCode(int encounter)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::addTile(TileType tile) general test", "[Map::addTile(TileType tile)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getTile(int x, int y) general test", "[Map::getTile(int x, int y)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getDimention() general test", "[Map::getDimention()]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::getTiles() general test", "[Map::getTiles()]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::empty() general test", "[Map::empty()]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::readTile(string par) general test", "[Map::readTile(string par)]"){

}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("test creating a map with custom tiles", "[Map_create]"){
	std::cout << "creating Map";
	Map m1 = Map(5, 5);
	TileType t1, t2, t3, t4, t5 = TileType();
	vector<string> v1{ "name1", "0", "0", "0", "0", "0", "0", "0", "0", "tile1" };
	vector<string> v2 = { "name2", "1", "1", "1", "1", "1", "1", "122", "132", "tile2" };
	vector<string> v3 = { "name3", "0", "0", "0", "0", "0", "0", "0", "0", "tile3" };
	vector<string> v4 = { "name4", "1", "1", "1", "1", "1", "1", "122", "122", "tile4" };
	vector<string> v5 = { "name5", "1", "1", "1", "1", "1", "1", "122", "122", "tile5" };
	t1.setAll(v1);
	t2.setAll(v2);
	t3.setAll(v3);
	t4.setAll(v4);
	t5.setAll(v5);
	m1.addTile(t1);
	m1.addTile(t2);
	m1.addTile(t3);
	m1.addTile(t4);
	m1.addTile(t5);


	REQUIRE(m1.getTile(0, 0).getName() == "wall");
	m1.setSpace(0, 0, "name1");
	REQUIRE(m1.getTile(0, 0).getAll() == v1);

	m1.setSpace(1, 3, "name2");
	REQUIRE(m1.getTile(1, 3).getAll() == v2);
	m1.setSpace(1, 3, "name3");
	REQUIRE(m1.getTile(1, 3).getAll() == v3);

	m1.setSpace(4, 4, "name4");
	REQUIRE(m1.getTile(4, 4).getAll() == v4);

	m1.setSpaces(2, vector<string>(5, "name5"));
	REQUIRE(m1.getTile(2, 0).getAll() == v5);
	REQUIRE(m1.getTile(2, 1).getAll() == v5);
	REQUIRE(m1.getTile(2, 2).getAll() == v5);
	REQUIRE(m1.getTile(2, 3).getAll() == v5);
	REQUIRE(m1.getTile(2, 4).getAll() == v5);

	m1.setSpace(3, 1, "notExisting");
	REQUIRE(m1.getTile(3, 1).getName() == "wall");


}