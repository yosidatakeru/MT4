#include "Quaternion.h"



Quaternion Quatrnion::MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle)
{
    float halfAngle = angle * 0.5f;
    float sinHalfAngle = std::sin(halfAngle);

    Quaternion result;
    result.w = std::cos(halfAngle);
    result.x = axis.x * sinHalfAngle;
    result.y = axis.y * sinHalfAngle;
    result.z = axis.z * sinHalfAngle;

    return result;
}

Vector3 Quatrnion::RotaVector(const Vector3& vector, const Quaternion& quaternion)
{
    Quaternion qv( vector.x, vector.y, vector.z,0.0f);

    Quaternion conjugate = { -quaternion.x, -quaternion.y, -quaternion.z, quaternion.w };

    Quaternion result = {};
    result.x = qv.x * conjugate.x;
    result.y = qv.y * conjugate.y;
    result.z = qv.z * conjugate.z;

    return Vector3(result.x, result.y, result.z);
}

Matrix4x4 Quatrnion::MakeRotatematrix(const Quaternion& quaternion)
{
    Matrix4x4 result;

    result.m[0][0] = 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z);
    result.m[0][1] = 2.0f * (quaternion.x * quaternion.y - quaternion.w * quaternion.z);
    result.m[0][2] = 2.0f * (quaternion.x * quaternion.z + quaternion.w * quaternion.y);
    result.m[0][3] = 0.0f;

    result.m[1][0] = 2.0f * (quaternion.x * quaternion.y + quaternion.w * quaternion.z);
    result.m[1][1] = 1.0f - 2.0f * (quaternion.x * quaternion.x + quaternion.z * quaternion.z);
    result.m[1][2] = 2.0f * (quaternion.y * quaternion.z - quaternion.w * quaternion.x);
    result.m[1][3] = 0.0f;

    result.m[2][0] = 2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y);
    result.m[2][1] = 2.0f * (quaternion.y * quaternion.z + quaternion.w * quaternion.x);
    result.m[2][2] = 1.0f - 2.0f * (quaternion.x * quaternion.x + quaternion.y * quaternion.y);
    result.m[2][3] = 0.0f;

    result.m[3][0] = 0.0f;
    result.m[3][1] = 0.0f;
    result.m[3][2] = 0.0f;
    result.m[3][3] = 1.0f;

    return result;
}

Vector3 Quatrnion::Transform(const Vector3& vector, const Quaternion& quaternion)
{
    Quaternion qv(vector.x, vector.y, vector.z, 0.0f);

    Quaternion conjugate = { -quaternion.x, -quaternion.y, -quaternion.z, quaternion.w };

    Quaternion result = {};
    result.x = qv.x * conjugate.x;
    result.y = qv.y * conjugate.y;
    result.z = qv.z * conjugate.z;

    return Vector3(result.x, result.y, result.z);
}
    
