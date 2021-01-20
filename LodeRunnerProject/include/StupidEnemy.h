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
	virtual void move(const Map&, const sf::Vector2f&);
private:
	bool m_goLeft = true;
};
