#pragma once

#include "TextButton.h"

TextButton::TextButton() :
	m_string()
{}

//--------------------------------------------------------
//this the constructor of the TextButton we take the Font
//and what we want to write on the botton also the possistion
//of the botton
TextButton::TextButton(const std::string& string,
	const sf::Vector2f& position) :
	m_string(string) {
	m_position = position;
}

//--------------------------------------------------------
//here we draw the botton
void TextButton::draw(sf::RenderWindow& window) const {
	window.draw(create());

	auto text = sf::Text(m_string, *(Textures::instance().get_font()));
	text.setPosition({ m_position.x + 20, m_position.y + 4 });
	window.draw(text);
}

void TextButton::set_string(std::string string) {
	m_string = string;
}