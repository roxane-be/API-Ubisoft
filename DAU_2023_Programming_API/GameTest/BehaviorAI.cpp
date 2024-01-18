#include "stdafx.h"
#include "BehaviorAI.h"

void BehaviorAI::Init()
{
}

void BehaviorAI::Update(float deltaTime)
{
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 5.f,
		m_entity->GetTransform()->GetPosition()->y);
	OutsideScreen();
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