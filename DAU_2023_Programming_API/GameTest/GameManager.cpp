#include "stdafx.h"
#include "GameManager.h"
#include "Entity.h"
#include "Level.h"
#include "MapManager.h"


std::map<std::string, std::function<void()>> GameManager::functionMap;


GameManager::GameManager()
{
	m_levels.push_back(new Level(this)); // menu
	m_levels.push_back(new Level(this)); // game
	m_levels.push_back(new Level(this)); // shop

	functionMap["ButtonPlay"] = std::bind(&GameManager::PlayGame, this);
	functionMap["ButtonShop"] = []() {};
	functionMap["ButtonQuit"] = []() {exit(0); };
}

void GameManager::Init()
{
	m_levels[currentLevel]->Init();
	m_levels[currentLevel]->GetAllEntitiesLevel(&m_ActiveEntitiesList);
	ptrMapManager->currentLevel = GetCurrentLevel();
}

void GameManager::Update(float deltaTime)
{
	if (ptrMapManager->currentLevel != GetCurrentLevel())
	{
		ptrMapManager->Shutdown();
		Shutdown();
		ptrMapManager->currentLevel = GetCurrentLevel();
		Init();
		ptrMapManager->Init();
	}

	GetCurrentLevel()->Update(deltaTime);
	for (const auto element : (m_ActiveEntitiesList))
	{
		element->Update(deltaTime);
	}

	
	//delete entity
	for (auto entity : m_EntitiesToDelete)
	{
		if (entity != nullptr)
		{
			m_ActiveEntitiesList.remove(entity);
			delete entity;
			entity = nullptr;
		}
	}
	m_EntitiesToDelete.clear();

}

void GameManager::Render()
{
	for (const auto element : (m_ActiveEntitiesList))
	{
		element->Render();
	}


	

}

void GameManager::Shutdown()
{


	for (auto entity : m_ActiveEntitiesList)
	{
		if (entity != nullptr)
		{
			delete entity;
			entity = nullptr;
		}
	}
	m_ActiveEntitiesList.clear();
	m_EntitiesToDelete.clear();


}

void GameManager::SetLevel(eCurrentLevel newLevel)
{
	currentLevel = newLevel;
}

void GameManager::PlayGame()
{
	SetLevel(Game);
}
