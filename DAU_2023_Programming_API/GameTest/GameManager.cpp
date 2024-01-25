#include "stdafx.h"
#include "GameManager.h"
#include "Entity.h"
#include "Level.h"
#include "MapManager.h"


std::map<std::string, std::function<void()>> GameManager::functionMap;

GameManager::GameManager()
{
	m_levels.push_back(new Level()); // menu
	m_levels.push_back(new Level()); // game

	functionMap["ButtonReturnMenu"] = []() {GameManager::Instance.SetLevel(eStatusGame::MAINMENU); };
	functionMap["ButtonPlay"] = []() {GameManager::Instance.SetLevel(eStatusGame::INGAME); };
	functionMap["ButtonQuit"] = []() {exit(0); };
}

void GameManager::Init()
{
	m_levels[m_statusGame]->Init();
	m_levels[m_statusGame]->GetAllEntitiesLevel(&m_ActiveEntitiesList);
	ptrMapManager->currentLevel = GetLevel();
	m_enemiesKilled = 0;
}

void GameManager::Update(float deltaTime)
{
	if (ptrMapManager->currentLevel != GetLevel())
	{
		ptrMapManager->Shutdown();
		Shutdown();
		ptrMapManager->currentLevel = GetLevel();
		Init();
		ptrMapManager->Init();
	}

	GetLevel()->Update(deltaTime);
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

void GameManager::SetLevel(eStatusGame newLevel)
{
	m_statusGame = newLevel;
}

