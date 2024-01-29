#include"Function.h"

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle)
{
	Matrix4x4 result{};
	float cosAngle = cosf(angle);
	float sinAngle = sinf(angle);

	

	result.m[0][0] = (axis.x * axis.x) * (1.0f - cosAngle) + cosAngle;
	result.m[0][1] = (axis.x * axis.y) * (1.0f - cosAngle) - axis.z * sinAngle;
	result.m[0][2] = (axis.x * axis.z) * (1.0f - cosAngle) + axis.y * sinAngle;
										   
	result.m[1][0] = (axis.x * axis.y) * (1.0f - cosAngle) + axis.z * sinAngle;
	result.m[1][1] = (axis.y * axis.y) * (1.0f - cosAngle) + cosAngle;
	result.m[1][2] = (axis.y * axis.z) * (1.0f - cosAngle) - axis.x * sinAngle;
										   
	result.m[2][0] = (axis.x * axis.z) * (1.0f - cosAngle) - axis.y * sinAngle;
	result.m[2][1] = (axis.y * axis.z) * (1.0f - cosAngle) + axis.x * sinAngle;
	result.m[2][2] = (axis.z * axis.z) * (1.0f - cosAngle) + cosAngle;
	return result;
}

Vector3 Normalize(Vector3 V1) 
{
	Vector3 result = {};

	float length = sqrt(V1.x * V1.x + V1.y * V1.y + V1.z * V1.z);

	float newX = V1.x;
	float newY = V1.y;
	float newZ = V1.z;


	if (length != 0.0f) {
		newX = V1.x / length;
		newY = V1.y / length;
		newZ = V1.z / length;

	}

	result.x = newX;
	result.y = newY;
	result.z = newZ;


	return result;
}

