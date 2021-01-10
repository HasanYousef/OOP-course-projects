
#pragma once

#include "MoveableObject.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
MoveableObject::MoveableObject() {}

//-------------------------------------------------
MoveableObject::MoveableObject(ObjectType type, 
	        sf::Texture* t, const sf::Vector2f& p)
	                  : WorldObject(type, t, p) {}

//-------------------------------------------------
void MoveableObject::move(const Map& map, char way) {}


