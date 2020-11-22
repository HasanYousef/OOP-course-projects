#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Consts.h"

class Rectangle {
public:
	// constructors
	Rectangle() = default;
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex verticles[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& center, double width, double height);
	//get info
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	//other
	void draw(Board& board) const;
	bool scale(double factor);

private:
	Vertex m_bottomLeft = Vertex(DEF_BOTTOM_LEFT_COL, DEF_BOTTOM_LEFT_ROW),
		m_topRight = Vertex(DEF_TOP_RIGHT_COL, DEF_TOP_RIGHT_ROW);

	bool setVartexes(const Vertex& bottomLeft, const Vertex& topRight);
};