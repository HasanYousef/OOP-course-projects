#pragma once

#include <SFML/Graphics.hpp>
#include <Enemy.h>

#include "macros.h"

class StupidEnemy: public Enemy {
public:
	//---Constructors---------------------
	StupidEnemy();
	StupidEnemy(ObjectType, const sf::Vector2f&);
	//---functions--------------
	virtual void move(const Map&);
private:
	bool m_goLeft = false;
};
