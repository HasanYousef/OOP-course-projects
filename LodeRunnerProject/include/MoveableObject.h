#pragma once

#include <iostream>

#include "WorldObject.h"

class MoveableObject : public WorldObject {
public:
	//---Constructors---------------------------------------------------
	MoveableObject() : m_position(), m_texture() {}
	MoveableObject(const sf::Vector2f& position, sf::Texture* texture)
	{
		m_position = position;
		m_texture = texture;
		m_body = sf::Sprite(*texture);
		m_body.setPosition(position);
	}
	//---functions----------------------------
	sf::Vector2f get_position() const;
	void set_position(const sf::Vector2f&);
	void draw(sf::RenderWindow&) const;
	void move(sf::Vector2f&);
};
