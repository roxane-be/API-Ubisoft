#pragma once
#include "Transform.h"
#include "VisualSprite.h"
class Character
{
public : 
	Character();
	~Character();

	//method
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	//properties
	Transform transform;
	VisualSprite sprite;
};

