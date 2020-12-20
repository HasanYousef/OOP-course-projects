#pragma once

#include "TextButton.h"

//------------------------------------------------------
TextButton::TextButton(std::string string, sf::Vector2f size, sf::Font& font) {
	m_text.setString(string);
	m_text.setColor(sf::Color::Black);
	m_text.setCharacterSize(TEXTSIZE);
	m_text.setFont(font);
	m_button.setSize(size);
	m_button.setFillColor(sf::Color::White);
}

//------------------------------------------------------
void TextButton::setPosition(sf::Vector2f points) {
	m_button.setPosition(points);
	m_text.setPosition(sf::Vector2f(m_button.getOrigin()));
}