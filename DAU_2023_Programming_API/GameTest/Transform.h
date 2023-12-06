#pragma once
#include "Vector2.h"

class Transform
{
public:
	Transform() = default;
	Transform(Vector2f position, Vector2f rotation, Vector2f scale) : m_position(position), m_rotation(rotation), m_scale(scale){} ;

	void SetPosition(Vector2f position) { m_position = position; };
	void SetRotation(Vector2f rotation) { m_rotation = rotation; };
	void SetScale(Vector2f scale) { m_scale = scale; };

	void SetPosition(float x, float y) { m_position.SetVector2f(x, y); };
	void SetRotation(float x, float y) { m_rotation.SetVector2f(x, y); };
	void SetScale(float x, float y) { m_scale.SetVector2f(x, y); };

	Vector2f* GetPosition() { return &m_position; };
	Vector2f* GetRotation() { return &m_rotation; };
	Vector2f* GetScale() { return &m_scale; };

private:
	Vector2f m_position;
	Vector2f m_rotation;
	Vector2f m_scale{ 1, 1 };

};

