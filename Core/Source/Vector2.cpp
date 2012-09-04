#include <math.h>
#include "Vector2.h"

using namespace Core;


const float EpsilonDef = 0.01f;
#define Abs(val)((val) > 0 ? (val) : -(val))
#define EpsilonStab(v)if(v&&Abs(v)<EpsilonDef)v=0.0f

Vector2::Vector2() : x(.0f), y(.0f) {}
Vector2::Vector2(const Vector2& v) : x(v.x), y(v.y) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

bool Vector2::operator==(const Vector2& v) const
{
	return x == v.x && y == v.y;
}

bool Vector2::operator!=(const Vector2& v) const
{
	return x != v.x || y != v.y;
}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

Vector2& Vector2::operator=(float v)
{
	x = y = v;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2& Vector2::operator+=(float v)
{
	x += v;
	y += v;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2& Vector2::operator-=(float v)
{
	x -= v;
	y -= v;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

Vector2& Vector2::operator*=(float v)
{
	x *= v;
	y *= v;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

Vector2& Vector2::operator/=(float v)
{
	x /= v;
	y /= v;
	return *this;
}

const Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

const Vector2 Vector2::operator+(float v) const
{
	return Vector2(x + v, y + v);
}

const Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

const Vector2 Vector2::operator-(float v) const
{
	return Vector2(x - v, y - v);
}

const Vector2 Vector2::operator*(const Vector2& v) const
{
	return Vector2(x * v.x, y * v.y);
}

const Vector2 Vector2::operator*(float v) const
{
	return Vector2(x * v, y * v);
}

const Vector2 Vector2::operator/(const Vector2& v) const
{
	return Vector2(x / v.x, y / v.y);
}

const Vector2 Vector2::operator/(float v) const
{
	return Vector2(x / v, y / v);
}

void Vector2::Get(float& x, float& y) const
{
	x = this->x;
	y = this->y;
}

float Vector2::GetX() const
{
	return x;
}

float Vector2::GetY() const
{
	return y;
}

void Vector2::Set(const Vector2& v)
{
	x = v.x;
	y = v.y;
}

void Vector2::Set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::SetX(float x)
{
	this->x = x;
}

void Vector2::SetY(float y)
{
	this->y = y;
}

void Vector2::Rotate(float Radian)
{
	float rx = x;
	x = rx * cosf(Radian) - y * sinf(Radian);
	y = rx * sinf(Radian) + y * cosf(Radian);
}

void Vector2::Normalize()
{
	float len = sqrtf(x * x + y * y);
	if(len)
	{
		len = 1.f / len;
		x *= len;
		y *= len;
	}
}

void Vector2::StabilizeEpsilon()
{
	EpsilonStab(x);
	EpsilonStab(y);
}
