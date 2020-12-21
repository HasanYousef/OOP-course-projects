#pragma once

#include "Button.h"

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

/*
//------------------------------------------------------
//this is the constructor that take the texture and the
//size of the rectangle also we take the type of the 
//botton (player,enemy,addobject...) we build the botton
//on rectangle with the size we have and we add the texture
Button::Button(sf::Vector2f size) {
	m_button.setSize(size);
}

//------------------------------------------------------
//this void func take the window to let is draw the 
//botton we have on the window
void Button::draw(const sf::RenderWindow& window) const {
	window.draw(m_button);
}

//------------------------------------------------------
//this func take Vector2f to set the botton on the
//Vector2f points that we want on the window
void Button::setPosition(sf::Vector2f points) {
	m_button.setPosition(points);
}

//------------------------------------------------------
//this func return Vector2f that have the botton points
sf::Vector2f Button::getPosition() const {
	return m_button.getPosition();
}
*/