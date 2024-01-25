#include "stdafx.h"
#include "BehaviorPlayer.h"
#include "App/app.h"
#include "cassert"

void BehaviorPlayer::Init()
{
}

void BehaviorPlayer::Update(float deltaTime)
{
	if (App::IsKeyPressed(VK_LBUTTON) && m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_WALK)
		m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_ATTACK;
	if (m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_WALK && doOnceAttack)
		doOnceAttack = false;
	if (m_entity->GetTransform()->GetPosition()->x < 300.0f)
		m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x + 0.2f, m_entity->GetTransform()->GetPosition()->y);

}

void BehaviorPlayer::Render()
{
}

void BehaviorPlayer::OnCollision(Entity* other)
{
}

void BehaviorPlayer::OnTrigger(Entity* other)
{
	//attack 
	if (!doOnceAttack && m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_ATTACK)
	{
		other->blackBoard->ptrFDamage();
		doOnceAttack = true;
	}
}

void BehaviorPlayer::Damage()
{
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 2.f, m_entity->GetTransform()->GetPosition()->y);
	BehaviorOutsideScreen();
}

void BehaviorPlayer::Death()
{
	if (GameManager::Instance.mainCharacter != nullptr)
	{
		GameManager::Instance.mainCharacter = nullptr;
		GameManager::Instance.AddEntityToDelete(m_entity);
	}
}

Component* BehaviorPlayer::Clone(Entity* resultEntity)
{
	assert(false);
	return nullptr;
}

void BehaviorPlayer::BehaviorOutsideScreen()
{
	if (m_entity->GetTransform()->GetPosition()->x <= 0)
	{
		Death();
	}
}
