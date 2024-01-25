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
	m_timeWave = 0;
	m_currentWave = 0;
	m_playerIsDead = false;

	std::string pathFile;
	switch (GameManager::Instance.GetStatusGame())
	{
	case GameManager::eStatusGame::INGAME:
		pathFile = ".\\TestData\\LoadEntities\\LevelGame";

		break;
	case GameManager::eStatusGame::MAINMENU:
		pathFile = ".\\TestData\\LoadEntities\\LevelMenu";

		break;
	default:
		break;
	}
	srand((unsigned int)time(0));

	LoadEntities(pathFile);
	if (GameManager::Instance.GetStatusGame() == GameManager::eStatusGame::INGAME)
		LoadNewWave(GameManager::Instance.GetActiveEntitiesList());
}

void Level::Update(float deltaTime)
{
	if (GameManager::Instance.GetStatusGame() == GameManager::eStatusGame::INGAME)
	{
		if (GameManager::Instance.mainCharacter != nullptr)
		{
			m_timeWave -= deltaTime;
			if (m_timeWave < 0)
			{
				LoadNewWave(GameManager::Instance.GetActiveEntitiesList());
			}
		}
		else if(!m_playerIsDead)
		{
			LoadEntities(".\\TestData\\LoadEntities\\EndGame");
			m_playerIsDead =true;
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
			m_sWaves.push_back(waveTemp);
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
	srand((unsigned int)time(0));
	std::list<Wave*>::iterator it = m_sWaves.begin();
	m_currentWave = rand() % m_sWaves.size();
	std::advance(it, m_currentWave);
	if (it != m_sWaves.end())
	{
		m_timeWave = (*it)->time;
	}
	else
	{
		assert(false);
	}
	//copy enemy to create new entity
	for (const auto element : (*it)->pathEnemyToLoad)
	{
		Entity* baseEntity = m_EnemyEntitiesMap[element];
		Entity* entity = new Entity(*baseEntity);  // copy
		entity->GetTransform()->SetPosition((float)((rand() % 1000) + 1000), entity->GetTransform()->GetPosition()->y);
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
			GameManager::Instance.GetActiveEntitiesList()->push_back(entity);
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

