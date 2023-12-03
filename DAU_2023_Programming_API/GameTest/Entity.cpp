#include "stdafx.h"
#include "Entity.h"
#include "Character.h"


void Entity::Init()
{
}

void Entity::Update(float deltaTime)
{
	for (const auto& component : m_components)
	{
		component->Update(deltaTime);
	}
}

void Entity::Render()
{
	for (const auto& component : m_components)
	{
		component->Render();
	}
}

void Entity::AddComponent(Component* component)
{
	m_components.push_back(component);
}



// très rare d'avoir besoin de ça
// on préfère passer les components nécessaires à l'init ou au constructeur
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
