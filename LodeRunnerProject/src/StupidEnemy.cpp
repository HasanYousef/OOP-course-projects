#pragma once
#include "StupidEnemy.h"

//-----------------------------------------------
StupidEnemy::StupidEnemy() : Enemy() {}

//-----------------------------------------------
StupidEnemy::StupidEnemy(ObjectType t,
	const sf::Vector2f& p)
	: Enemy(t, p) {}

//-----------------------------------------------
void StupidEnemy::move(const Map& map, const sf::Vector2f& playerPos) {
	switch (m_goLeft) {
	case true:
		if (if_can_move(map, 'R')) {
			m_position.x += SPEED;
			break;
		}
		m_goLeft = false;
		break;
	case false:
		if (if_can_move(map, 'L'))
		{
			m_position.x -= SPEED;
			break;
		}
		m_goLeft = true;
		break;
	}
}


