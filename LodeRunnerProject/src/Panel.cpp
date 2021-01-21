#pragma once

#include "Panel.h"

//-------------------------------------------------------
//
void Panel::addTextureButton(UserOption option) {
	TextureButton* button = new TextureButton;
	button->setOption(option);

	sf::Vector2f position(m_position.x,
		m_buttons.back()->get_position().y + BUTTON_HEIGHT + BUTTON_MARGIN);
	button->set_position(position);

	m_buttons.push_back(button);
}

//-------------------------------------------------------
//
void Panel::addTextButton(UserOption option, std::string string) {
	TextButton* button = new TextButton;
	button->setOption(option);
	button->set_string(string);
	sf::Vector2f position;
	if (m_buttons.size() > 0)
		position = sf::Vector2f(m_position.x,
			m_buttons.back()->get_position().y + BUTTON_HEIGHT + BUTTON_MARGIN);
	else
		position = sf::Vector2f(m_position.x,m_position.y);

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
	for (int i = 0; i < m_buttons.size(); i++)
		m_buttons[i]->draw(window);
}

void Panel::setPosition(sf::Vector2f pos) {
	m_position = pos;
}

//-------------------------------------------------------
//
void Panel::clear() {
	for (int i = 0; i < m_buttons.size(); i++)
		delete m_buttons[i];
	m_buttons.clear();
}
