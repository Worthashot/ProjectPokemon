#pragma once
#include "catch.hpp"
#include "TileType.h""


TEST_CASE("TileType::TileType() general test", "[TileType::TileType()]"){
	//Tests that all paramaters are set to nothing
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments) test set to nothing", "[TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments)]"){
	//Tests all paramaters are set to nothing
}


TEST_CASE("TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments) test set to something", "[TileType::TileType(std::vector<std::string> commands, std::vector<std::string> arguments)]"){
	//Tests all paramaters are set something
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::setAll(string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, string tileset) test set to something", "[TileType::setAll(string name, int passable, int surfable, int doorway, int talkable, int pushable, int cutable, int location, int person, string tileset)]"){
	//Tests all paramaters are set to something
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::setAll(vector<string> par) tests set to something", "[TileType::setAll(vector<string> par)]"){
	//Tests all paramaters are set to something
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set name", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}


TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set passable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set surfable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set doorway", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set talkable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set pushable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set cutable", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set location", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set person", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}



TEST_CASE("TileType::assignAsSpecified(string command, string argument) test set tileset", "[TileType::assignAsSpecified(string command, string argument)]"){
	//tests the name paramater is set
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::getAll() test all returned", "[TileType::getAll()]"){
	//Tests that all the paramaters of a TileType are returned
}


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


TEST_CASE("TileType::testValidTileType(string line) test wrong size", "[TileType::testValidTileType(string line)]"){
	//Tests a string with too many sub-strings returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 2", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as second substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 3", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as third substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 4", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as fourth substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 5", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as fith substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 6", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as sixth substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 7", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as seventh substring returns false
}


TEST_CASE("TileType::testValidTileType(string line) test wrong pos 8", "[TileType::testValidTileType(string line)]"){
	//Tests a string with no integer as eighth substring returns false
}



TEST_CASE("TileType::testValidTileType(string line) test correct", "[TileType::testValidTileType(string line)]"){
	//Tests a propperly formatted string returns true
}