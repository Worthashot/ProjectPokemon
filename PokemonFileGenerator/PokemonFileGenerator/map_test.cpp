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

TEST_CASE("Map::Map(int xDim, int Ydim) general test 1", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 0);
	std::vector<int> d = { 0, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 2", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(5, 5);
	std::vector<int> d = { 5, 5 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 3", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 150);
	std::vector<int> d = { 150, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 4", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(2, 7);
	std::vector<int> d = { 2, 7 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 5", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(0, 17);
	std::vector<int> d = { 0, 17 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 6", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(17, 0);
	std::vector<int> d = { 17, 0 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 7", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(1, 150);
	std::vector<int> d = { 1, 150 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 8", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates map with the correct dimension.
	Map m = Map(150, 1);
	std::vector<int> d = { 150, 1 };
	REQUIRE(m.getDimention() == d);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 9", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 10", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(0, 17);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 11", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(17, 0);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}

TEST_CASE("Map::Map(int xDim, int Ydim) general test 12", "[Map::Map(int xDim, int Ydim)]"){
	//Test that this creates a map with only a wall TileType
	Map m = Map(170, 170);

	std::vector<string> tile = { "wall" };

	REQUIRE(m.getTiles() == tile);
	REQUIRE(m.getTiles().size() == 1);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("Map::Map(string xDimS, string yDimS) general test", "[Map(string xDimS, string yDimS)]"){
	//Test that this creates map with the correct dimension with each point being the correct TileType.
}

TEST_CASE("Map::Map(int xDim, int yDim, int encounter) general test", "[Map(int xDim, int yDim, int encounter)]"){
	//Test that this creates map with the correct dimension with each point being the correct TileType and sets the encounter code.
}

TEST_CASE("Map::Map(deque<string> info) general test", "[Map::Map(deque<string> info)]"){
	//Test that all information is read correctly from the queue and assigned.
}

TEST_CASE("Map::setTile(string par) general test", "[Map::setTile(string par)]"){

}

TEST_CASE("Map::setSpace(int xCord, int yCord, string setSpace) general test", "[Map::setSpace(int xCord, int yCord, string setSpace)]"){

}

TEST_CASE("Map::setSpaces(int xCord, vector<string> spaces) general test", "[Map::setSpaces(int xCord, vector<string> spaces)]"){

}

TEST_CASE("Map::setEncounterCode(int encounter) general test", "[Map::setEncounterCode(int encounter)]"){

}

TEST_CASE("Map::addTile(TileType tile) general test", "[Map::addTile(TileType tile)]"){

}

TEST_CASE("Map::getTile(int x, int y) general test", "[Map::getTile(int x, int y)]"){

}

TEST_CASE("Map::getDimention() general test", "[Map::getDimention()]"){

}

TEST_CASE("Map::getTiles() general test", "[Map::getTiles()]"){

}

TEST_CASE("Map::empty() general test", "[Map::empty()]"){

}

TEST_CASE("Map::readTile(string par) general test", "[Map::readTile(string par)]"){

}

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