#pragma once

#include "Button.h"

//------------------------------------------------------
Button::Button() :
	m_option(UserOption::Nothing)
{}

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
UserOption Button::handle_click(const sf::Vector2f location) const {
	return create().getGlobalBounds().contains(location) ? m_option : UserOption::Nothing;
}

sf::Vector2f Button::get_position() const {
	return m_position;
}

void Button::set_position(sf::Vector2f position) {
	m_position = position;
}

void Button::setOption(UserOption option) {
	m_option = option;
}