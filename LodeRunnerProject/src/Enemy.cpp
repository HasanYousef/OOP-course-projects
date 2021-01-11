#pragma once

#include "Enemy.h"

//-------------------------------------------------
Enemy::Enemy() : m_iq(STUPID) {}

//-------------------------------------------------
Enemy::Enemy(ObjectType type, sf::Texture* t,
	const sf::Vector2f& p, int iq)
	: MoveableObject(type, t, p), m_iq(iq) {}

//-------------------------------------------------
int Enemy::setIq(int iq) {
	m_iq = iq;
}

//-------------------------------------------------
//in this function we move the enemy, we check wich
//type is the enemy (smart, stupid, normal) and we
//choose the move function according to his type
void Enemy::move(const Map& map) {
	//we choose wich type of move we want
	switch (m_iq) {
	case STUPID: //stupid enemy
		stupidMove(map);
		break
	case SMART: //smart enemy
		smartMove(map);
		break;
	case NORMAL: //normal enemy
		normalMove(map);
		break;
	default:
		break;
	}
}
