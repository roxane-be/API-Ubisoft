#include "stdafx.h"
#include "Level.h"
#include "GameManager.h"
#include <filesystem>



void Level::Init()
{
	m_entitiesList.clear();

	std::string pathFile;
	switch (GameManager::Instance.currentLevel)
	{
	case Game :
		pathFile = ".\\TestData\\LoadEntities\\LevelGame";

	break;
	case MainMenu :
		pathFile = ".\\TestData\\LoadEntities\\LevelMenu";

	break;
	default:
		break;
	}

	for (const auto& entry : std::filesystem::directory_iterator(pathFile))
	{
		if (entry.is_regular_file())
		{
			Entity* entity = new Entity();
			entity->Load(entity, entry.path().string());
			m_entitiesList.push_back(entity);
		}
	}
}

void Level::Update(float deltaTime)
{

}

void Level::Render()
{

}

void Level::Shutdown()
{
}

void Level::GetAllEntityLevel(std::list<Entity*>* _list)
{
	for (const auto element : (m_entitiesList))
	{
		_list->push_back(element);
	}
	/*for (const auto element : m_EnemiesEntities)
	{
		_list->push_back(element);
	}
	if (mainCharacter != nullptr)
		_list->push_back(mainCharacter);*/
}

