#pragma once

#include "StandartEnemy.h"

//-------------------------------------------------
StandartEnemy::StandartEnemy() : Enemy() {}

//-------------------------------------------------
StandartEnemy::StandartEnemy(ObjectType t, const sf::Vector2f& p)
	: Enemy(t, p) {}

//-------------------------------------------------
void StandartEnemy::move(const Map& map) {
	int way = rand() % 4 + 1;
	switch (way) {
	case 1:
		if (if_can_move(map, 'U')) {
			m_position.y -= SPEED;
			get_on_floor(map);
		}
		break;
	case 2:
		if (if_can_move(map, 'D')) {
			m_position.y += SPEED;
			get_on_floor(map);
		}
		break;
	case 3:
		if (if_can_move(map, 'L')) {
			m_position.x -= SPEED;
			get_on_floor(map);
		}
		break;
	case 4:
		if (if_can_move(map, 'R')) {
			m_position.x += SPEED;
			get_on_floor(map);
		}
		break;
	}
}