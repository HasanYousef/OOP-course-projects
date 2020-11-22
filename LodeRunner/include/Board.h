#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Macros.h"
#include "Coord.h"

//Board class stores a 2d array of chars that picture a level's map
class Board
{
public:
	Board() : m_size(0) {}	//deffault structor
	Board(ifstream&);
	Board(const Board&);
	void print();
	char get_char(const Coord&) const;
	Coord get_ground(const Coord&) const;
	void set_char(const Coord&, char);
	int get_size() const;
private:
	int m_size;						//the size of the 2d array (NxN)
	vector <vector<char>> m_map;	//the 2d array
};
