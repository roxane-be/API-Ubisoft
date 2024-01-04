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
	timeWave = 0;
	currentWave = 0;

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
		//check only file txt 
		if (entry.is_regular_file())
		{
			std::string pathLoad = entry.path().string();

			/*if (entry.path().string().find("LoadWave") != std::string::npos)
			{
				LoadWaveEnemies(pathLoad, pathFile);
			}
			else*/
			{
				Entity* entity = new Entity();
				entity->Load(entity, pathLoad);
				m_entitiesList.push_back(entity);
				if (entry.path().string().find("MainCharacter") != std::string::npos)
				{
					GameManager::Instance.mainCharacter = entity;
				}
			}
		}
		//check if a folder is a Load Wave
		if (entry.path().string().find("LoadWave") != std::string::npos)
		{
			LoadWaves(entry.path().string(), pathFile);
		}

	}
	LoadNewWave(&m_entitiesList);

}

void Level::Update(float deltaTime)
{
	timeWave -= deltaTime;
	if (timeWave <0)
	{
		LoadNewWave(m_gameManager->GetActiveEntity());
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

void Level::LoadWaves(std::string _pathFolder, std::string _pathFile)
{

	for (const auto& entry : std::filesystem::directory_iterator(_pathFolder))
	{
		std::string pathfiletoLoad = entry.path().string();
		std::ifstream myFile(pathfiletoLoad);
		if (myFile)
		{
			Wave* waveTemp = new Wave();
			std::string line;
			myFile >> line;
			waveTemp->time = std::stof(line);
			do
			{
				myFile >> line;
				std::string path = _pathFile;
				path += line;
				waveTemp->pathEnemyToLoad.push_back(path);


			} while (!myFile.eof());
			sWaves.push_back(waveTemp);
		}
	}

}

void Level::LoadEnemy(std::string _pathFolder)
{
}

void Level::LoadNewWave(std::list<Entity*>* _entityList)
{
	srand(time(0));
	std::list<Wave*>::iterator it = sWaves.begin();
	currentWave = rand() % sWaves.size();
	std::advance(it, currentWave);
	if (it != sWaves.end())
	{
		timeWave = (*it)->time;
	}
	else
	{
		assert(false);
	}
	for (const auto path : (*it)->pathEnemyToLoad)
	{
		Entity* entity = new Entity();
		entity->Load(entity, path);
		entity->GetTransform()->SetPosition((rand() % 1000) + 1000, entity->GetTransform()->GetPosition()->y);
		_entityList->push_back(entity);
	}
}

