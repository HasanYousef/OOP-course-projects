#pragma once
#include <iostream>
#include "macros.h"
#include "SFML/Graphics.hpp"

class WorldObject {
public:
	WorldObject();
	WorldObject(ObjectType, sf::Texture*, const sf::Vector2f&);
	//---functions----------------------------
	void draw(sf::RenderWindow&) const;
	sf::Vector2f get_position() const;
	void set_position(const sf::Vector2f&);
	ObjectType getType() const;
	WorldObject& operator=(const WorldObject&);
	//---build-body-----------
	sf::Sprite create() const;
protected:
	//---members--------------
	ObjectType m_objectType;
	sf::Vector2f m_position;
	sf::Texture* m_texture;
};