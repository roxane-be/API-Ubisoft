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
	playerIsDead = false;


	std::string pathFile;
	switch (GameManager::Instance.currentLevel)
	{
	case GAME:
		pathFile = ".\\TestData\\LoadEntities\\LevelGame";

		break;
	case MAINMENU:
		pathFile = ".\\TestData\\LoadEntities\\LevelMenu";

		break;
	default:
		break;
	}
	srand(time(0));


	LoadEntities(pathFile);
	if (GameManager::Instance.currentLevel == GAME)
		LoadNewWave(m_gameManager->GetActiveEntitiesList());

}

void Level::Update(float deltaTime)
{
	if (GameManager::Instance.currentLevel == GAME)
	{
		if (GameManager::Instance.mainCharacter != nullptr)
		{
			timeWave -= deltaTime;
			if (timeWave < 0)
			{
				LoadNewWave(m_gameManager->GetActiveEntitiesList());
			}
		}
		else if(!playerIsDead)
		{
			LoadEntities(".\\TestData\\LoadEntities\\EndGame");
			playerIsDead =true;
		}
	}

}

void Level::Render()
{

}

void Level::Shutdown()
{
}

void Level::GetAllEntitiesLevel(std::list<Entity*>* _list)
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

void Level::LoadEnemies(std::string _pathFolder)
{

	for (const auto& entry : std::filesystem::directory_iterator(_pathFolder))
	{
		if (entry.is_regular_file())
		{
			std::string pathfiletoLoad = entry.path().string();
			std::filesystem::path fileExt = entry.path().extension();
			if (fileExt == std::filesystem::path(".txt"))
			{
				std::ifstream myFile(pathfiletoLoad);
				if (myFile)
				{

					Entity* entityEnemy = new Entity();
					entityEnemy->Load(entityEnemy, pathfiletoLoad);

					m_EnemyEntitiesMap[pathfiletoLoad] = entityEnemy;
				}
			}
		}
	}
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


	for (const auto element : (*it)->pathEnemyToLoad)
	{

		Entity* baseEntity = m_EnemyEntitiesMap[element];
		Entity* entity = new Entity(*baseEntity);  // copy
		entity->GetTransform()->SetPosition((rand() % 1000) + 1000, entity->GetTransform()->GetPosition()->y);
		_entityList->push_back(entity);

	}
}

void Level::LoadEntities(std::string _pathFile)
{
	for (const auto& entry : std::filesystem::directory_iterator(_pathFile))
	{
		//check only file txt 
		if (entry.is_regular_file())
		{
			std::string pathLoad = entry.path().string();

			Entity* entity = new Entity();
			entity->Load(entity, pathLoad);
			m_gameManager->GetActiveEntitiesList()->push_back(entity);
			if (entry.path().string().find("MainCharacter") != std::string::npos)
			{
				GameManager::Instance.mainCharacter = entity;
			}

		}
		//check if a folder is a Load Wave
		if (entry.path().string().find("LoadWave") != std::string::npos)
		{
			LoadWaves(entry.path().string(), _pathFile);
		}
		if (entry.path().string().find("LoadEnemies") != std::string::npos)
		{
			LoadEnemies(entry.path().string());
		}
	}
}

