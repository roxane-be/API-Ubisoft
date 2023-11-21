#include "stdafx.h"
#include "Entity.h"
#include "MainCharacter.h"

Entity::Entity(MainCharacter* owner)
{
	m_owner = owner;
}

void Entity::TakeDamage(int damageToTake)
{
	m_life - damageToTake <= 0 ? Death() : m_life -= damageToTake;
}

void Entity::Death()
{
	//
}

MainCharacter* Entity::GetOwner()
{
	return m_owner;
}
