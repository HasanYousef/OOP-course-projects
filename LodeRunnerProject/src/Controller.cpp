#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() {
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "LodeRunner");
	//open_maps_stream();
}

//-----------------run-----------------
void Controller::run() {
	UserOption userChoice = runMenu();
	while(userChoice != UserOption::Exit)
	switch (userChoice) { // we make it to start the game 
		case UserOption::StartGame:
			m_game.run(m_window);
		case UserOption::EditMaps:
			m_editor.run(m_window, 1);
	}
}

UserOption Controller::runMenu() {
	Panel panel;
	panel.setPosition({ 10, 10 });
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