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
