#pragma once

#include "macros.h"
#include <Enemy.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class StandartEnemy: public Enemy {
public:
	StandartEnemy();
	StandartEnemy(ObjectType, const sf::Vector2f&);
	virtual void move(const Map&);
};