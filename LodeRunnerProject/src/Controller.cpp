#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() :
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Lode Runner") {
	//open_maps_stream();
}

//-----------------run-----------------
void Controller::run() {
	m_game.start(m_window);
	/*
	MainMenuOption userChoice = m_menu.run();
	switch (userChoice) { // we make it to start the game 
		case StartGame:
			m_game.start(m_window);
		case EditMaps:
			17; //m_editor.start();
		case Exit:
			17; //end();
	}
	*/
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