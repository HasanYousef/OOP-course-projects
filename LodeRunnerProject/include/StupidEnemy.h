#pragma once

#include "Enemy.h"
#include "macros.h"

class StupidEnemy : public Enemy {
public:
	//---Constructors---------------------
	StupidEnemy();
	StupidEnemy(ObjectType, const sf::Vector2f&, int);
	//---functions--------------
	void move(const Map&);
private:
	bool m_goLeft = false;
};
