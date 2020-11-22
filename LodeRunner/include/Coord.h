struct Coord {
	Coord() : m_col(0), m_row(0) {}
	Coord(int c, int r) : m_col(c), m_row(r) {}
	int m_col,
		m_row;
};

Coord &Coord::operator=(const Coord &other) {
	if (&other != this) {
		m_col = other.m_col;
		m_row = other.m_row;
	}
	return *this;
}

bool operator==(const Coord& l, const Coord& r) {
	return (l.m_col == r.m_col && l.m_row == r.m_row);
}

bool operator!=(const Coord& l, const Coord& r) {
	return !(l == r);
}