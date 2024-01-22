#pragma once
#include "Behavior.h"

#define TIMING_ATTACK 0.5f
class BehaviorPlayer : public Behavior
{
public :
	BehaviorPlayer(Entity* parent = nullptr) : Behavior(parent) {};
	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual void OnCollision(Entity* other) override;
	virtual void OnTrigger(Entity* other) override;

	virtual void Damage() override;
	virtual void Death() override;

	virtual Component* Clone(Entity* resultEntity) override;

	protected: 
	float timingAttack = TIMING_ATTACK;
	virtual void OutsideScreen() override;


};

