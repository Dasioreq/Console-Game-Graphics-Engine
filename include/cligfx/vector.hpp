#pragma once
#include <span>
#include <string>
#include <math.h>
#include <cstdint>

template <typename T>
class Vector2
{
public:
    T x, y;

    Vector2(){}
    Vector2(T x, T y): x(x), y(y){}
    template <typename U>
    Vector2(Vector2<U>& arg)
    {
        x = (T)arg.x;
        y = (T)arg.y;
    }
    Vector2(std::span<T, 2>& args): x(args[0]), y(args[1]){}

    template <typename U = float>
    U magnitude()
    {
        return (U)sqrt(x * x + y * y);
    }

    template <typename U = float>
    Vector2<U> normalized()    
    {
        return Vector2<U>(x / this->magnitude(), y / this->magnitude());
    }

    Vector2<T> operator=(Vector2<T> arg)
    {
        x = arg.x;
        y = arg.y;
        return *this;
    }
    Vector2<T> operator=(std::span<T, 2> args)
    {
        x = args[0];
        y = args[1];
        return *this;
    }
    Vector2 operator+=(Vector2<T> arg)
    {
        *this = Vector2(x + arg.x, y + arg.y);
        return *this;
    }
    Vector2 operator-=(Vector2<T> arg)
    {
        *this = Vector2(x - arg.x, y - arg.y);
        return *this;
    }

    std::string print(const std::string& braces = "{}", const std::string& sep = ", ", const std::string& end = "\n")
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
};

template <typename T, typename U, template <typename> class Vector2, typename V = std::common_type<T, U>::type>
Vector2<V> operator*(Vector2<U> vec, T scalar)
{
    return Vector2(scalar * vec.x, scalar * vec.y);
}

template <typename T, typename U, template <typename> class Vector2, typename V = std::common_type<T, U>::type>
Vector2<V> operator*(T scalar, Vector2<U> vec)
{
    return vec * scalar;
}

template <typename T, typename U, template <typename> class Vector2, typename V = std::common_type<T, U>::type>
Vector2<V> operator+(Vector2<T> lhs, Vector2<U> rhs)
{
    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

template <typename T, typename U, template <typename> class Vector2, typename V = std::common_type<T, U>::type>
Vector2<V> operator-(Vector2<T> lhs, Vector2<U> rhs)
{
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

template <typename T, typename U, template <typename> class Vector2, typename V = std::common_type<T, U>::type>
float operator*(Vector2<T> lhs, Vector2<U> rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
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