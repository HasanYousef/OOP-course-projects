#pragma once

#include "Panel.h"

void Panel::initPanel(sf::Texture* textures[]) {
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	m_textButtons.push_back(TextButton("Save", { 0, 0 }, m_font));
	m_textButtons.push_back(TextButton("Remove", { 0, BUTTON_HEIGHT }, m_font));

	for(int i = 0; i < NUM_OF_TYPES; i++)
		m_textureButtons.push_back(TextureButton(textures[i], sf::Vector2f(0, (2 + i)*BUTTON_HEIGHT), ObjectType(i)));
}

ActionType Panel::handleClick(const sf::Vector2f& location) const {
	if (m_textButtons[SAVE_BUTTON].handleClick(location))
		return ActionType::SaveBoard;
	else if (m_textButtons[CLEAR_BUTTON].handleClick(location))
		return ActionType::ClearBoard;
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++) {
		if (m_textureButtons[buttonIndex].handleClick(location))
			return ActionType(int(m_textureButtons[buttonIndex].getType()));
	}
	return Nothing;
}

void Panel::draw(sf::RenderWindow& window) const {
	m_textButtons[SAVE_BUTTON].draw(window);
	m_textButtons[CLEAR_BUTTON].draw(window);
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++)
		m_textureButtons[buttonIndex].draw(window);
}