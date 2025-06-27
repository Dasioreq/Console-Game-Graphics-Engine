#pragma once
#include "utils.hpp"
#include "vector.hpp"

namespace cf
{
class Transformable
{
public:
	Transformable() = default;
	Transformable(const Vector2f& position);
	virtual ~Transformable() = default;

	Vector2f position = {0, 0};
};
}
