#pragma once

#include "Vertex.h"
#include "Utilities.h"
#include "Rectangle.h"
#include "Board.h"
#include <cmath>

class Window {

public:
	//contrast
	Window() = default;
	Window(const Rectangle& outer, const Rectangle& inner);
	Window(const Rectangle& outer, double verticalThickness, double horizontalThickness);
	//get 
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getVerticalThickness() const;
	double getHorizontalThickness() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Rectangle m_outer = Rectangle(),
		m_inner = Rectangle();
	void setRectangles(const Rectangle& outer, const Rectangle& inner);
};