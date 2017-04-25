#include "catch.hpp"
#include "Map.h"
#include "MapList.h"
#include <iostream>
#include<string>
using namespace std;

TEST_CASE("test creating a map with custom tiles", "[map_create]"){
	Map m1 = Map(5, 5);
	TileType t1, t2, t3, t4, t5 = TileType();
	t1.setName("t1");
	t2.setName("t2");
	t3.setName("t3");
	t4.setName("t4");
	t5.setName("t5");
	m1.addTile(t1);
	m1.addTile(t2);
	m1.addTile(t3);
	m1.addTile(t4);
	m1.addTile(t5);


	REQUIRE(m1.getTile(0, 0).getName() == "wall");
	m1.setSpace(0, 0, "t1");
	REQUIRE(m1.getTile(0, 0).getName() == "t1");
	m1.setSpace(1, 3, "t2");
	REQUIRE(m1.getTile(1, 3).getName() == "t2");
	m1.setSpace(1, 3, "t3");
	REQUIRE(m1.getTile(1, 3).getName() == "t3");
	m1.setSpace(4, 4, "t4");
	REQUIRE(m1.getTile(4, 4).getName() == "t4");
	m1.setSpaces(2, vector<string>(5, "t5"));
	REQUIRE(m1.getTile(2, 0).getName() == "t5");
	REQUIRE(m1.getTile(2, 1).getName() == "t5");
	REQUIRE(m1.getTile(2, 2).getName() == "t5");
	REQUIRE(m1.getTile(2, 3).getName() == "t5");
	REQUIRE(m1.getTile(2, 4).getName() == "t5");
	m1.setSpace(3, 1, "notExisting");
	REQUIRE(m1.getTile(3, 1).getName() == "wall");


}