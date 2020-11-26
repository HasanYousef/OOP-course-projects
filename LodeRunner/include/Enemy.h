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
	Coord move(const Board& board, const Coord& coord);
	Coord get_coord() const;
private:
	bool there_is_laddder(const Board& board, int dir);
	//---enemy-indexes-----
	Coord m_coord;
};
