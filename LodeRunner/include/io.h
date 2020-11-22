#pragma once

#include "Location.h"

const int SPECIAL_KEY = 224;

// special keys
const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;

namespace Keyboard
{
// Implements the same semantics as _getch() from conio.h
// Currently, handles only regular keys (ASCII values)
// and arrow keys (doesn't handle F1-F12, for example)
int getch();
}

namespace Screen
{
// Reset terminal cursor location to start of the screen (0,0)
void resetLocation();
// Set terminal cursor location to the desired location
void setLocation(const Location& location);
}
