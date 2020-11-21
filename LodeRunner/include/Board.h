#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Macros.h"

//Board class stores a 2d array of chars that picture a level's map
class Board
{
public:
	Board() : m_size(0), m_map(NULL) {}	//deffault structor
	Board(ifstream);
	void print();
	char get_char(int x, int y);
private:
	int m_size;						//the size of the 2d array (NxN)
	vector <vector<char>> m_map;	//the 2d array
};
