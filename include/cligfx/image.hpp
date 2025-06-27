#pragma once
#include "./utils.hpp"

class Image
{
private:
	int width, height, channels;
	uint8_t** pixels;
public:
	Image();
	Image(std::string filename, uint8_t expectedChannels = 0);
	Image(const uint8_t* stbiData, int width, int height, int channels);
	~Image();

	int getWidth() const;
	bool cutWidth(int width);
	int getHeight() const;
	bool cutHeight(int height);
	int getChannels() const;

	bool resize();
};
