#include "stdafx.h"
#include "Behavior.h"
#include "GameManager.h"

void Behavior::Init()
{
}

void Behavior::Update(float deltaTime)
{
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 5.f,
	m_entity->GetTransform()->GetPosition()->y);
	OutsideScreen();
}

void Behavior::Render()
{
}

void Behavior::OutsideScreen()
{
	if (m_entity->GetTransform()->GetPosition()->x < -200)
	{
		GameManager::Instance.AddEntityToDelete(m_entity);
	}
}
