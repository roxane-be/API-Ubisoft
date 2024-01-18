#pragma once
#include "Component.h"

class Behavior : public Component
{
public:
	//Behavior() = default;
	Behavior(Entity* parent = nullptr) : Component(parent) {};

	virtual void Init() =0;
	virtual void Update(float deltaTime)=0;
	virtual void Render()=0;

	virtual Component* Clone(Entity* resultEntity) =0;

protected:
	void OutsideScreen();

};

