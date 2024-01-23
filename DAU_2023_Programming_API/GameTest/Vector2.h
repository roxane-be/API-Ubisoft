#pragma once

struct Vector2f
{
public:
	Vector2f(float _x = 0, float _y = 0) : x(_x), y(_y) {};
	Vector2f GetVector2f() { return Vector2f(x, y); }
	void SetVector2f(float x, float y) { this->x = x; this->y = y; }

	Vector2f operator+(const Vector2f& other) const {
		return Vector2f(x + other.x, y + other.y);
	}

	Vector2f operator-(const Vector2f& other) const {
		return Vector2f(x - other.x, y - other.y);
	}


	Vector2f operator+=(float scalar) {
		x += scalar;
		y += scalar;
		return *this;
	}

	Vector2f operator-(float scalar) const {
		return Vector2f(x - scalar, y - scalar);
	}

	Vector2f operator/(float scalar) const {
		return Vector2f(x / scalar, y / scalar);
	}

	Vector2f& operator/=(const Vector2f& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2f& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	float x;
	float y;

};




