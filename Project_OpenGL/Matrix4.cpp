#include "Matrix4.h"

void Matrix4::identity()
{

    for (int j = 0; j < 16; j++)
    {
        if (j % 5 == 0)
        {
            i[j] = 1;
        }
        else
        {
            i[j] = 0;
        }
    }
}

Matrix4 Matrix4::perspective(float fov, float aspect, float near, float far)
{
    float f = tanf(fov / 2.f);
    Matrix4 mat;
    float m1[] =
    {
        (f / aspect), 0.f, 0.f, 0.f,
        0.f, f, 0.f, 0.f,
        0.f, 0.f, (near + far) / (near - far), (2 * far * near) / (near - far),
        0.f, 0.f, -1.f, 0.f
    };
    for (int j = 0; j < 16; j++)
    {
        mat.m[j] = m1[j];
    }
    return mat;
}

Matrix4::Matrix4()
{

}

Matrix4::Matrix4(float value)
{
    for (int j = 0; j < 16; j++)
    {
        m[j] = value;
    }
}

Matrix4::Matrix4(float m1[16])
{
    for (int j = 0; j < 16; j++)
    {
        m[j] = m1[j];
    }
}

Matrix4 Matrix4::lookAt(Vector3& eye, Vector3& target, Vector3& upDir)
{
    // compute the forward vector from target to eye
    Vector3 forward = eye - target;
    forward.normalize(forward);                 // make unit length

    // compute the left vector
    Vector3 left = upDir.cross(forward); // cross product
    left.normalize(left);

    // recompute the orthonormal up vector
    Vector3 up = forward.cross(left);    // cross product

    // init 4x4 matrix
    Matrix4 matrix;
    matrix.identity();

    // set rotation part, inverse rotation matrix: M^-1 = M^T for Euclidean transform
    matrix.m[0] = left.x;
    matrix.m[4] = left.y;
    matrix.m[8] = left.z;
    matrix.m[1] = up.x;
    matrix.m[5] = up.y;
    matrix.m[9] = up.z;
    matrix.m[2] = forward.x;
    matrix.m[6] = forward.y;
    matrix.m[10] = forward.z;

    // set translation part
    matrix.m[12] = -left.x * eye.x - left.y * eye.y - left.z * eye.z;
    matrix.m[13] = -up.x * eye.x - up.y * eye.y - up.z * eye.z;
    matrix.m[14] = -forward.x * eye.x - forward.y * eye.y - forward.z * eye.z;

    return matrix;
}

Matrix4 Matrix4::operator*(Matrix4 mat) {
    Matrix4 new_m;
    float somme = 0;

    for (int x = 0; x < 4; x++) {
        //Parcours des lignes
        for (int i = 0; i < 4; i++) {

            //Parcours des colonnes
            for (int j = 0; j < 4; j++) {
                somme += m[(x * 4) + j] * mat.m[j * 4 + i];
            }
            new_m.m[i] = somme;
            somme = 0;
        }
    }

    return new_m;
}
