#pragma once
#include "Vector3.h"
class Matrix4
{
public:
    float m[16];
    float i[16];
    Matrix4();
    Matrix4(float m1[16]);
    Matrix4(float value);

    Matrix4 lookAt(Vector3& eye, Vector3& target, Vector3& upDir);
    void identity();
    Matrix4 perspective(float fov, float aspect, float near, float far);
    Matrix4 operator*(Matrix4 mat);
};

