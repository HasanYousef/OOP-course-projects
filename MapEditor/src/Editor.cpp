#pragma once

#include "Editor.h"

Editor::Editor() :
	m_window(sf::VideoMode(800, 800), "Map Editor") {}

void Editor::run() {
	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased: {
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (location.x < BOARD_UI_X)
					handle_panel_click(location);
				else
					m_board.set_object(m_clickMode, location);
			}
			}
		}
	}
}

void Editor::handle_panel_click(const sf::Vector2f &location) {
	if (m_saveButton.handle_click(location)) {

	}
	else if (m_clearButton.handle_click(location)) {

	}
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++) {
		if(m_)
	}
}
