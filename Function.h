#include "Vector3.h"
#include"Matrix4x4.h"
#include <cassert>
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include  <math.h>

#include <Vector2.h>
#include <imgui.h>


struct Quaternion
{
	float x;
	float y;
	float z;
	float w;
};


Quaternion Multiply(const Quaternion& lhs , const Quaternion& rhs );

Quaternion IdentiyQuaternion();

Quaternion Conjugate(const Quaternion& quaternion);

float Norm(const Quaternion& quaternion);

Quaternion Normalize(const Quaternion& quaternion);

Quaternion Inverse(const Quaternion& quaternion);

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Normalize(Vector3 V1);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

Vector3 Cross(const Vector3& from, const Vector3& to);

float Dot(const Vector3& from, const Vector3& to);

float Length(Vector3 Cross);

