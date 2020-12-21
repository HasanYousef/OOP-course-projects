#pragma once

#include "TextButton.h"

TextButton::TextButton(const std::string& text,
	const sf::Vector2f& position,
	const sf::Font& font) :
	m_text(text),
	m_font(font) {
	m_position = position;
}

void TextButton::draw(sf::RenderWindow& window) const {
	window.draw(create());

	auto text = sf::Text(m_text, m_font);
	text.setPosition({ m_position.x + 20, m_position.y + 4 });
	const auto rect = text.getLocalBounds();
	window.draw(text);
}
