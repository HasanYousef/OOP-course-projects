
#pragma once

#include "MoveableObject.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
MoveableObject::MoveableObject() {}

//-------------------------------------------------
MoveableObject::MoveableObject(ObjectType type,
	                        const sf::Vector2f& p)
	                  : WorldObject(type, p) {}

//-------------------------------------------------
void MoveableObject::move(const Map& map) {}
