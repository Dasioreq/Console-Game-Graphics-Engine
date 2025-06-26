#pragma once
#include "./utils.hpp"
#include <iostream>

class Image
{
private:
	int width, height, channels;
	uchar** pixels;
public:
	Image();
	Image(std::string filename, uchar expectedChannels = 0);
	Image(const uchar* stbiData, int width, int height, int channels);
	~Image();

	int getWidth() const;
	bool cutWidth(int width);
	int getHeight() const;
	bool cutHeight(int height);
	int getChannels() const;

	bool resize();
};
