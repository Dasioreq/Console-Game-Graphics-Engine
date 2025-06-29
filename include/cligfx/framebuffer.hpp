#pragma once
#include "utils.hpp"
#include "vector.hpp"
#include "drawable.hpp"

namespace cf
{
class FrameBuffer
{
public:
	FrameBuffer(const Vector2i& size, const char& fill = ' ');
	~FrameBuffer();

	char& at(const Vector2i& position);
	const char& at(const Vector2i& position) const;
	void clear(const char& fill = ' ');
	void draw(const Drawable& object);
	void display() const;
private:
	bool isValid(const Vector2i& position) const;

	std::vector<char> frame;
	const Vector2i size;
	char overflow;
};
}
