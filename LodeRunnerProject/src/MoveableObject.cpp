#pragma once

#include "MoveableObject.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
sf::Vector2f MoveableObject::get_position() const {
	return m_position;
}

//-------------------------------------------------
void MoveableObject::set_position(const sf::Vector2f& position) {
	m_position = position;
}

//-------------------------------------------------
//this func draw the object
void MoveableObject::draw(sf::RenderWindow& window) const {
	window.draw(m_body);
}

//-------------------------------------------------
void MoveableObject::move(sf::Vector2f& movement) {
	m_body.move(movement.x, movement.y);
}
