#pragma once

#include "MoveableObject.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MoveableObject::create() const {
	auto result = sf::Sprite(*m_texture);
	result.setPosition(m_position);
	return result;
}

//-------------------------------------------------
sf::Vector2f MoveableObject::get_position() const {
	return m_position;
}

//-------------------------------------------------
void MoveableObject::set_position(const sf::Vector2f& position) {
	m_position = position;
}






