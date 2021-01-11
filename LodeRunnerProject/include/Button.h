#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
//----------------------------------
class Button {
public:
	Button() {}
	sf::RectangleShape create() const;
	bool handleClick(const sf::Vector2f location) const;
	UserOption what_action() const;
protected:
	sf::Vector2f m_position;
	UserOption m_action;
};
