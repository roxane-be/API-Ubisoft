#include "stdafx.h"
#include "Behavior.h"
#include "GameManager.h"

void Behavior::OutsideScreen()
{
	if (m_entity->GetTransform()->GetPosition()->x < -200)
	{
		GameManager::Instance.AddEntityToDelete(m_entity);
	}
}

bool Behavior::CheckDistanceWithEntity(Entity* other, float distance)
{
	return FunctionLibrary::RaycastObject2D(*m_entity->GetTransform()->GetPosition(), *other->GetTransform()->GetPosition(), distance);
}