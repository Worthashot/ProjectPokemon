#include "catch.hpp"
#include "Map.h"
#include "MapList.h"
#include <iostream>
using namespace std;

TEST_CASE("map is assigned", "[map]") {
	Map m = Map(1, 1);

	TileType t = TileType();
	t.setAll("test", 0, 0, 0, 0, 0, 0, 0, 0, "test");
	m.addTile(t.getName(), t);

	m.setSpaces(0, vector<string>(1, "test"));

	REQUIRE(m.getTile(0, 0) == t.getName());
	string junk;
	cin >> junk;
}



