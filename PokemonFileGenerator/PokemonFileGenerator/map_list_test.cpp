#pragma once
#include <direct.h>
#include "catch.hpp"
#include "MapList.h"
#include <iostream>
#include <fstream>
using namespace std;

TEST_CASE("Test getting correct information from a file 1", "[MapList_create1]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string test1Folder = (string)buffer + "test 1\\";
	_mkdir(test1Folder.c_str());
	ofstream h1(test1Folder + "header.txt");
	h1 << "test1_1\ntest1_2";
	h1.close();

	ofstream t1_1(test1Folder + "test1_1.txt");
	t1_1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t1_1.close();

	ofstream t1_2(test1Folder + "test1_2.txt");
	t1_2 << "5 5\n5\nt1 1 1 1 1 1 1 1 1 ts1\nt2 1 1 1 1 1 1 1 1 ts2\nt3 1 1 1 1 1 1 1 1 ts3\nt4 1 1 1 1 1 1 1 1 ts4\nt5 1 1 1 1 1 1 1 1 ts5\nt1 t2 t3 t4 t5\nt1 t5 t4 t1 t2\nt2 t1 t3 t1 t4\nt3 t1 t4 t3 t5\nt1 t1 t1 t5 t1";
	t1_2.close();

	MapList test1 = MapList(test1Folder);
	vector<string> v1_list{ "test1_1", "test1_2" };
	vector<string> v1_1{ "t1", "1", "1", "1", "1", "1", "1", "1", "1", "ts1" };
	vector<string> v1_2{ "t2", "1", "1", "1", "1", "1", "1", "1", "1", "ts2" };
	vector<string> v1_3{ "t3", "1", "1", "1", "1", "1", "1", "1", "1", "ts3" };
	vector<string> v1_4{ "t4", "1", "1", "1", "1", "1", "1", "1", "1", "ts4" };
	vector<string> v1_5{ "t5", "1", "1", "1", "1", "1", "1", "1", "1", "ts5" };

	REQUIRE(test1.getMap("test1_1")->getTile(1, 1).getAll() == v1_1);
	REQUIRE(test1.getMap("test1_2")->getTile(0, 0).getAll() == v1_1);
	REQUIRE(test1.getMap("test1_2")->getTile(1, 4).getAll() == v1_2);
	REQUIRE(test1.getMap("test1_2")->getTile(2, 2).getAll() == v1_3);
	REQUIRE(test1.getMap("test1_2")->getTile(3, 2).getAll() == v1_4);
	REQUIRE(test1.getMap("test1_2")->getTile(4, 3).getAll() == v1_5);
	REQUIRE(test1.mapCount() == 2);
	REQUIRE(test1.listOfMaps() == v1_list);
	_rmdir(test1Folder.c_str());
}

TEST_CASE("Test getting correct information from a file 2", "[MapList_create2]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string test2Folder = (string)buffer + "test 2\\";
	_mkdir(test2Folder.c_str());

	ofstream h2(test2Folder + "header.txt");
	h2 << "test2_1";
	h2.close();

	ofstream t2_1(test2Folder + "test2_1.txt");
	t2_1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t2_1.close();

	MapList test2 = MapList(test2Folder);
	vector<string> v2_list{ "test2_1" };
	REQUIRE(test2.mapCount() == 1);
	REQUIRE(test2.listOfMaps() == v2_list);
	_rmdir(test2Folder.c_str());
}

TEST_CASE("Test getting correct information from a file 3", "[MapList_create3]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string test3Folder = (string)buffer + "test 3\\";
	_mkdir(test3Folder.c_str());

	ofstream h3(test3Folder + "header.txt");
	h3 << "";
	h3.close();

	MapList test3 = MapList(test3Folder);
	vector<string> v3_list{  };
	REQUIRE(test3.mapCount() == 0);
	REQUIRE(test3.listOfMaps() == v3_list);

}
	/*
	ofstream h3("header test3.txt");
	h2 << "";
	h2.close();

	MapList test3 = MapList("header test3");
	vector<string> v3_list{ "" };
	REQUIRE(test3.mapCount() == 0);
	REQUIRE(test3.listOfMaps() == v3_list);
	*/

TEST_CASE("Test getting correct information from a file 4", "[MapList_create4]"){
	char buffer[_MAX_PATH];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	string test4Folder = (string)buffer + "test 4\\";
	_mkdir(test4Folder.c_str());

	ofstream h4(test4Folder + "header.txt");
	h4 << "test4_1\ntest4_2\ntest4_3\ntest4_4\ntest4_5\ntest4_6";
	h4.close();

	ofstream t4_1(test4Folder + "test4_1.txt");
	t4_1 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_1.close();

	ofstream t4_2(test4Folder + "test4_2.txt");
	t4_2 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_2.close();

	ofstream t4_3(test4Folder + "test4_3.txt");
	t4_3 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_3.close();

	ofstream t4_4(test4Folder + "test4_4.txt");
	t4_4 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_4.close();

	ofstream t4_5(test4Folder + "test4_5.txt");
	t4_5 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_5.close();

	ofstream t4_6(test4Folder + "test4_6.txt");
	t4_6 << "5 5\n1\nt1 1 1 1 1 1 1 1 1 ts1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1\nt1 t1 t1 t1 t1";
	t4_6.close();

	MapList test4 = MapList(test4Folder);
	vector<string> v4_list{ "test4_1","test4_2","test4_3","test4_4","test4_5","test4_6" };
	REQUIRE(test4.mapCount() == 6);
	REQUIRE(test4.listOfMaps() == v4_list);

	_rmdir(test4Folder.c_str());

}

//frst draft file format
//first line number of dimensions
//second line, number of custom times (n)
//next n lines, the custom tiles
//next x tiles, each y tile
