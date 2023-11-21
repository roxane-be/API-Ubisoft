#pragma once
#include "Transform.h"
#include "VisualSprite.h"
#include "Entity.h"

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

protected:
	Entity entity;
};

