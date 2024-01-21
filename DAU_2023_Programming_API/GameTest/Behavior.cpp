#include "stdafx.h"
#include "Behavior.h"
#include "GameManager.h"


bool Behavior::CheckDistanceWithEntity(Entity* other, float distance)
{
	return FunctionLibrary::RaycastObject2D(*m_entity->GetTransform()->GetPosition(), *other->GetTransform()->GetPosition(), distance);
}