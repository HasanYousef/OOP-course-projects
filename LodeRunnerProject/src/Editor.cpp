#pragma once

#include "Editor.h"

Editor::Editor() :
	m_clickMode(UserOption::Nothing),
	m_numOfLevels(0),
	m_level(0)
{}

//--------------------------------------------
UserOption Editor::run(sf::RenderWindow& window, int level, int numOfLevels) {
	m_level = level;
	m_numOfLevels = numOfLevels;
	// set the panel's buttons
	initPanel();
	
	// if the usew wants to edit an existing map
	if (m_level > 0)
		m_map.load_map(m_level, BUTTON_WIDTH + 10);
	// adding new level
	else {
		initMap(window);
		m_level *= -1;
	}

	// mouse world object hover
	sf::Sprite hover;
	bool putHover = false;
	while (window.isOpen()) {
		window.clear();
		m_map.draw(window, true);
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
				if (location.x < BUTTON_WIDTH + 10) {
					UserOption choice = handle_click(location, window);
					if (choice == UserOption::Exit ||
						choice == UserOption::NextBoard ||
						choice == UserOption::PrevBoard) {
						return choice;
					}
				}
				//board side
				else if (m_clickMode < UserOption::SaveBoard) {
					location.x = ((int(location.x) - (BUTTON_WIDTH + 10)) / TEXTURE_SIZE) * TEXTURE_SIZE + (BUTTON_WIDTH + 10);
					location.y = (int(location.y) / TEXTURE_SIZE) * TEXTURE_SIZE;
					m_map.setObjectWithMargin(ObjectType(m_clickMode), location, BUTTON_WIDTH + 10);
				}
				break;
			}
			//hover action
			case sf::Event::MouseMoved: {
				auto location = sf::Mouse::getPosition(window);
				int newCol = int(location.x - BUTTON_WIDTH + 10) / TEXTURE_SIZE;
				int newRow = int(location.y) / TEXTURE_SIZE;
				//if there is a hover in the board side
				if (m_clickMode < UserOption::SaveBoard && location.x > BUTTON_WIDTH + 10 &&
					newRow < m_map.get_height() && newCol < m_map.get_width()) {

					//put the texture that the user holds with the mouse and wants to put
					hover = sf::Sprite(*(Textures::instance().get_texture(ObjectType(m_clickMode))));
					int xPos = ((int(location.x) - (BUTTON_WIDTH + 10)) / TEXTURE_SIZE) * TEXTURE_SIZE + BUTTON_WIDTH + 10;
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
UserOption Editor::handle_click(const sf::Vector2f &location, sf::RenderWindow& window) {
	UserOption act = m_panel.handle_click(location);
	if (act == UserOption::SaveBoard)
		m_map.save(m_level);
	if (act == UserOption::ClearBoard) {
		initMap(window);
	}
	if (act == UserOption::NextBoard) {
		m_level++;
		return UserOption::NextBoard;
	}
	if (act == UserOption::PrevBoard) {
		m_level--;
		return UserOption::PrevBoard;
	}
	if (act == UserOption::Exit) {
		m_level = 0;
		return UserOption::Exit;
	}
	//if the user wants to put something in the board
	if (act != UserOption::Nothing && act < 8) {
		m_clickMode = UserOption(int(act));
	}
}

//--------------------------------------------
//we creat new board
void Editor::initMap(sf::RenderWindow& window) {
	//writing a message on the window to tell the user to use the other window
	auto text = sf::Text("Please enter the height and the width of the new board\nin the other window...",
		*Textures::instance().get_font(),
		20);
	//display the message
	window.clear();
	window.draw(text);
	window.display();

	int height, width, time;
	std::cout << "Enter the height and the width of the map that you want to create:\n";
	std::cin >> height >> width;
	std::cout << "Enter the max time of the new level:\n";
	std::cin >> time;
	//making a board with the given size
	m_map.~Map();
	m_map.init(height, width, time);
}

//--------------------------------------------
//we creat new board
void Editor::initPanel() {
	m_panel.clear();
	m_panel.setPosition(sf::Vector2f(10, 10));
	m_panel.addTextButton(UserOption::SaveBoard, "Save");
	m_panel.addTextButton(UserOption::ClearBoard, "Clear");
	if(m_level < m_numOfLevels && m_level > 0)
		m_panel.addTextButton(UserOption::NextBoard, "Next");
	if (1 < m_level || m_level < 0)
		m_panel.addTextButton(UserOption::PrevBoard, "Previous");

	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_panel.addTextureButton(UserOption(i));
	m_panel.addTextButton(UserOption::Exit, "Exit");
}
