#pragma once

#include "Editor.h"

Editor::Editor() :
	m_window(sf::VideoMode(640, 500), "Map Editor") {}

void Editor::run() {
	/* try to open file to read */
	fs::path p = "C:board.txt";
	std::ifstream ifile(fs::absolute(p));

	// if file exists
	if (ifile) {
		m_board.readFromStream(ifile);
	}
	// if file doesn't exist
	else {
		int height, width;
		std::cin >> height >> width;
		m_board.setNew(height, width);
	}
	ifile.close();

	initButtons();

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
					m_clickMode = m_panel.handleClick(location);
				else
					m_board.set_object(m_clickMode, location);
			}
			}
		}
	}
}

void Editor::handle_panel_click(const sf::Vector2f &location) {
	
}

void Editor::initButtons() {

}

void Editor::saveBoard() const {

}

