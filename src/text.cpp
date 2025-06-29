#include "cligfx/text.hpp"

namespace cf
{
Text::Text(const std::string& string)
	: string(string)
{}

void Text::draw(FrameBuffer& fb) const
{
	int x = position.x;
	for(const char el : string)
	{
		fb.at({x, int(position.y)}) = el;
		x++;
	}
}
}
