#include "cligfx/framebuffer.hpp"

namespace cf
{
FrameBuffer::FrameBuffer(const Vector2i& size, const char& fill)
	: frame(size.x * size.y, fill), size(size)
{
	std::cout << "\033[2J";
	std::cout << "\033[?25l";
}

FrameBuffer::~FrameBuffer()
{
	std::cout << "\033[?25h";
}

char& FrameBuffer::at(const Vector2i& position)
{
	if(isValid(position))
		return frame[position.y * size.x + position.x];
	else
		return overflow;
}

const char& FrameBuffer::at(const Vector2i& position) const
{
	if(isValid(position))
		return frame[position.y * size.x + position.x];
	else
		return overflow;
}

void FrameBuffer::clear(const char& fill)
{
	std::fill(frame.begin(), frame.end(), fill);
	std::cout << "\033[H";
}

void FrameBuffer::draw(const Drawable& object)
{
	object.draw(*this);
}

void FrameBuffer::display() const
{
	for(int y = 0; y < size.y; y++)
	{
		std::string_view row(&frame[y * size.x], size.x);
		std::cout << row << '\n';
	}
	std::cout.flush();
}

bool FrameBuffer::isValid(const Vector2i& position) const
{
	return (position.x >= 0 && position.x < size.x &&
	        position.y >= 0 && position.y < size.y);
}
}
