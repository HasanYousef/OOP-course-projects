#pragma once

#include "Button.h"

//------------------------------------------------------
//this creat the botton to draw it on the window
sf::RectangleShape Button::create() const {
	auto result = sf::RectangleShape({ BUTTON_WIDTH, BUTTON_HEIGHT });
	result.setPosition(m_position);
	result.setFillColor(sf::Color::Blue);
	return result;
}

//------------------------------------------------------
//this bool funck check if the mouse is on the botton
//or not if yes we return true if no we return false
bool Button::handleClick(const sf::Vector2f location) const {
	return (create().getGlobalBounds().contains(location));
}
