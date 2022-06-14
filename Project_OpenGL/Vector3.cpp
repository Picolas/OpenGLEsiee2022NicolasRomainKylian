#include "Vector3.h"


Vector3 Vector3::normalize(Vector3 v1)
{
    float srt = std::sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
    return(Vector3(v1.x/srt, v1.y/srt, v1.z/srt));
}

Vector3 Vector3::operator-(Vector3& v1)
{
    return Vector3(v1.x - x, v1.y - y, v1.z - z);
}

Vector3 Vector3::operator+(Vector3& v1)
{
    return Vector3(v1.x + x, v1.y + y, v1.z + z);
}

Vector3 Vector3::operator+=(Vector3 v1)
{
    return Vector3(v1.x + x, v1.y + y, v1.z + z);
}

Vector3 Vector3::operator-=(Vector3 v1)
{
    return Vector3(v1.x - x, v1.y - y, v1.z - z);
}

Vector3 Vector3::operator= (Vector3 v1)
{
    return Vector3(v1);
}

Vector3 Vector3::operator-=(float value)
{
    return Vector3(x - value, y - value, z - value);
}

Vector3 Vector3::operator+=(float value)
{
    return Vector3(x + value, y + value, z + value);
}

Vector3 Vector3::operator*(float& value)
{
    return Vector3(x * value, y * value, z * value);
}

Vector3 Vector3::cross(Vector3& v1)
{
    return Vector3(y * v1.z - z * v1.y, -(x * v1.z - z * v1.x), x * v1.y - y * v1.x);
}


Vector3::Vector3()
{

}

Vector3::Vector3(const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3::Vector3(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}
