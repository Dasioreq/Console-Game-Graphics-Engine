#include "cligfx/sprite.hpp"

std::string convert(uint8_t* data, int width, int height, int channels)
{
	std::string result = "";

	for(int y = 0; y < height; y += 2)
	{
		for(int x = 0; x < width; x += 1)
		{
			std::string fgColor;
			if(data[(y * width + x) * channels + 3])
				fgColor = "\033[38;2;" +
				          std::to_string(data[(y * width + x) * channels + 0]) + ';' +
				          std::to_string(data[(y * width + x) * channels + 1]) + ';' +
				          std::to_string(data[(y * width + x) * channels + 2]) + 'm';
			else
				fgColor = "\033[30m";
			std::string bgColor;
			if(y + 1 < height)
			{
				if(data[((y + 1) * width + x) * channels + 3])
					bgColor = "\033[48;2;" +
					          std::to_string(data[((y + 1) * width + x) * channels + 0]) + ';' +
					          std::to_string(data[((y + 1) * width + x) * channels + 1]) + ';' +
					          std::to_string(data[((y + 1) * width + x) * channels + 2]) + 'm';
				else
					bgColor = "\033[49m";
			}
			else
				bgColor = "\033[49m";
			result += fgColor + bgColor + char(223);
		}
		result += "\n\033[0m";
	}

	return result;
}
