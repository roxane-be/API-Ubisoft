#pragma once
#include "Behavior.h"
class BehaviorPlayer : public Behavior
{
public :
	BehaviorPlayer(Entity* parent = nullptr) : Behavior(parent) {};
	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual Component* Clone(Entity* resultEntity) override;
};

