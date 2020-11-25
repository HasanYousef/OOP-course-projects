#pragma once

#include "coord.h"
#include "Macros.h"
#include "Board.h"

class Enemy {
public:
	//---Constructors-------
	Enemy() : m_Ecoord() {}
	Enemy(const Coord& coord) : m_Ecoord(coord) {}
	//---functions----------
	Coord Enemy_Movement();
	Coord Get_E_Coord() const;
private:
	//---enemy-indexes-----
	Coord m_Ecoord;
};
