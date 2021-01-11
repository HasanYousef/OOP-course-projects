#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() {
	m_window.setSize({ WINDOW_WIDTH,WINDOW_HEIGHT });
	//open_maps_stream();
}

//-----------------run-----------------
void Controller::run() {
	UserOption userChoice = m_menu.run(m_window);
	while(userChoice != UserOption::Exit)
	switch (userChoice) { // we make it to start the game 
		case UserOption::ShowMainMenu:
			userChoice = m_menu.run(m_window);
		case UserOption::StartGame:
			userChoice = m_game.run(m_window);
		case UserOption::EditMaps:
			userChoice = m_editor.run(m_window);
	}
}

//---------------------------------------------
/*
void Controller::open_maps_stream() {
	// try to open file to read
	fs::path p = MAP_PATH;
	m_mapsStream(fs::absolute(p));
	// if file doesn't exist open the editor
	if (!m_mapsStream)
		initNewMap();
}
*/