#include "stdafx.h"
#include "Entity.h"
#include "Character.h"

Entity::Entity()
{
	m_owner = nullptr;
}

Entity::Entity(Character* owner, int life, int damage)
{
	m_owner = owner;
	m_life = life;
	m_damage = damage;
}



void Entity::TakeDamage(int damageToTake)
{
	m_life - damageToTake <= 0 ? Death() : m_life -= damageToTake;
}

void Entity::Death()
{
	//
}

Character* Entity::GetOwner()
{
	return m_owner;
}

int Entity::GetLife()
{
	return m_life;
}

int Entity::GetDamage()
{
	return m_damage;
}
