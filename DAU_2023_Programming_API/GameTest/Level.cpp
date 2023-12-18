#include "stdafx.h"
#include "Level.h"
#include "GameManager.h"
#include <filesystem>
#include <cassert>
#include <ctime>  
#include "App/app.h"



void Level::Init()
{
	m_entitiesList.clear();

	std::string pathFile;
	switch (GameManager::Instance.currentLevel)
	{
	case Game:
		pathFile = ".\\TestData\\LoadEntities\\LevelGame";

		break;
	case MainMenu:
		pathFile = ".\\TestData\\LoadEntities\\LevelMenu";

		break;
	default:
		break;
	}
	srand(time(0));

	for (const auto& entry : std::filesystem::directory_iterator(pathFile))
	{
		if (entry.is_regular_file())
		{
			std::string pathLoad = entry.path().string();
			if (entry.path().string().find("LoadWave") != std::string::npos)
			{				
				LoadWaveEnemies(pathLoad, pathFile, &m_entitiesList);
			}
			else
			{
				Entity* entity = new Entity();
				entity->Load(entity, pathLoad);
				m_entitiesList.push_back(entity);
			}
		}
	}
}

void Level::Update(float deltaTime)
{
	timeWave -= deltaTime*0.001;
	if (timeWave <0)
	{
		std::string pathFile = ".\\TestData\\LoadEntities\\LevelGame";
		std::string pathLoad = pathFile;
		pathLoad += "\\LoadWave\\LoadWave";
		pathLoad += std::to_string(currentWave);
		pathLoad += ".txt";
		LoadWaveEnemies(pathLoad, pathFile, m_gameManager->GetActiveEntity());
	}

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
}

void Level::LoadWaveEnemies(std::string _pathLoad,std::string _pathFile, std::list<Entity*>* _entityList )
{
	std::ifstream myFile(_pathLoad);
	if (myFile)
	{
		std::string line;
		myFile >> line;
		timeWave = std::stof(line);
			currentWave++;
		do
		{
			myFile >> line;
			_pathLoad = _pathFile;
			_pathLoad += line;
			Entity* entity = new Entity();
			entity->Load(entity, _pathLoad);
			entity->GetTransform()->SetPosition((rand() % 1000) + 1000, entity->GetTransform()->GetPosition()->y);
			_entityList->push_back(entity);
		} while (!myFile.eof());
	}
}

