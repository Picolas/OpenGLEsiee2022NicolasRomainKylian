#include "Vector2.h"

Vector2 Vector2::normalize(Vector2 v1)
{
    float srt = std::sqrt(v1.x * v1.x + v1.y * v1.y);
    return(Vector2(v1.x / srt, v1.y / srt));
}

Vector2 Vector2::operator-(Vector2& v1)
{
    return Vector2(v1.x - x, v1.y - y);
}

Vector2 Vector2::operator+(Vector2& v1)
{
    return Vector2(v1.x + x, v1.y + y);
}

Vector2 Vector2::operator+=(Vector2 v1)
{
    return Vector2(v1.x + x, v1.y + y);
}

Vector2 Vector2::operator-=(Vector2 v1)
{
    return Vector2(v1.x - x, v1.y - y);
}

Vector2 Vector2::operator= (Vector2 v1)
{
    return Vector2(v1);
}

Vector2 Vector2::operator-=(float value)
{
    return Vector2(x - value, y - value);
}

Vector2 Vector2::operator+=(float value)
{
    return Vector2(x + value, y + value);
}

Vector2 Vector2::operator*(float& value)
{
    return Vector2(x * value, y * value);
}


Vector2::Vector2()
{

}

Vector2::Vector2(const Vector2& v)
{
    x = v.x;
    y = v.y;
}

Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

