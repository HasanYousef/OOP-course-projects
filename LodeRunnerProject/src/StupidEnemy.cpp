#pragma once
#include "StupidEnemy.h"

//-----------------------------------------------
StupidEnemy::StupidEnemy() : Enemy() {}

//-----------------------------------------------
StupidEnemy::StupidEnemy(ObjectType t,
	const sf::Vector2f& p)
	: Enemy(t, p) {}

//-----------------------------------------------
void StupidEnemy::move(const Map& map) {
	switch (m_goLeft) {
	case true:
		if (map.get_type({ get_position().x + TEXTURE_SIZE, 
			               get_position().y + TEXTURE_SIZE }) == O_Wall
			&& map.get_type({ get_position().x + TEXTURE_SIZE,
				              get_position().y }) != O_Wall) {
			m_position.x += SPEED;
			break;
		}
		m_goLeft = false;
		break;
	case false:
		if (map.get_type({ m_position.x - TEXTURE_SIZE, m_position.y }) != O_Wall) {
			if (map.get_type({ m_position.x - (TEXTURE_SIZE / 2),m_position.y - (TEXTURE_SIZE / 2) }) == O_Wall)
			{
				m_position.x -= SPEED;
				break;
			}
		}
		m_goLeft = true;
		break;
	}
}


