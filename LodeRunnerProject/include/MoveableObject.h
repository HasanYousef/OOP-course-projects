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
	void fall(const Map&);
	bool on_ladder(const Map&, char);
	bool if_can_move(const Map&, char);
	//---functions----------------------------
	virtual void move(const Map&);
private:
	sf::Vector2f m_originPosition;
};
