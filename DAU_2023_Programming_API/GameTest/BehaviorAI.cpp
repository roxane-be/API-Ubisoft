#include "stdafx.h"
#include "BehaviorAI.h"
#include "cassert"
#include "App/app.h"

void BehaviorAI::Init()
{
}

void BehaviorAI::Update(float deltaTime)
{

	if(GameManager::Instance.mainCharacter->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_DEATH)
	GameManager::Instance.AddEntityToDelete(m_entity);
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
	behavior->m_entity->blackBoard->ptrFOnTrigger = std::bind(&BehaviorAI::OnTrigger, behavior, std::placeholders::_1);
	behavior->m_entity->blackBoard->ptrFDeath = std::bind(&BehaviorAI::Death, behavior);
	behavior->m_entity->blackBoard->ptrFDamage = std::bind(&BehaviorAI::Damage, behavior);
	return behavior;
}

void BehaviorAI::OnCollision(Entity* other)
{
if(other->blackBoard->currentAnimation != AnimationSprite::eAnimationSprite::ANIM_DEATH)
	other->blackBoard->ptrFDamage();

}

void BehaviorAI::OnTrigger(Entity* other)
{
}

void BehaviorAI::Damage()
{
	m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_DEATH;
}

void BehaviorAI::Death()
{
	GameManager::Instance.AddEntityToDelete(m_entity);
}

void BehaviorAI::OutsideScreen()
{
	if (m_entity->GetTransform()->GetPosition()->x < -200)
	{
		GameManager::Instance.AddEntityToDelete(m_entity);
	}
}


