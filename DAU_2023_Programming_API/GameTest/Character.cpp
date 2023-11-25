#include "stdafx.h"
#include "Character.h"
#include "App/app.h"
#include "Entity.h"

Character::Character()
{
	//transform = Transform(Vector2f(0, 0), Vector2f(0, 0), Vector2f(1, 1));
	//sprite = VisualSprite();
	//entity = Entity(this);
}

Character::~Character()
{
	entityTransform = m_entity->GetTransform();
}

void Character::Init()
{
	//
}

void Character::Update(float deltaTime)
{
	//if (!sprite.IsNull())
	//	sprite.Update(deltaTime);
}

void Character::Render()
{
	//if (!sprite.IsNull())
	//	sprite.RenderSprite(transform.GetPosition());

	
}
