#include "stdafx.h"
#include "BehaviorAI.h"
#include "cassert"
#include "App/app.h"

void BehaviorAI::Init()
{
}

void BehaviorAI::Update(float deltaTime)
{
	if (m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_DEATH)
		return;
	//enemy move to left 
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 5.f, m_entity->GetTransform()->GetPosition()->y);
	//check if entity is outside the screen 
	OutsideScreen();
	//
	if (CheckDistanceWithEntity(GameManager::Instance.mainCharacter, 150.f) && !doOnceAttack)
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
	behavior->m_entity->blackBoard->ptrFOnCollision = std::bind(&BehaviorAI::OnCollision, behavior, std::placeholders::_1);
	behavior->m_entity->blackBoard->ptrFDeath = std::bind(&BehaviorAI::Death, behavior);
	behavior->m_entity->blackBoard->ptrFDamage = std::bind(&BehaviorAI::Damage, behavior);
	return behavior;
}

void BehaviorAI::OnCollision(Entity* other)
{
	assert(false);
}

void BehaviorAI::Damage()
{
	m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_DEATH;
}

void BehaviorAI::Death()
{
	GameManager::Instance.AddEntityToDelete(m_entity);
}


