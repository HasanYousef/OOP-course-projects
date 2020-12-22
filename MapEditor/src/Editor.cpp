#pragma once

#include "Editor.h"

//--------------------------------------------
Editor::Editor() :
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Map Editor") {}

//--------------------------------------------
void Editor::run() {
	// set the textures in the start
	initializeTextures();
	// set the panel's buttons
	m_panel.initPanel(m_textures);
	// try to open file to read
	fs::path p = "C:board.txt";
	std::ifstream ifile(fs::absolute(p));

	// if file exists
	if (ifile)
		m_board.readFromStream(ifile, m_textures);
	// if file doesn't exist
	else
		initBoard();
	ifile.close();

	// mouse world object hover
	sf::Sprite hover;
	bool putHover = false;
	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		m_panel.draw(m_window);
		if (putHover)
			m_window.draw(hover);
		m_window.display();
		// if an event happened
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			//close window
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;

			//if clicked - the click could be in the panel side or in the board side
			case sf::Event::MouseButtonReleased: {
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				//panel side
				if (location.x < BOARD_UI_X)
					handleClick(location);
				//board side
				else if (m_clickMode < ActionType::SaveBoard)
					m_board.set_object(ObjectType(m_clickMode), location, m_textures);
				break;
			}
			//hover action
			case sf::Event::MouseMoved: {
				auto location = sf::Mouse::getPosition(m_window);
				int newCol = int(location.x - BOARD_UI_X) / TEXTURE_SIZE;
				int newRow = int(location.y) / TEXTURE_SIZE;
				//if there is a hover in the board side
				if (m_clickMode < ActionType::SaveBoard && location.x > BOARD_UI_X &&
					newRow < m_board.getHeight() && newCol < m_board.getWidth()) {

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
void Editor::handleClick(const sf::Vector2f &location) {
	ActionType act = m_panel.handleClick(location);
	if (act == ActionType::SaveBoard)
		m_board.save();
	if (act == ActionType::ClearBoard) {
		initBoard();
	}
	//if the user wants to put something in the board
	if (act != ActionType::Nothing && act < 8) {
		m_clickMode = ActionType(int(act));
	}
}

//--------------------------------------------
//we creat new board
void Editor::initBoard() {
	//writing a message on the window to tell the user to use the other window
	sf::Font font;
	font.loadFromFile(FONT_PATH);
	auto text = sf::Text("Please enter the height and the width of the new board\nin the other window...",
		font,
		20);
	//display the message
	m_window.clear();
	m_window.draw(text);
	m_window.display();

	int height, width;
	std::cout << "Enter the height and the width of the map that you want to create:\n";
	std::cin >> height >> width;
	//making a board with the given size
	m_board.setNew(height, width, m_textures);
}

//--------------------------------------------
//here we load the textures
void Editor::initializeTextures() {
	//initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textures[i] = new sf::Texture();

	(*m_textures[ObjectType::Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::Money]).loadFromFile("money.png");
	(*m_textures[ObjectType::Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::Enemy]).loadFromFile("enemy.png");
}