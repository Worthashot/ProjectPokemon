#pragma once
#include "catch.hpp"
#include "TileType.h""


TEST_CASE("TileType::TileType() general test", "[TileType::TileType()]"){
	TileType t = TileType();
	std::vector<std::string> v = { "", "0", "0", "0", "0", "0", "0", "0", "0", "" };
	REQUIRE(t.getAll() == v);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments) test set to nothing", "[TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments)]"){
	//Tests all paramaters are set to nothing

	std::vector<std::string> v = { "", "0", "0", "0", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> e = {};
	TileType t = TileType(e, e);
	REQUIRE(t.getAll() == v);
}

TEST_CASE("TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments) test set to something 1", "[TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments)]"){
	//Tests all paramaters are set something

	std::vector<std::string> v2 = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile"};
	std::vector<std::string> v = { "name 1 1 1 1 1 1 1 1 tile" };
	std::vector<std::string> e = {"all"};
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments) test set to something 2", "[TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments)]"){
	//Tests only name is set something

	std::vector<std::string> v2 = { "name", "0", "0", "0", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "name" };
	std::vector<std::string> e = { "name" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::setAll(string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, string tileset) test set to something", "[TileType::setAll(string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, string tileset)]"){
	//Tests all paramaters are set to something

	TileType t = TileType();
	std::vector<std::string> v = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile" };
	t.setAll("name", 1, 1, 1, 1, 1, 1, 1, 1, "tile");
	REQUIRE(t.getAll() == v);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::setAll(vector<string> par) tests set to something", "[TileType::setAll(vector<string> par)]"){
	//Tests all paramaters are set to something

	TileType t = TileType();
	std::vector<std::string> v = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile" };
	t.setAll(v);
	REQUIRE(t.getAll() == v);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set name", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set

	std::vector<std::string> v2 = { "name", "0", "0", "0", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "name" };
	std::vector<std::string> e = { "name" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set passable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the passable paramater is set

	std::vector<std::string> v2 = { "", "1", "0", "0", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "passable" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set surfable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the surfable paramater is set

	std::vector<std::string> v2 = { "", "0", "1", "0", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "surfable" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);

}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set doorway", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the doorway paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "1", "0", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "doorway" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set talkable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the talkable paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "1", "0", "0", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "talkable" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set pushable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the pushable paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "0", "1", "0", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "pushable" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set cutable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the cutable paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "0", "0", "1", "0", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "cutable" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set location", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the location paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "0", "0", "0", "1", "0", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "location" };
	TileType t = TileType(e, v); 
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set person", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the person paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "0", "0", "0", "0", "1", "" };
	std::vector<std::string> v = { "1" };
	std::vector<std::string> e = { "person" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set tileset", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the tileset paramater is set

	std::vector<std::string> v2 = { "", "0", "0", "0", "0", "0", "0", "0", "0", "tile" };
	std::vector<std::string> v = { "tile" };
	std::vector<std::string> e = { "tileset" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2); 
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set all", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests every paramater is set

	std::vector<std::string> v2 = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile" };
	std::vector<std::string> v = { "name 1 1 1 1 1 1 1 1 tile" };
	std::vector<std::string> e = { "all" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}

TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set all individual", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests every paramater is set

	std::vector<std::string> v2 = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile" };
	std::vector<std::string> v = { "name", "1", "1", "1", "1", "1", "1", "1", "1", "tile" };
	std::vector<std::string> e = { "name", "passable", "surfable", "doorway", "talkable", "pushable", "cutable", "location", "person", "tileset" };
	TileType t = TileType(e, v);
	REQUIRE(t.getAll() == v2);
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::testValidTileType(string line) test wrong size", "[TileType::testValidTileType(string line)]"){
	//Tests a string with too many sub-strings returns false

	REQUIRE(TileType::testValidTileType("1 1 1 1 1 1 1 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 2", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as second substring returns false

	REQUIRE(TileType::testValidTileType("1 one 1 1 1 1 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 3", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as third substring returns false

	REQUIRE(TileType::testValidTileType("1 1 one 1 1 1 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 4", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as fourth substring returns false

	REQUIRE(TileType::testValidTileType("1 1 1 one 1 1 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 5", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as fith substring returns false

	REQUIRE(TileType::testValidTileType("1 1 1 1 one 1 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 6", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as sixth substring returns false

	REQUIRE(TileType::testValidTileType("1 1 1 1 1 one 1 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 7", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as seventh substring returns false

	REQUIRE(TileType::testValidTileType("1 1 1 1 1 1 one 1 1 1") == false);
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 8", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as eighth substring returns false

	REQUIRE(TileType::testValidTileType("1 1 1 1 1 1 1 one 1 1") == false);
}



TEST_CASE("TileType::testValidTileType(string line) test correct", "[TileType::testValidTileType(string line)]"){
	//Tests a propperly formatted string returns true

	REQUIRE(TileType::testValidTileType("1 1 1 1 1 1 1 1 1 1") == true);
}