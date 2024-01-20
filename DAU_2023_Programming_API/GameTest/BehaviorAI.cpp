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
	if (CheckDistanceWithPlayer() && !doOnceAttack)
	{
		m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_ATTACK;
		doOnceAttack = true;
	}

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

bool BehaviorAI::CheckDistanceWithPlayer()
{
	return FunctionLibrary::RaycastObject2D(*m_entity->GetTransform()->GetPosition(), *GameManager::Instance.mainCharacter->GetTransform()->GetPosition(), 170.f);
}
