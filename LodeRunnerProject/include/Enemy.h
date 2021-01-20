#pragma once

#include <SFML/Graphics.hpp>
#include <MoveableObject.h>

class Enemy : public MoveableObject {
public:
	Enemy() {};
	Enemy(ObjectType, const sf::Vector2f&);
	virtual void move(const Map&) = 0;
};