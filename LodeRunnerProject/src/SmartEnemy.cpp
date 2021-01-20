#pragma once
#include "SmartEnemy.h"

//-----------------------------------------------
SmartEnemy::SmartEnemy() : Enemy() {}

//-----------------------------------------------
SmartEnemy::SmartEnemy(ObjectType t,
	const sf::Vector2f& p)
	: Enemy(t, p) {}

//-----------------------------------------------
void SmartEnemy::move(const Map& map) {
	
}
