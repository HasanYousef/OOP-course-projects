#pragma once

#include <conio.h>

#include "io.h"
#include "coord.h"
#include "Macros.h"
#include "Board.h"

class Player {
public:
	Player() : m_coord(), m_health(INIT_HEALTH) {}
	Player(const Coord& coord) : m_coord(coord), m_health(INIT_HEALTH) {}
	Coord get_coord();
	Coord move(const Board&);
	int get_health() const;
	void die();
private:
	int m_health;
	Coord m_coord;
	//---help-functions-------------------
	bool is_wall(int, int, const Board&);
};
