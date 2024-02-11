#include "Vector3.h"
#include"Matrix4x4.h"
#include <cassert>
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include  <math.h>

#include <Vector2.h>
#include <imgui.h>

Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Vector3 Normalize(Vector3 V1);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

Vector3 Cross(const Vector3& from, const Vector3& to);

float Dot(const Vector3& from, const Vector3& to);

float Length(Vector3 Cross);