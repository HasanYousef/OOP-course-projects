#pragma once

#include <iostream>
#include "ImageDataStructure.h"

//--------------------------------------------------
//making pixels data structure with the same given color
ImageDataStructure::ImageDataStructure(int H, int W, unsigned char pixle) {
	//allocate the rows in the arr
	m_arr = new(std::nothrow) Pixel * [H];
	//allocate the cols of the arr and set the color
	for (int row = 0; row < H; row++) {
		m_arr[row] = new(std::nothrow) Pixel[W];
		//we set the color for every elment in the row
		for (int col = 0; col < W; col++) {
			m_arr[row][col] = pixle;
		}
	}
}

//--------------------------------------------------
ImageDataStructure::ImageDataStructure(const ImageDataStructure& image, int H, int W)
{
	m_arr = new(std::nothrow) Pixel * [H];
	for (int row = 0; row < H; row++)
	{
		m_arr[row] = new(std::nothrow) Pixel[W];
		//we set the color for every elment in the row
		for (int col = 0; col < W; col++) {
			m_arr[row][col] = image.m_arr[row][col];
		}
	}
}

//--------------------------------------------------
Pixel ImageDataStructure::operator()(unsigned int col, unsigned int row) const {
	return m_arr[row][col];
}

//--------------------------------------------------
Pixel& ImageDataStructure::operator()(unsigned int col, unsigned int row) {
	return m_arr[row][col];
}

//-------------------------------------------------
//deep deleting the pixes rows
void ImageDataStructure::free(int rows) {
	for (int row = 0; row < rows; row++) {
		delete m_arr[row];
	}
	delete m_arr;
}




