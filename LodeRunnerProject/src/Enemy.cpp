#pragma once

#include "Enemy.h"

//-------------------------------------------------
Enemy::Enemy(ObjectType type,
	const sf::Vector2f& p, int iq)
	: MoveableObject(type, p) {}
