#pragma once
#include <span>
#include <string>
#include <math.h>

template <typename T>
class Vector2
{
public:
    T x, y;

    Vector2(){}
    Vector2(T x, T y): x(x), y(y){}
    template <typename U>
    Vector2(Vector2<U>& arg):x((T)arg.x), y((T)arg.y){}
    Vector2(std::span<T, 2>& args): x(args[0]), y(args[1]){}

    template <typename U = float>
    U magnitude()
    {
        return (U)sqrt(x * x + y * y);
    }

    Vector2 normalized()
    {
        return *this / this->magnitude();
    }

    void normalize()
    {
        *this = this->normalized();
    }

    template <typename U>
    Vector2 operator+(Vector2<U> arg)
    {
        return {x + arg.x, y + arg.y};
    }
    
    template <typename U>
    Vector2 operator-(Vector2<U> arg)
    {
        return {x - arg.x, y - arg.y};
    }

    Vector2 operator-()
    {
        return Vector2(-x, -y);
    }

    template <typename U>
    Vector2 operator/(U scalar)
    {
        return Vector2(x / scalar, y / scalar);
    }

    template <typename U = float>
    U operator/(Vector2<T>& vec)
    {
        return (x * vec.x) + (y * vec.y);
    }

    template <typename U>
    Vector2 operator*(U scalar)
    {
        return Vector2(x * scalar, y * scalar);
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
    template <typename U>
    Vector2 operator+=(Vector2<U> arg)
    {
        *this = *this + arg;
        return *this;
    }
    template <typename U>
    Vector2 operator-=(Vector2<U> arg)
    {
        *this = *this - arg;
        return *this;
    }

    std::string print(const std::string& braces = "{}", const std::string& sep = ", ", const std::string& end = "\n")
    {
        std::string xStr = std::to_string(x);
        xStr.erase(xStr.find_last_not_of('0') + 1, std::string::npos);
        xStr.erase(xStr.find_last_not_of('.') + 1, std::string::npos);

        std::string yStr = std::to_string(y);
        yStr.erase(yStr.find_last_not_of('0') + 1, std::string::npos);
        yStr.erase(yStr.find_last_not_of('.') + 1, std::string::npos);

        return braces[0] + xStr + sep + yStr + braces[1] + end;
    }
};

template <typename T, typename U>
Vector2<U> operator*(U scalar, Vector2<T> vec)
{
    return Vector2(vec.x * scalar, vec.y * scalar);
}