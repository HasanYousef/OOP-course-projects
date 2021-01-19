#pragma once

#include "Panel.h"

//-------------------------------------------------------
//
void Panel::add_button(ObjectType type) {
	TextureButton* button = new TextureButton;
	button->set_type(type);

	sf::Vector2f position(m_position.x,
		m_buttons.back()->get_position().y + BUTTON_HEIGHT + BUTTON_MARGIN);
	button->set_position(position);

	m_buttons.push_back(button);
}

//-------------------------------------------------------
//
void Panel::add_button(std::string string) {
	TextButton* button = new TextButton;
	button->set_string(string);

	sf::Vector2f position(m_position.x,
		m_buttons.back()->get_position().y + BUTTON_HEIGHT + BUTTON_MARGIN);
	button->set_position(position);

	m_buttons.push_back(button);
}

//-------------------------------------------------------
//in this func we take the location of the pressed mouse
//and we check wich botton the user pressed
UserOption Panel::handle_click(const sf::Vector2f& location) const {
	for (int i = 0; i < m_buttons.size(); i++)
		if (m_buttons[i]->handle_click(location) != UserOption::Nothing)
			return m_buttons[i]->handle_click(location);

	return UserOption::Nothing;
}

//-------------------------------------------------------
//here we draw the panel (menu) we print every button 
void Panel::draw(sf::RenderWindow& window) const {
	m_textButtons[SAVE_BUTTON].draw(window);
	m_textButtons[CLEAR_BUTTON].draw(window);
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++)
		m_textureButtons[buttonIndex].draw(window);
}