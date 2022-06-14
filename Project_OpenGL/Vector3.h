#pragma once
#include <iostream>
class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3 normalize(Vector3 v1);

    Vector3 operator-(Vector3& v1);
    Vector3 operator+(Vector3& v1);
    Vector3 operator+=(Vector3 v1);
    Vector3 operator-=(Vector3 v1);
    Vector3 operator-=(float value);
    Vector3 operator+=(float value);
    Vector3 operator*(float& value);
    Vector3 operator=(Vector3 v1);

    Vector3 cross(Vector3& v1);

    Vector3();

    Vector3(const Vector3& v);

    Vector3(float _x, float _y, float _z);
};

