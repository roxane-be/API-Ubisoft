#pragma once
#include "Behavior.h"

class BehaviorPlayer : public Behavior
{
public:
	BehaviorPlayer(Entity* parent = nullptr) : Behavior(parent) {};

	//override function pure parent 
	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;
	virtual Component* Clone(Entity* resultEntity) override;

	//function Collision behavior
	virtual void OnCollision(Entity* other) override;
	virtual void OnTrigger(Entity* other) override;
	//function behavior
	virtual void Damage() override;
	virtual void Death() override;


protected:
	virtual void BehaviorOutsideScreen() override;


};

