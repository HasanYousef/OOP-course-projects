#pragma once
//---Include-----
#include "io.h"
#include "coord.h"
#include "Macros.h"
#include "Board.h"
#include "io.h"
//---------------
class Player {
public:
	Player() : m_coord(), m_health(INIT_HEALTH) {}
	Player(const Coord& coord) : m_coord(coord), m_health(INIT_HEALTH) {}
	Coord Player_Movement(const Board&);
	bool is_wall(int, int,const Board&);
	int get_lives() const;
	void die();
	void set_life();
private:
	int m_health;
	Coord m_coord;
};
