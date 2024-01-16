#pragma once
#include "Component.h"

class Behavior : public Component
{
public:
	//Behavior() = default;
	Behavior(Entity* parent = nullptr, BlackBoard* blackBoard = nullptr) : Component(parent, blackBoard) {};

	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual Component* Clone(Entity* resultEntity) override;

	protected :
	void OutsideScreen();
};

