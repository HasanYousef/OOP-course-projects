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
	text.setPosition(m_position);
	const auto rect = text.getLocalBounds();
	//text.setOrigin(rect.width / 2, rect.height / 2);
	window.draw(text);
}


/*
//------------------------------------------------------
TextButton::TextButton(const std::string& string, const sf::Vector2f& size, const sf::Font& font) {
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

std::string TextButton::getType() const {
	return m_text.getString();
}

*/