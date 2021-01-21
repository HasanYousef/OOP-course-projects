#pragma once

#include "macros.h"
#include "SFML/Graphics.hpp"

class WorldObject {
public:
	WorldObject();
	WorldObject(ObjectType, const sf::Vector2f&);
	//---functions----------------------------
	void draw(sf::RenderWindow&) const;
	sf::Vector2f get_position() const;
	void set_position(const sf::Vector2f&);
	ObjectType get_type() const;
	void setType(ObjectType type);
	WorldObject& operator=(const WorldObject&);
	//---build-body-----------
	virtual sf::Sprite create() const;
protected:
	//---members--------------
	ObjectType m_objectType;
	sf::Vector2f m_position;
};