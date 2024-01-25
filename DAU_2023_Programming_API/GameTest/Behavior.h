#pragma once
#include "Component.h"

class Behavior : public Component
{
public:
	Behavior(Entity* parent = nullptr) : Component(parent) {};

	//override function pure parent
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual Component* Clone(Entity* resultEntity) = 0;

	//function collision behavior
	virtual void OnCollision(Entity* other) = 0;
	virtual void OnTrigger(Entity* other) = 0;

	//function behavior
	virtual void Death() = 0;
	virtual void Damage() = 0;

protected:
	virtual void BehaviorOutsideScreen() = 0;
	bool CheckDistanceWithEntity(Entity* other, float distance);
	bool doOnceAttack = false;


};

