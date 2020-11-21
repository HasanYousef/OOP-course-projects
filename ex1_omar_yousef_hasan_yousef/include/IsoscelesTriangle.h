#pragma once
//include
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"
#include "Consts.h"
#include <cmath>

//IsoscelesTriangle class
class IsoscelesTriangle {
public:
	// constructors
	IsoscelesTriangle(const Vertex verticles[3]);
	IsoscelesTriangle(const Vertex& v0, const Vertex& v1, double height);

	// public functions
	Vertex getVertex(int index) const;
	double getBaseLength() const;
	double getLegLength() const;
	double getHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex m_bottomLeft, m_bottomRight, m_top;
	bool isValidVartexes(Vertex v0, Vertex v1, Vertex v2);
	void setVertexes(Vertex v0, Vertex v1, Vertex v2);
};