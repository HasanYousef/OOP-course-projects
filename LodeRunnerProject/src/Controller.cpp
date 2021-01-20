#pragma once

#include "Controller.h"
#include "SFML/Audio.hpp"
//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller()
{
	m_numOfLevels = countLevels();
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "LodeRunner");
}

//-----------------run-----------------
void Controller::run() {
	UserOption userChoice = runMenu();
	while (userChoice != UserOption::Exit) {
		switch (userChoice) {
		case UserOption::StartGame:
			m_game.run(m_window, m_numOfLevels);
		case UserOption::EditMaps:
			m_editor.run(m_window, 1);
		case UserOption::AddNewMap:
			m_editor.run(m_window, m_numOfLevels + 1);
		}
		userChoice = runMenu();
	}
}

UserOption Controller::runMenu() {
	Panel panel;
	panel.setPosition({ 10, 10 });
	if(m_numOfLevels > 0)
		panel.addTextButton(UserOption::StartGame, "Start game");
	panel.addTextButton(UserOption::EditMaps, "Edit levels");
	panel.addTextButton(UserOption::AddNewMap, "Add a new level");
	panel.addTextButton(UserOption::Exit, "Exit game");

	while (m_window.isOpen()) {
		m_window.clear();
		panel.draw(m_window);
		m_window.display();
		// if an event happened
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			//close window
			switch (event.type) {
			case sf::Event::Closed:
				return UserOption::Exit;

			case sf::Event::MouseButtonReleased:
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				return panel.handle_click(location);
			}
		}
	}

	return UserOption::Nothing;
}

int Controller::countLevels() {
	int level = 1;
	while (true) {
		std::string str = "C:board";
		str += std::to_string(level);
		str += ".txt";
		fs::path p = str;
		std::ifstream ifile(fs::absolute(p));
		if (!ifile)
			break;
		ifile.close();
		level++;
	}
	return level - 1;
}