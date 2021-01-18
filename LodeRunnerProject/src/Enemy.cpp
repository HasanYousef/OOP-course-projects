#pragma once

#include "Enemy.h"

//-------------------------------------------------
Enemy::Enemy(ObjectType type,
	const sf::Vector2f& p)
	: MoveableObject(type, p) {}
