#pragma once

namespace Core {

class Vector2
{
	float x, y;

	public:
	Vector2();
	Vector2(const Vector2& v);
	Vector2(float x, float y);
	~Vector2();

	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	Vector2& operator=(const Vector2& v);
	Vector2& operator=(float v);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator+=(float v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator-=(float v);
	Vector2& operator*=(const Vector2& v);
	Vector2& operator*=(float v);
	Vector2& operator/=(const Vector2& v);
	Vector2& operator/=(float v);

	Vector2 const operator+(const Vector2& v) const;
	Vector2 const operator+(float v) const;
	Vector2 const operator-(const Vector2& v) const;
	Vector2 const operator-(float v) const;
	Vector2 const operator*(const Vector2& v) const;
	Vector2 const operator*(float v) const;
	Vector2 const operator/(const Vector2& v) const;
	Vector2 const operator/(float v) const;

	void Get(float& x, float& y) const;
	float GetX() const;
	float GetY() const;
	void Set(const Vector2& v);
	void Set(float x, float y);
	void SetX(float x);
	void SetY(float y);
	void Rotate(float Radian);
	void Normalize();
	void StabilizeEpsilon();
};

}
