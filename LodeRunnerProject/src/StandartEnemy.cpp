#pragma once

#include "StandartEnemy.h"

//-------------------------------------------------
StandartEnemy::StandartEnemy() : Enemy() {}

//-------------------------------------------------
StandartEnemy::StandartEnemy(ObjectType t, const sf::Vector2f& p)
	: Enemy(t, p) {}

//-------------------------------------------------
void StandartEnemy::move(const Map& map, const sf::Vector2f& playerPos) {
	if (m_timer.getElapsedTime().asSeconds() > 3) {
		m_timer.restart();
		int way = rand() % 4 + 1;
		while (way == m_way)
			way = rand() % 4 + 1;
		m_way = way;
	}
	switch (m_way) {
	case 1:
		if (if_can_move(map, 'U')) {
			m_dir = 'U';
			m_position.y -= SPEED;
		}
		break;
	case 2:
		if (if_can_move(map, 'D')) {
			m_dir = 'D';
			m_position.y += SPEED;
		}
		break;
	case 3:
		if (if_can_move(map, 'L')) {
			m_dir = 'L';
			m_position.x -= SPEED;
		}
		break;
	case 4:
		if (if_can_move(map, 'R')) {
			m_dir = 'R';
			m_position.x += SPEED;
		}
		break;
	}
}