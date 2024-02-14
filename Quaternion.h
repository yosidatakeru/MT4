#pragma once
#include"Function.h"

class Quatrnion
{
	
public:
	Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);

	Vector3 RotaVector(const Vector3& vector, const Quaternion& quaternion);
    
	Matrix4x4 MakeRotatematrix(const Quaternion& quaterninon);

	Vector3 Transform(const Vector3& vector, const Quaternion& quaternion);
};


