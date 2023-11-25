#pragma once
#include "Transform.h"
#include "Component.h"

class Character : public Component
{
public : 
	Character();
	~Character();

	//method
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	//properties
	//VisualSprite sprite;

protected:
	Transform* entityTransform;
};

