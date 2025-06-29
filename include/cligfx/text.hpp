#include "utils.hpp"
#include "transformable.hpp"
#include "drawable.hpp"
#include "framebuffer.hpp"

namespace cf
{
class Text : public Transformable, public Drawable
{
public:
	Text() = default;
	Text(const std::string& string);
	std::string string;

	void draw(FrameBuffer& fb) const override;
};
}
