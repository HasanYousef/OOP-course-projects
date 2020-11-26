#pragma once

#include "coord.h"
#include "Macros.h"
#include "Board.h"
#include <vector>

class Enemy {
public:
	//---Constructors-------
	Enemy() : m_coord() {}
	Enemy(const Coord& coord) : m_coord(coord) {}
	//---functions----------
	Coord move(const Board& board);
	Coord get_coord() const;
	int find_shortest_path(const Board& board, vector<vector<bool>>& helpBoard, const Coord& curr);
private:
	//---enemy-indexes-----
	Coord m_coord;
};
