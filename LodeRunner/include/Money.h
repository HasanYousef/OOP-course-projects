#pragma once

#include "coord.h"
#include "Macros.h"
#include "Board.h"

struct Money {
	//---Constructors-------
	Money() : m_coord() {}
	Money(const Coord& coord) : m_coord(coord) {}
	//---money-index-----
	Coord m_coord = Coord();
	bool m_isTaken = false;
};
