#pragma once
#include "Component.h"


class Collision : public Component
{
public:
	Collision(Entity* parent = nullptr, BlackBoard* _blackboard = nullptr) : Component(parent, _blackboard) {};

	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

public:

	std::vector<Vector2f> m_points;
};

