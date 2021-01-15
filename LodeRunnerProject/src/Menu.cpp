#pragma once

#include "Menu.h"

//-------------------------------------------------------
//initializing the buttons to be in the right position
void Menu::initMenu(sf::Texture* textures[]) {
	m_font.loadFromFile(FONT_PATH);
	// font buttons
	m_textureButtons.push_back(TextButton("Save", { 0, 0 }, m_font));
	m_textureButtons.push_back(TextButton("Clear", { 0, BUTTON_HEIGHT }, m_font));
	//textured buttons
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textureButtons.push_back(TextureButton(textures[i], sf::Vector2f(0, (2 + i) * BUTTON_HEIGHT), ObjectType(i)));
}

//-------------------------------------------------------
//in this func we take the location of the pressed mouse
//and we check wich botton the user pressed
UserOption Menu::handleClick(const sf::Vector2f& location) const {
	if (m_textureButtons[SAVE_BUTTON].handleClick(location))
		return ActionType::SaveBoard;
	else if (m_textureButtons[CLEAR_BUTTON].handleClick(location))
		return ActionType::ClearBoard;
	//checking each textured button if clicked
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++) {
		if (m_textureButtons[buttonIndex].handleClick(location))
			return ActionType(int(m_textureButtons[buttonIndex].getType()));
	}
	return Nothing;
}

//-------------------------------------------------------
//here we draw the panel (menu) we print every button 
void Menu::draw(sf::RenderWindow& window) const {
	m_textureButtons[SAVE_BUTTON].draw(window);
	m_textureButtons[CLEAR_BUTTON].draw(window);
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++)
		m_textureButtons[buttonIndex].draw(window);
}