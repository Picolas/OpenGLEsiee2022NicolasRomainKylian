#pragma once
#include <iostream>

#include "Vector3.h"

class Vector2
{
public:
    float x;
    float y;

    Vector2 normalize(Vector2 v1);

    Vector2 operator-(Vector2& v1);
    Vector2 operator+(Vector2& v1);
    Vector2 operator+=(Vector2 v1);
    Vector2 operator-=(Vector2 v1);
    Vector2 operator-=(float value);
    Vector2 operator+=(float value);
    Vector2 operator*(float& value);
    Vector2 operator=(Vector2 v1);

    Vector2 cross(Vector2& v1);

    Vector2();

    Vector2(const Vector2& v);
    
    Vector2(float _x, float _y);
};

