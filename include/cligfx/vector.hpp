#pragma once
#include "utils.hpp"

namespace cf
{
template<typename T>
class Vector2
{
public:
	T x, y;

	constexpr Vector2()
	{}
	constexpr Vector2(T x, T y) : x(x), y(y)
	{}
	template<typename U>
	constexpr Vector2(Vector2<U>& arg)
	{
		x = (T)arg.x;
		y = (T)arg.y;
		x + y;
	}
	constexpr Vector2(std::span<T, 2>& args) : x(args[0]), y(args[1])
	{}

	template<typename U = float>
	constexpr U magnitude()
	{
		return (U)sqrt(x * x + y * y);
	}

	template<typename U = float>
	constexpr Vector2<U> normalized()
	{
		return Vector2<U>(x / this->magnitude(), y / this->magnitude());
	}

	constexpr Vector2<T> operator=(Vector2<T> arg)
	{
		x = arg.x;
		y = arg.y;
		return *this;
	}
	constexpr Vector2<T> operator=(std::span<T, 2> args)
	{
		x = args[0];
		y = args[1];
		return *this;
	}
	constexpr Vector2 operator+=(Vector2<T> arg)
	{
		*this = Vector2(x + arg.x, y + arg.y);
		return *this;
	}
	constexpr Vector2 operator-=(Vector2<T> arg)
	{
		*this = Vector2(x - arg.x, y - arg.y);
		return *this;
	}
	template<typename U>
	constexpr Vector2 operator*=(U scalar)
	{
		x = (T)(x * scalar);
		y = (T)(y * scalar);
	}
	template<typename U>
	constexpr Vector2 operator/=(U scalar)
	{
		x = (T)(x / scalar);
		y = (T)(y / scalar);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector2<V> operator+(Vector2<U> rhs)
	{
		return Vector2<V>(x + rhs.x, y + rhs.y);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector2<V> operator-(Vector2<U> rhs)
	{
		return Vector2<V>(x - rhs.x, y - rhs.y);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector2<V> operator*(U scalar)
	{
		return Vector2<V>(scalar * x, scalar * y);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector2<V> operator/(U scalar)
	{
		return Vector2<V>(x / scalar, y / scalar);
	}

	template<typename U, typename V = float>
	constexpr V operator*(Vector2<U> rhs)
	{
		return x * rhs.x + y * rhs.y;
	}

	template<typename U, typename V = float>
	constexpr V dot(Vector2<U> rhs)
	{
		return x * rhs.x + y * rhs.y;
	}

	constexpr std::string print(const std::string& braces = "{}", const std::string& sep = ", ", const std::string& end = "\n")
	{
		std::string xStr = std::to_string(x);

		if(xStr != "0")
		{
			xStr.erase(xStr.find_last_not_of('0') + 1, std::string::npos);
		}

		std::string yStr = std::to_string(y);

		if(yStr != "0")
		{
			yStr.erase(yStr.find_last_not_of('0') + 1, std::string::npos);
		}

		if(std::is_same<T, float>())
		{
			xStr += 'f';
			yStr += 'f';
		}

		return braces[0] + xStr + sep + yStr + braces[1] + end;
	}

	operator bool()
	{
		return true;
	}
};

template<typename T, typename U, template<typename> class Vector2, typename V = std::common_type<T, U>::type>
constexpr inline Vector2<V> operator*(T scalar, Vector2<U> vec)
{
	return vec * scalar;
}

typedef Vector2<int8_t> Vector2i8;
typedef Vector2<uint8_t> Vector2u8;
typedef Vector2<int16_t> Vector2i16;
typedef Vector2<uint16_t> Vector2u16;
typedef Vector2<int32_t> Vector2i32;
typedef Vector2<int32_t> Vector2i;
typedef Vector2<uint32_t> Vector2u32;
typedef Vector2<uint32_t> Vector2u;
typedef Vector2<int64_t> Vector2i64;
typedef Vector2<uint64_t> Vector2u64;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

constexpr Vector2i Vector2left(1, 0);
constexpr Vector2i Vector2right(-1, 0);
constexpr Vector2i Vector2up(0, 1);
constexpr Vector2i Vector2down(0, -1);

template<typename T>
class Vector3
{
public:
	T x, y, z;

	constexpr Vector3()
	{}
	constexpr Vector3(T x, T y, T z) : x(x), y(y), z(z)
	{}
	template<typename U>
	constexpr Vector3(Vector3<U>& arg)
	{
		x = (T)arg.x;
		y = (T)arg.y;
		z = (T)arg.z;
	}
	constexpr Vector3(std::span<T, 3>& args) : x(args[0]), y(args[1]), z(args[2])
	{}

	template<typename U = float>
	constexpr U magnitude()
	{
		return (U)sqrt(x * x + y * y + z * z);
	}

	template<typename U = float>
	constexpr Vector3<U> normalized()
	{
		return Vector3<U>(x / this->magnitude(), y / this->magnitude(), z / this->magnitude());
	}

	constexpr Vector3<T> operator=(Vector3<T> arg)
	{
		x = arg.x;
		y = arg.y;
		z = arg.z;
		return *this;
	}
	constexpr Vector3<T> operator=(std::span<T, 3> args)
	{
		x = args[0];
		y = args[1];
		z = args[2];
		return *this;
	}
	constexpr Vector3<T> operator+=(Vector3<T> arg)
	{
		*this = Vector3(x + arg.x, y + arg.y, z + arg.z);
		return *this;
	}
	constexpr Vector3<T> operator-=(Vector3<T> arg)
	{
		*this = Vector3(x - arg.x, y - arg.y, z - arg.z);
		return *this;
	}
	template<typename U>
	constexpr Vector3 operator*=(U scalar)
	{
		x = (T)(x * scalar);
		y = (T)(y * scalar);
		z = (T)(z * scalar);
	}
	template<typename U>
	constexpr Vector3 operator/=(U scalar)
	{
		x = (T)(x / scalar);
		y = (T)(y / scalar);
		z = (T)(z / scalar);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> operator+(Vector3<U> rhs)
	{
		return Vector3<V>(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> operator-(Vector3<U> rhs)
	{
		return Vector3<V>(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> operator*(U scalar)
	{
		return Vector3<V>(scalar * x, scalar * y, z * scalar);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> operator/(U scalar)
	{
		return Vector3<V>(x / scalar, y / scalar, z / scalar);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr V operator*(Vector3<U> rhs)
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr V dot(Vector3<U> rhs)
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> operator/(Vector3<U> rhs)
	{
		return Vector3<V>(y * rhs.z - rhs.y * z, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}

	template<typename U, typename V = std::common_type<T, U>::type>
	constexpr Vector3<V> cross(Vector3<U> rhs)
	{
		return Vector3<V>(y * rhs.z - rhs.y * z, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}

	constexpr std::string print(const std::string& braces = "{}", const std::string& sep = ", ", const std::string& end = "\n")
	{
		std::string xStr = std::to_string(x);
		std::string yStr = std::to_string(y);
		std::string zStr = std::to_string(z);

		if(std::is_floating_point<T>())
		{
			xStr.erase(xStr.find_last_not_of('0') + 1);
			yStr.erase(yStr.find_last_not_of('0') + 1);
			zStr.erase(zStr.find_last_not_of('0') + 1);
		}

		if(std::is_same<T, float>())
		{
			xStr += 'f';
			yStr += 'f';
			zStr += 'f';
		}

		return braces[0] + xStr + sep + yStr + sep + zStr + braces[1] + end;
	}

	constexpr operator bool()
	{
		return true;
	}
};

template<typename T, typename U, template<typename> class Vector2, typename V = std::common_type<T, U>::type>
constexpr inline Vector3<V> operator*(T scalar, Vector3<U> vec)
{
	return vec * scalar;
}


typedef Vector3<int8_t> Vector3i8;
typedef Vector3<uint8_t> Vector3u8;
typedef Vector3<int16_t> Vector3i16;
typedef Vector3<uint16_t> Vector3u16;
typedef Vector3<int32_t> Vector3i32;
typedef Vector3<int32_t> Vector3i;
typedef Vector3<uint32_t> Vector3u32;
typedef Vector3<uint32_t> Vector3u;
typedef Vector3<int64_t> Vector3i64;
typedef Vector3<uint64_t> Vector3u64;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

constexpr Vector3i Vector3left(1, 0, 0);
constexpr Vector3i Vector3right(-1, 0, 0);
constexpr Vector3i Vector3up(0, 1, 0);
constexpr Vector3i Vector3down(0, -1, 0);
constexpr Vector3i Vector3forward(0, 0, 1);
constexpr Vector3i Vector3back(0, 0, -1);
}
