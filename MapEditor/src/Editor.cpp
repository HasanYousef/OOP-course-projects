#pragma once

#include "Editor.h"

Editor::Editor() :
	m_window(sf::VideoMode(800, 800), "Map Editor") {}

void Editor::run() {
	/* try to open file to read */
	fs::path p = "C:resources";
	fs::path fileName = "board.txt";
	p /= fileName;
	std::ifstream ifile(fs::absolute(p));
	std::ofstream ofile;

	// if file exists
	if (ifile) {
		std::cout << "file exists\n";
		// here print file input to window
	}
	// if file does exists
	else {
		int height, width;
		std::cout << p << "\n";
		ifile.close();
		std::cin >> height >> width;
		m_board.setNew(height, width);
	}

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
	if (m_textButtons[SAVE_BUTTON].handleClick(location))
		saveBoard();
	else if (m_textButtons[CLEAR_BUTTON].handleClick(location)) {
		int width, height;
		std::cout << "Enter new width and Hight for the window: ";
		std::cin >> width >> height;
		//m_board.clearBoard();
		//m_board(width, height);
	}
	for (int buttonIndex = 0; buttonIndex < NUM_OF_TYPES; buttonIndex++) {
		if (m_textureButtons[buttonIndex].handleClick(location)) {
			m_clickMode = m_textureButtons[buttonIndex].getType();
		}
	}
}

void Editor::saveBoard() const {

}