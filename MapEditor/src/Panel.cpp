#pragma once

#include "Panel.h"

Panel::Panel() {
	m_textButtons.push_back(TextButton("Save", { 30, 30 }, m_font));
	m_textButtons.push_back(TextButton("Remove", { 30, 30 }, m_font));

	m_textureButtons.push_back(TextureButton());
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

void Panel::draw(const sf::RenderWindow& window) const {
	m_textButtons[SAVE_BUTTON].draw(window);
	m_textButtons[CLEAR_BUTTON].draw(window);
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++)
		m_textureButtons[buttonIndex].draw(window);
}