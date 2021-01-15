#pragma once
#include "StupidEnemy.h"

//-----------------------------------------------
StupidEnemy::StupidEnemy() : Enemy() {}

//-----------------------------------------------
StupidEnemy::StupidEnemy(ObjectType type,
	sf::Texture* t, const sf::Vector2f& p, int iq)
	: Enemy(ObjectType type, const sf::Vector2f& p, int iq) {}

//-----------------------------------------------
void StupidEnemy::move(const Map& map) {
	switch (m_goLeft) {
	case true:
		if (map.get_type({ get_position().x + 16, get_position().y + 16 }) == O_Wall 
			&& map.get_type({ get_position().x + 16, get_position().y }) != O_Wall) {
			create().move(SPEED,0);
			set_position({ get_position().x + SPEED, get_position().y });
			break;
		}
		m_goLeft = false;
	case false:
		if (map.get_type({ get_position().x - 16, get_position().y - 16 }) == O_Wall
			&& map.get_type({ get_position().x - 16, get_position().y }) != O_Wall) {
			create().move(-SPEED, 0);
			set_position({ get_position().x - SPEED, get_position().y });
			break;
		}
		m_goLeft = true;
		break;
	}
}


