#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"
//----------------------------------
class Button {
public:
	Button() {}
	sf::RectangleShape create() const;
	bool handleClick(const sf::Vector2f location) const;
	sf::Vector2f get_position() const;
	void set_position(sf::Vector2f);
protected:
	sf::Vector2f m_position;
};
