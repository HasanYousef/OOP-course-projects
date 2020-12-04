#pragma once


#include <iostream>
#include "ImageDataStructure.h"

//--------------------------------------------------

ImageDataStructure::ImageDataStructure(int H, int W, unsigned char pixle) {
	//allocate the rows in the arr
	*m_arr = new(std::nothrow) Pixel[H];
	//check if its not NULL
	if (H != 0 && *m_arr == NULL) {
		std::cout << "error";
		exit(EXIT_FAILURE);
	}
	//allocate the cols of the arr and set the color
	for (int row = 0; row < H; row++) {
		m_arr[row] = new(std::nothrow) Pixel[W];
		//check if its not NULL
		if (m_arr[row] == NULL) {
			std::cout << "error";
			exit(EXIT_FAILURE);
		}
		//we set the color for every elment in the row
		for (int col = 0; col < W; col++) {
			m_arr[row][col] = pixle;
		}
	}
}

//--------------------------------------------------
ImageDataStructure::ImageDataStructure(const ImageDataStructure& image, int H, int W)
{
	*m_arr = new(std::nothrow) Pixel[H];
	if (*m_arr == NULL) {
		std::cout << "error";
		exit(EXIT_FAILURE);
	}
	for (int row = 0; row < H; row++)
	{
		m_arr[row] = new(std::nothrow) Pixel[W];
		//check if its not NULL
		if (m_arr[row] == NULL) {
			std::cout << "error";
			exit(EXIT_FAILURE);
		}
		//we set the color for every elment in the row
		for (int col = 0; col < W; col++) {
			m_arr[row][col] = image.m_arr[row][col];
		}
	}
}

//--------------------------------------------------
Pixel ImageDataStructure::operator()(unsigned int col, unsigned int row) const {
	return m_arr[row][col].get_color();
}

//--------------------------------------------------
Pixel& ImageDataStructure::operator()(unsigned int col, unsigned int row) {
	return m_arr[row][col];
}

//--------------------------------------------------
void ImageDataStructure::free(int rows) {
	for (int row = 0; row < rows; row++) {
		delete m_arr[row];
	}
	delete m_arr;
}

