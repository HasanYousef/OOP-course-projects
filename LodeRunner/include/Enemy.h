#pragma once

#include "coord.h"
#include "Macros.h"
#include "Board.h"

class Enemy {
public:
	//---Constructors-------
	Enemy() : m_coord() {}
	Enemy(const Coord& coord) : m_coord(coord) {}
	//---functions----------
	Coord move(const Board& board, const Coord& coord);
	Coord get_coord() const;
private:
	int ladder_dis(const Board& board, int dir);
	bool can_go_side(const Board& b, int dir);
	//---enemy-indexes-----
	Coord m_coord;
};
