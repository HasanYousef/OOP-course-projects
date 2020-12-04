#pragma once
#include "Image.h"
#include "ImageDataStructure.cpp"

//--------------------------------------------------
Image::Image() : m_height(0), m_width(0), m_datastruct(){
	
}

Image::Image(int H, int W) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_datastruct = ImageDataStructure(H, W, WHITE);
}

//-------------------------------------------------
Image::Image(int H, int W, unsigned char pixel) {
	m_height = (H >= 0) ? H : 0;
	m_width = (W >= 0) ? W : 0;
	m_datastruct = ImageDataStructure(H, W, pixel);
}

//-------------------------------------------------
Image::Image(const Image& other) {
	*this = other;
}

//-------------------------------------------------
int Image::get_height() const {
	return m_height;
}

//-------------------------------------------------
int Image::get_width() const {
	return m_width;
}

//---Local---Operators-----------------------------
//-------------------------------------------------
Pixel Image::operator()(unsigned int col, unsigned int row) const {
	return m_datastruct(col, row);
}

//------------------------------------------------
void Image::operator=(const Image& other) {
	m_datastruct.free(m_height);
	m_height = other.get_height();
	m_width = other.get_width();
	m_datastruct = ImageDataStructure(other.m_datastruct, m_height, m_width);
}

//------------------------------------------------
Pixel& Image::operator()(unsigned int col, unsigned int row) {
	return m_datastruct(row, col);
}

//===========================================================//

//---Global---Operators----------------------------
//-------------------------------------------------
bool operator==(const Image& first, const Image& second)
{
	if (first.get_width() != second.get_width() ||
		first.get_height() != second.get_height()) {
		return false;
	}
	//we check the pixels colors 
	for (int row = 0; row < second.get_height(); row++) {
		for (int col = 0; col < first.get_width(); col++) {
			if (first(row, col) != second(row, col)) {
				return false;
			}
		}
	}
	return true;
}

//-------------------------------------------------
bool operator!=(const Image& first, const Image& second) {
	return !(first == second);
}

//-------------------------------------------------
Image operator~(const Image& image) {
	Image newimage;
	newimage(image.get_height(), image.get_width());
	for (int row = 0; row < image.get_height(); row++) {
		for (int col = 0; col < image.get_width(); col++) {
			if (image(row, col) == WHITE) {
				newimage(row, col) = BLACK;
			}
			else if (image(row, col) == BLACK) {
				newimage(row, col) = WHITE;
			}
		}
	}
	return newimage;
}

//--------------------------------------------------------
Image operator+(const Image& A, const Image& B)
{
	Image newimage(max(A.get_height(), B.get_height()),
		A.get_width() + B.get_width());
	//Copy A image
	for (int row = 0; row < A.get_height(); row++) {
		for (int col = 0; col < A.get_width(); col++) {
			newimage(row, col) = A(row, col);
		}
	}
	//Copy B image
	for (int row = 0; row < B.get_height(); row++) {
		for (int col = A.get_width(); col < B.get_width(); col++) {
			newimage(row, col) = B(row, col);
		}
	}
	//WHITE pixels
	if (A.get_height() > B.get_height()) {
		for (int row = B.get_height(); row < A.get_height(); row++) {
			for (int col = A.get_width(); col < B.get_width() + A.get_width(); col++) {
				newimage(row, col) = B(row, col);
			}
		}
	}
	else {
		for (int row = B.get_height(); row < newimage.get_height(); row++) {
			for (int col = 0; col < B.get_width(); col++) {
				newimage(row, col) = B(row, col);
			}
		}
	}
	return newimage;
}

//--------------------------------------------------------
Image operator+=(const Image& A, const Image& B) {
	return (A + B);
}

//--------------------------------------------------------
Image operator*(const Image& image, int n)
{
	int replay = 0;
	Image newimage(image.get_height(), image.get_width());
	while (replay < n) {
		newimage += image;
		replay++;
	}
	return newimage;
}

//--------------------------------------------------------
Image operator*=(const Image& image, int n) {
	return image * n;
}

//--------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Image& image)
{
	for (int row = 0; row < image.get_height(); row++) {
		for (int col = 0; col < image.get_width(); col++) {
			os << image(col, row);
		}
	}
	return os;
}

Image operator&(const Image& left, const Image& right) {
	int minHeight = left.get_height() < right.get_height() ? left.get_height() : right.get_height(),
		minWidth = left.get_width() < right.get_width() ? left.get_width() : right.get_width();
	Image newImg(minHeight, minWidth);

	for (int row = 0; row < minHeight; row++) {
		for (int col = 0; col < minWidth; col++) {
			newImg(row, col) = left(row, col) & right(row, col);
		}
	}
	return newImg;
}

Image operator|(const Image& left, const Image& right) {
	int leftHeight = left.get_height(),
		rightHeight = right.get_height(),
		leftWidth = left.get_width(),
		rightWidth = right.get_width();
	int maxHeight = rightHeight > leftWidth ? rightHeight : leftWidth,
		maxWidth = leftWidth > rightWidth ? leftWidth : rightWidth;
	Image newImg(maxHeight, maxWidth);

	for (int row = 0; row < maxHeight; row++) {
		for (int col = 0; col < maxWidth; col++) {
			if (row < leftHeight && row < rightHeight
				&& col < leftWidth && col < rightWidth)
				newImg(row, col) = left(row, col) | right(row, col);
			else if (row < leftHeight && col < leftWidth)
				newImg(row, col) = left(row, col);
			else if (row < rightHeight && col < rightHeight)
				newImg(row, col) = right(row, col);
		}
	}
	return newImg;
}

Image& operator|=(Image& left, const Image& right) {
	left = left | right;
	return left;
}

Image& operator&=(Image& left, const Image& right) {
	left = left & right;
	return left;
}



