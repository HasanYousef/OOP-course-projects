#pragma once

#include <cmath>

#include "Enemy.h"

class SmartEnemy : public Enemy {
public:
	SmartEnemy();
	SmartEnemy(ObjectType, const sf::Vector2f&);
	virtual void move(const Map&, const sf::Vector2f&);
	char moveDir(const Map&, const sf::Vector2f&);
};