#pragma once

#include <iostream>

class MoveableObject {
public:
	//---Constructors---------------------------------------------------
	MoveableObject() : m_position(), m_texture() {}
	MoveableObject(const sf::Vector2f& position, sf::Texture* texture) :
		                     m_position(position), m_texture(texture) {}
	//---functions----------------------------
	sf::Vector2f get_position() const;
	void set_position(const sf::Vector2f&);
	sf::Sprite create() const;
private:
	sf::Vector2f m_position;
	sf::Texture* m_texture;
};
