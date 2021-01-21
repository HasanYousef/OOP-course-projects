#pragma once
#include "SmartEnemy.h"

//-----------------------------------------------
SmartEnemy::SmartEnemy() : Enemy() {}

//-----------------------------------------------
SmartEnemy::SmartEnemy(ObjectType t,
	const sf::Vector2f& p)
	: Enemy(t, p) {}

void SmartEnemy::move(const Map& map, const sf::Vector2f& playerPos) {
	switch (moveDir(map, playerPos)) {
	case 'U':
		if (if_can_move(map, 'U')) {
			m_position.y -= SPEED;
		}
		break;
	case 'D':
		if (if_can_move(map, 'D')) {
			m_position.y += SPEED;
		}
		break;
	case 'L':
		if (if_can_move(map, 'L')) {
			m_position.x -= SPEED;
		}
		break;
	case 'R':
		if (if_can_move(map, 'R')) {
			m_position.x += SPEED;
		}
		break;
	}
}

//-----------------------------------------------
char SmartEnemy::moveDir(const Map& map, const sf::Vector2f& playerPos)
{
	float horizontalDistance = std::abs(m_position.x - playerPos.x),
		verticalDistance = std::abs(m_position.y - playerPos.y);
	// in this case the enemy will try to reach teh player height level
	if (verticalDistance > horizontalDistance) {
		// if the player is higher than the enemy
		if (playerPos.y < m_position.y) {
			if (if_can_move(map, 'U'))
				m_dir = 'U';
		}
		// if the enemy is higher than the enemy
		else {
			if (if_can_move(map, 'D'))
				m_dir =  'D';
		}
		// change direction
		if (!if_can_move(map, m_dir)) {
			if (m_dir == 'R')
				m_dir = 'L';
			else
				m_dir = 'R';
		}
	}
	// if the player and the enemy are in the same height level
	else {
		// player in the right
		if (m_position.x > playerPos.x)
			if (if_can_move(map, 'R'))
				m_dir = 'R';
		m_dir = 'L';
	}
	return m_dir;
}
