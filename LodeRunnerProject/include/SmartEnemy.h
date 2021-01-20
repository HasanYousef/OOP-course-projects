#pragma once

#include "Enemy.h"

class SmartEnemy : public Enemy {
public:
	SmartEnemy();
	SmartEnemy(ObjectType, const sf::Vector2f&);
	virtual void move(const Map&);
};