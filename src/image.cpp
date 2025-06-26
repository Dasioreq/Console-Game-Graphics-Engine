#include "cligfx/image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image()
{}

Image::Image(std::string filename, uchar expectedChannels)
{
	const uchar* stbiData = stbi_load(filename.c_str(), &width, &height, &channels, expectedChannels);

	pixels = new uchar*[width * height];
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			pixels[y * width + x] = new uchar[channels];
			for(int c = 0; c < channels; c++)
			{
				pixels[y * width + x][c] = stbiData[y * width + x + c];
			}
		}
	}

	delete[] stbiData;
}

Image::Image(const uchar* stbiData, int width, int height, int channels) : width(width), height(height), channels(channels)
{
	pixels = new uchar*[width * height];
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			pixels[y * width + x] = new uchar[channels];
			for(int c = 0; c < channels; c++)
			{
				pixels[y * width + x][c] = stbiData[y * width + x + c];
			}
		}
	}

	delete[] stbiData;
}

Image::~Image()
{
	delete[] pixels;
}
