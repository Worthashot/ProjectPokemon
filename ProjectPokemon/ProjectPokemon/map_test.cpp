#include "catch.hpp"
#include "Map.h"
using namespace std;

TEST_CASE("test creating a map with custom tiles", "[Map_create]"){
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