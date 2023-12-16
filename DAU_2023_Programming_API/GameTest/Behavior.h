#pragma once
#include "Component.h"
class Behavior : public Component
{
public:
	Behavior() = default;
	Behavior(Entity* parent, BlackBoard* _blackBoard) : Component(parent, _blackBoard) {};

	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	protected :
	void OutsideScreen();
};

