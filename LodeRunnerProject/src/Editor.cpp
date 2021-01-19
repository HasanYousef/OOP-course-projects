#pragma once

#include "Editor.h"

Editor::Editor() :
	m_clickMode(UserOption::Nothing)
{}

//--------------------------------------------
void Editor::run(sf::RenderWindow& window, int level) {
	// set the panel's buttons
	initPanel();
	
	m_map.load_map(level);

	// mouse world object hover
	sf::Sprite hover;
	bool putHover = false;
	while (window.isOpen()) {
		window.clear();
		m_map.draw(window);
		m_panel.draw(window);
		if (putHover)
			window.draw(hover);
		window.display();
		// if an event happened
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			//close window
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			//if clicked - the click could be in the panel side or in the board side
			case sf::Event::MouseButtonReleased: {
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				//panel side
				if (location.x < BOARD_UI_X)
					handle_click(location);
				//board side
				else if (m_clickMode < UserOption::SaveBoard)
					m_map.set_object(ObjectType(m_clickMode), location);
				break;
			}
			//hover action
			case sf::Event::MouseMoved: {
				auto location = sf::Mouse::getPosition(window);
				int newCol = int(location.x - BOARD_UI_X) / TEXTURE_SIZE;
				int newRow = int(location.y) / TEXTURE_SIZE;
				//if there is a hover in the board side
				if (m_clickMode < UserOption::SaveBoard && location.x > BOARD_UI_X &&
					newRow < m_map.get_height() && newCol < m_map.get_width()) {

					//put the texture that the user holds with the mouse and wants to put
					hover = sf::Sprite(*m_textures[m_clickMode]);
					int xPos = ((int(location.x) - BOARD_UI_X) / TEXTURE_SIZE) * TEXTURE_SIZE + BOARD_UI_X;
					int yPos = (int(location.y) / TEXTURE_SIZE) * TEXTURE_SIZE;
					hover.setPosition(sf::Vector2f(xPos , yPos));
					putHover = true;
				}
				else {
					putHover = false;
				}
			}
			}
		}
	}
}

//--------------------------------------------
//check wich botton the user clicked
void Editor::handle_click(const sf::Vector2f &location) {
	UserOption act = m_panel.handle_click(location);
	//if (act == UserOption::SaveBoard)
		//m_map.save();
	if (act == UserOption::ClearBoard) {
		initMap();
	}
	//if the user wants to put something in the board
	if (act != UserOption::Nothing && act < 8) {
		m_clickMode = UserOption(int(act));
	}
}

//--------------------------------------------
//we creat new board
void Editor::initMap() {
	int height = 12, width = 15;
	m_map = Map(height, width);
}

//--------------------------------------------
//we creat new board
void Editor::initPanel() {
	m_panel.setPosition(sf::Vector2f(10, 10));
	m_panel.addTextButton(UserOption::SaveBoard, "Save");
	m_panel.addTextButton(UserOption::ClearBoard, "Clear");

	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_panel.addTextureButton(UserOption(i));
}
