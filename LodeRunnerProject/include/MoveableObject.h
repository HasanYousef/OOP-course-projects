#pragma once

#include "macros.h"
#include "SFML/Graphics.hpp"
#include "WorldObject.h"
#include "Map.h"

class MoveableObject : public WorldObject {
public:
	//---Constructors---------------------------------------------------
	MoveableObject();
	MoveableObject(ObjectType, const sf::Vector2f&);
	//---functions----------------------------
	virtual void move(const Map&);
};
