#pragma once

#include "Well.h"

//-------------------------------------------------
Well::Well() {
	m_position = sf::Vector2f(0, 0);
	m_clock.restart();
}

//-------------------------------------------------
Well::Well(sf::Vector2f &position)
	:  m_position(position) {
	m_clock.restart();
}

//-------------------------------------------------
bool Well::stillWell(Map& map) const {
	sf::Time time = m_clock.getElapsedTime();
	if (time.asSeconds() >= 5) {
		map.set_object(O_Wall, m_position);
		return true;
	}
	return false;
}

//-------------------------------------------------
void Well::setPosition(sf::Vector2f& points) {
	m_position = points;
}

//-------------------------------------------------
sf::Vector2f* Well::getPosition() {
	return &m_position;
}