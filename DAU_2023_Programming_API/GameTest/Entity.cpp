#include "stdafx.h"
#include "Entity.h"


void Entity::Init()
{
}

void Entity::Update(float deltaTime)
{
	for (const auto component : m_components)
	{
		component->Update(deltaTime);
	}
}

void Entity::Render()
{
	for (const auto component : m_components)
	{
		component->Render();
	}
}

void Entity::Shutdown()
{

}

void Entity::AddComponent(Component* component)
{
	m_components.push_back(component);
}
