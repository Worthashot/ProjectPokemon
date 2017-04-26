#include "catch.hpp"
#include "TileType.h"
using namespace std;



TEST_CASE("Test setting TileType with basic paramaters", "[TileType_create]") {
	TileType t1 = TileType();
	vector<string> v1{ "name1", "0", "0", "0", "0", "0", "0", "0", "0", "tile1" };
	t1.setAll("name1", 0, 0, 0, 0, 0, 0, 0, 0, "tile1");
	REQUIRE(t1.getAll() == v1);

	TileType t2 = TileType();
	vector<string> v2 = { "name2", "1", "1", "1", "1", "1", "1", "122", "132", "tile2" };
	t2.setAll("name2", 1, 1, 1, 1, 1, 1, 122, 132, "tile2");
	REQUIRE(t2.getAll() == v2);


	TileType t3 = TileType();
	vector<string> v3 = { "name3", "0", "0", "0", "0", "0", "0", "0", "0", "tile3" };
	t3.setAll(v3);
	REQUIRE(t3.getAll() == v3);


	TileType t4 = TileType();
	vector<string> v4 = { "name4", "1", "1", "1", "1", "1", "1", "122", "122", "tile4" };
	t4.setAll(v4);
	REQUIRE(t4.getAll() == v4);
}


