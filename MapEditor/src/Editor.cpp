#pragma once

#include "Editor.h"

Editor::Editor() :
	m_window(sf::VideoMode(640, 500), "Map Editor") {}

void Editor::run() {
	m_panel.initPanel(m_textures);

	/* try to open file to read */
	fs::path p = "C:board.txt";
	std::ifstream ifile(fs::absolute(p));

	// if file exists
	if (ifile)
		m_board.readFromStream(ifile, m_textures);
	// if file doesn't exist
	else
		initBoard();
	ifile.close();

	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		m_panel.draw(m_window);
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
					handleClick(location);
				else
					m_board.set_object(m_clickMode, location, m_textures);
			}
			}
		}
	}
}

void Editor::handleClick(const sf::Vector2f &location) {
	ActionType act = m_panel.handleClick(location);
	if (act == ActionType::SaveBoard)
		m_board.save();
	if (act == ActionType::ClearBoard)
		initBoard();
	if (!act == ActionType::Nothing)
		m_clickMode = ObjectType(int(act));
}

void Editor::initBoard() {
	int height, width;
	std::cout << "Enter the height and the width of the map that you want to create:\n";
	std::cin >> height >> width;
	m_board.setNew(height, width, m_textures);
}

void Editor::initializeTextures() {
	(*m_textures[ObjectType::Space]).loadFromFile("space.png");
	(*m_textures[ObjectType::Wall]).loadFromFile("wall.png");
	(*m_textures[ObjectType::Ladder]).loadFromFile("ladder.png");
	(*m_textures[ObjectType::Rope]).loadFromFile("rope.png");
	(*m_textures[ObjectType::Money]).loadFromFile("money.png");
	(*m_textures[ObjectType::Player]).loadFromFile("player.png");
	(*m_textures[ObjectType::Enemy]).loadFromFile("enemy.png");
}