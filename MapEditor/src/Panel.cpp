#pragma once

#include "Panel.h"

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