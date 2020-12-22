#pragma once

#include "TextButton.h"

//--------------------------------------------------------
//this the constructor of the TextButton we take the Font
//and what we want to write on the botton also the possistion
//of the botton
TextButton::TextButton(const std::string& text,
	const sf::Vector2f& position,
	const sf::Font& font) :
	m_text(text),
	m_font(font) {
	m_position = position;
}

//--------------------------------------------------------
//here we draw the botton
void TextButton::draw(sf::RenderWindow& window) const {
	window.draw(create());

	auto text = sf::Text(m_text, m_font);
	text.setPosition({ m_position.x + 20, m_position.y + 4 });
	const auto rect = text.getLocalBounds();
	window.draw(text);
}
