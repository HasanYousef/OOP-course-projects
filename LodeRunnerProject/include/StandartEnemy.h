#pragma once

#include "macros.h"
#include "SFML/Graphics.hpp"

#include <Enemy.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class StandartEnemy: public Enemy {
public:
	StandartEnemy();
	StandartEnemy(ObjectType, const sf::Vector2f&);
	virtual void move(const Map&, const sf::Vector2f&);

private:
	int m_way = 1;
	sf::Clock m_timer;
};