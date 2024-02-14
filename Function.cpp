#include"Function.h"
#include<assert.h>


Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs)
{ 
	
	Quaternion result = {
	 
	  lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
	  lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
	  lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
	  lhs.w* rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
	};
	
	 return result ;
}




Quaternion IdentiyQuaternion()
{
	Quaternion result = { 0.0f, 0.0f, 0.0f, 0.1f };
	return result;
}



Quaternion Conjugate(const Quaternion& quaternion)
{
	Quaternion result = {-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w };
	return result;
}



float Norm(const Quaternion& quaternion)
{
	float result = 0.0f;
	result = sqrtf(
		
		quaternion.x * quaternion.x +
		quaternion.y * quaternion.y +
		quaternion.z * quaternion.z +
		quaternion.w * quaternion.w );

	return result;
}

Quaternion Normalize(const Quaternion& quaternion)
{
	Quaternion result = {};


	float length = sqrtf(
		quaternion.w * quaternion.w +
		quaternion.x * quaternion.x +
		quaternion.y * quaternion.y +
		quaternion.z * quaternion.z);



	Quaternion preResult = {};
	preResult.x = quaternion.x;
	preResult.y = quaternion.y;
	preResult.z = quaternion.z;
	preResult.w = quaternion.w;

	if (length != 0.0f) {
		preResult.x = quaternion.x / length;
		preResult.y = quaternion.y / length;
		preResult.z = quaternion.z / length;
		preResult.w = quaternion.w / length;

	}

	result.x = preResult.x;
	result.y = preResult.y;
	result.z = preResult.z;
	result.w = preResult.w;


	return result;
}

Quaternion Inverse(const Quaternion& quaternion)
{
	Quaternion result = {};


	float norm = Norm(quaternion);
	Quaternion conjugate = Conjugate(quaternion);

	float t = norm * norm;

	result.x = conjugate.x / t;
	result.y = conjugate.y / t;
	result.z = conjugate.z / t;
	result.w = conjugate.w / t;


	return result;
}







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

Matrix4x4  DirectionToDirection(const Vector3& from, const Vector3& to)
{
	Matrix4x4 result = {};
	Vector3 cross = Cross(from, to);
	float cos = Dot(from, to);
	float sin = Length(cross);
	float epsilon = 1e-6f;

	Vector3 axis = {};
	if (std::abs(cos + 1.0f) <= epsilon)
	{
		if (std::abs(from.x) > epsilon || std::abs(from.y) > epsilon)
		{
			axis.x = from.y;
			axis.y = -from.x;
			axis.z = 0.0f;
		}
		else if (std::abs(from.x) > epsilon || std::abs(from.z) > epsilon)
		{
			axis.x = from.z;
			axis.y = 0.0f;
			axis.z = -from.x;
		}
		axis = Normalize(axis);
			
		
	}else
	{
		axis = Normalize(cross);
	}


	
	Matrix4x4 resultR = {};
	resultR.m[0][0] = axis.x * axis.x * (1 - cos) + cos;
	resultR.m[0][1] = axis.x * axis.y * (1 - cos) +sin ;
	resultR.m[0][2] = axis.x * axis.z * (1 - cos) - sin;
	resultR.m[0][3] = 0.0f;

	resultR.m[1][0] = axis.y* axis.x * (1 - cos) - sin;
	resultR.m[1][1] = axis.y* axis.y * (1 - cos) + cos;
	resultR.m[1][2] = axis.y* axis.z * (1 - cos) + sin;
	resultR.m[1][3] = 0.0f;

	resultR.m[2][0] = axis.z * axis.x * (1 - cos) + sin;
	resultR.m[2][1] = axis.z * axis.y * (1 - cos) - sin;
	resultR.m[2][2] = axis.z * axis.z * (1 - cos) + cos;
	resultR.m[2][3] = 0.0f;

	resultR.m[3][0] = 0.0f;
	resultR.m[3][1] = 0.0f;
	resultR.m[3][2] = 0.0f;
	resultR.m[3][3] = 1.0f;

	return resultR;
}

		
	







Vector3 Cross(const Vector3& from, const Vector3& to)
{
	/*Vector3 result = {};
	result.x = from.y * to.z - from.z * to.y;
	result.y = from.z * to.x - from.x * to.z;
	result.z = from.x * to.y - from.y * to.x;
	return result;*/
	return Vector3(
		from.y * to.z - from.z * to.y,
		from.z * to.x - from.x * to.z,
		from.x * to.y - from.y * to.x
	);
}



float Dot(const Vector3& from, const Vector3& to)
{

	/*Vector3  result;
	result.x = from.x * to.x;
	result.y = from.y * to.y;
	result.z = from.z * to.z;

	
	return result;*/
	  return from.x * to.x + from.y * to.y + from.z * to.z;
}

float Length(Vector3 Cross)
{

	return Cross.x * Cross.x + Cross.y * Cross.y + Cross.z * Cross.z;
}



