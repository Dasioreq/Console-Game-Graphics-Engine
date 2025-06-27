#include "utils.hpp"
#include "vector.hpp"

namespace cf
{
class Transformable
{
public:
	Transformable() = default;
	Transformable(Vector2f position);
	virtual ~Transformable() = default;

	Vector2f position = {0, 0};
};
}
