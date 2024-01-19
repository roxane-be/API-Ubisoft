#include "stdafx.h"
#include "BehaviorAI.h"

void BehaviorAI::Init()
{
}

void BehaviorAI::Update(float deltaTime)
{
	//enemy move to left 
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 5.f, m_entity->GetTransform()->GetPosition()->y);
	//check if entity is outside the screen 
	OutsideScreen();
	//
	oui();

}

void BehaviorAI::Render()
{
}


Component* BehaviorAI::Clone(Entity* resultEntity)
{
	BehaviorAI* behavior = new BehaviorAI();
	//*behavior = *this  // deep copy

	behavior->m_entity = resultEntity;

	return behavior;
}

void BehaviorAI::oui()
{
	if (FunctionLibrary::RaycastObject2D(*m_entity->GetTransform()->GetPosition(), *GameManager::Instance.mainCharacter->GetTransform()->GetPosition(), 170.f))
	{
		m_entity->blackBoard->currentAnimation = VisualSprite::eAnimationSprite::ANIM_ATTACK;
	}
}
