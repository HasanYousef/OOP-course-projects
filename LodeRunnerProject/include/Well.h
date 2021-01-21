#pragma once

#include "macros.h"
#include <SFML/Graphics.hpp>
#include "Map.h"

class Well {
public:
	Well();
	Well(sf::Vector2f&);
	bool stillWell(Map&) const;
	void setPosition(sf::Vector2f&);
	sf::Vector2f* getPosition();
private:
	sf::Clock m_clock;
	sf::Vector2f m_position;
};