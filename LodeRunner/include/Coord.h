struct Coord {
	Coord() : m_col(0), m_row(0) {}
	Coord(int c, int r) : m_col(c), m_row(r) {}
	int m_col,
		m_row;
};