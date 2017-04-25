#include "catch.hpp"
#include "TileType.h"
using namespace std;



TEST_CASE("Test setting TileType with basic paramaters", "[TileType_create]") {
	TileType t1 = TileType();
	t1.setAll("name1", 0, 0, 0, 0, 0, 0, 0, 0, "tile1");
	REQUIRE(t1.getName() == "name1");
	REQUIRE(t1.getPassable() == 0);
	REQUIRE(t1.getSurfable() == 0);
	REQUIRE(t1.getDoorway() == 0);
	REQUIRE(t1.getTalkable() == 0);
	REQUIRE(t1.getPushable() == 0);
	REQUIRE(t1.getCutable() == 0);
	REQUIRE(t1.getLocation() == 0);
	REQUIRE(t1.getPerson() == 0);
	REQUIRE(t1.getTileset() == "tile1");

	TileType t2 = TileType();
	t2.setAll("name2", 1, 1, 1, 1, 1, 1, 122, 132, "tile2");
	REQUIRE(t2.getName() == "name2");
	REQUIRE(t2.getPassable() == 1);
	REQUIRE(t2.getSurfable() == 1);
	REQUIRE(t2.getDoorway() == 1);
	REQUIRE(t2.getTalkable() == 1);
	REQUIRE(t2.getPushable() == 1);
	REQUIRE(t2.getCutable() == 1);
	REQUIRE(t2.getLocation() == 122);
	REQUIRE(t2.getPerson() == 132);
	REQUIRE(t2.getTileset() == "tile2");

	
	vector<string> v3 = {"name3","0","0","0","0","0","0","0","0","tile3"};
	TileType t3 = TileType();
	t3.setAll(v3);
	REQUIRE(t3.getName() == "name3");
	REQUIRE(t3.getPassable() == 0);
	REQUIRE(t3.getSurfable() == 0);
	REQUIRE(t3.getDoorway() == 0);
	REQUIRE(t3.getTalkable() == 0);
	REQUIRE(t3.getPushable() == 0);
	REQUIRE(t3.getCutable() == 0);
	REQUIRE(t3.getLocation() == 0);
	REQUIRE(t3.getPerson() == 0);
	REQUIRE(t3.getTileset() == "tile3");

	vector<string> v4 = { "name4", "1", "1", "1", "1", "1", "1", "122", "122", "tile4" };
	TileType t4 = TileType();
	t4.setAll(v4);
	REQUIRE(t4.getName() == "name4");
	REQUIRE(t4.getPassable() == 1);
	REQUIRE(t4.getSurfable() == 1);
	REQUIRE(t4.getDoorway() == 1);
	REQUIRE(t4.getTalkable() == 1);
	REQUIRE(t4.getPushable() == 1);
	REQUIRE(t4.getCutable() == 1);
	REQUIRE(t4.getLocation() == 122);
	REQUIRE(t4.getPerson() == 122);
	REQUIRE(t4.getTileset() == "tile4");
}



