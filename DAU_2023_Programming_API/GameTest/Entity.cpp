#include "stdafx.h"
#include "Entity.h"
#include "Character.h"

Entity::Entity()
{
	
}

void Entity::Init()
{
}

void Entity::Update(float deltaTime)
{
}

void Entity::Render()
{
}



// tr�s rare d'avoir besoin de �a
// on pr�f�re passer les components n�cessaires � l'init ou au constructeur
//Character* Entity::SearchCharacter()
//{
//	Character* FoundChar = nullptr;
//
//	for (auto c : m_components)
//	{
//		if (FoundChar = dynamic_cast<Character*>(c) != NULL)
//		{
//			return FoundChar;
//		}
//
//	}
//
//	return nullptr;
//}





//Entity::Entity(Character* owner, int life, int damage)
//{
//	m_owner = owner;
//	m_life = life;
//	m_damage = damage;
//}
//
//
//
//void Entity::TakeDamage(int damageToTake)
//{
//	m_life - damageToTake <= 0 ? Death() : m_life -= damageToTake;
//}
//
//void Entity::Death()
//{
//	//
//}
//
//Character* Entity::GetOwner()
//{
//	return m_owner;
//}
//
//int Entity::GetLife()
//{
//	return m_life;
//}
//
//int Entity::GetDamage()
//{
//	return m_damage;
//}
