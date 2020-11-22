#pragma once

struct Location
{
    explicit Location(int row, int col) : row(row), col(col) {}
    int row;
    int col;
};
