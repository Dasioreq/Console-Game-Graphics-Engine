#pragma once

namespace cf
{
class FrameBuffer;

class Drawable
{
public:
	virtual ~Drawable() = default;
	void virtual draw(FrameBuffer& fb) const = 0;
};
}
