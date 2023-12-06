#include "stdafx.h"
#include "Level.h"
#include "GameManager.h"


void Level::Init()
{

}

void Level::Update(float deltaTime)
{

}

void Level::Render()
{

}

void Level::Shutdown()
{
	m_ButtonEntities.clear();	
}

void Level::GetAllEntityLevel(std::list<Entity*>* _list)
{
	for (const auto element : (m_ButtonEntities))
	{
		_list->push_back(element);
	}
	if (mainCharacter != nullptr)
		_list->push_back(mainCharacter);
}

