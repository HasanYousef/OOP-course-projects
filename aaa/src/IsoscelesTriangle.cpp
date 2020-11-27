#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3]) {//
	double d1, d2, d3;
	d1 = distance(vertices[0], vertices[1]);
	d2 = distance(vertices[0], vertices[2]);
	d3 = distance(vertices[1], vertices[2]);
	if (!(vertices[0].isValid() || vertices[1].isValid() || vertices[2].isValid()) || !isEqual(d2, d3) ||
		!sameRow(vertices[0], vertices[1]))
		Isoscelestriangledefault();
	else {
		_point1 = vertices[0];
		_point2 = vertices[1];
		_point3 = vertices[2];
	}
}


void IsoscelesTriangle::Isoscelestriangledefault() {//
	_point1.m_col = _point1.m_row = _point2.m_row = 20;
	_point2.m_col = 30;
	_point3.m_col = 25;
	_point3.m_row = 20 + sqrt(75);
}


IsoscelesTriangle::IsoscelesTriangle(const Vertex& v0, const Vertex& v1, double height) {//
	Vertex point3(
		v1.m_col - distance(v0, v1) / 2,
		v1.m_row + height
	);
	if (
		v0.isValid() &&
		v1.isValid() &&
		point3.isValid() &&
		sameRow(v0, v1) &&
		isEqual(distance(v0, point3), distance(v1, point3))
		) {
		_point1.m_col = v0.m_col;
		_point1.m_row = v0.m_row;
		_point2.m_col = v1.m_col;;
		_point2.m_row = v1.m_row;;
		_point3.m_col = point3.m_col;
		_point3.m_row = point3.m_row;
	}
	else
		Isoscelestriangledefault();
}

Vertex IsoscelesTriangle::getVertex(int index)const {//
	if (index == 0)
		return _point1;
	else if (index == 1)
		return _point2;
	else if (index == 2)
		return _point3;
}


double IsoscelesTriangle::getBaseLength()const {//
	return (distance(_point1, _point2));
}




Rectangle IsoscelesTriangle::getBoundingRectangle() const {//
	Vertex bottomleft, topright;
	bottomleft.m_col = _point1.m_col;
	bottomleft.m_row = _point1.m_row;
	topright.m_col = _point2.m_col;
	topright.m_row = _point3.m_row;
	Rectangle rect(bottomleft, topright);
	return rect;
}

double IsoscelesTriangle::getArea() const {//
	return distance(_point1, _point2) * distance(this->getCenter(), _point3);
}

double  IsoscelesTriangle::getPerimeter() const {//
	return (
		distance(_point1, _point2) +
		distance(_point2, _point3) +
		distance(_point3, _point1)
		);
}

Vertex  IsoscelesTriangle::getCenter() const {//
	Vertex v(_point3.m_col, _point3.m_row - getHeight() / 2);
	return v;
}

double IsoscelesTriangle::getHeight() const {//
	double height = _point3.m_row - _point1.m_row;
	return height >= 0 ? height : -height;
}

bool IsoscelesTriangle::scale(double factor) {
	double newHeight = getHeight() * factor;
	Vertex point1(getCenter().m_col - distance(_point1, _point2) * factor / 2,
		getCenter().m_row - newHeight / 2);
	Vertex point2(getCenter().m_col + distance(_point1, _point2) * factor / 2,
		getCenter().m_row - newHeight / 2);
	Vertex point3(_point3.m_col, newHeight / 2 + getCenter().m_row);

	if (
		point1.isValid() &&
		point2.isValid() &&
		point3.isValid() &&
		sameRow(point1, point2) &&
		isEqual(distance(point1, point3), distance(point2, point3))
		) {
		_point1.m_col = point1.m_col;
		_point1.m_row = point1.m_row;
		_point2.m_col = point2.m_col;;
		_point2.m_row = point2.m_row;;
		_point3.m_col = point3.m_col;
		_point3.m_row = point3.m_row;
		return true;
	}
	Isoscelestriangledefault();
	return false;
}

double IsoscelesTriangle::getLegLength() const {//
	return distance(_point1, _point3);
}

void IsoscelesTriangle::draw(Board& board) const {//
	board.drawLine(_point1, _point2);
	board.drawLine(_point2, _point3);
	board.drawLine(_point3, _point1);
}