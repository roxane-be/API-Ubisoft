#include "stdafx.h"
#include "GameManager.h"
#include "Entity.h"
#include "Level.h"
#include "LevelGame.h"
#include "LevelMenu.h"
#include "MapManager.h"

GameManager::GameManager()
{
	m_levels.push_back(new LevelMenu(this)); // menu
	m_levels.push_back(new LevelGame(this)); // game
	m_levels.push_back(new Level(this)); // shop
}

void GameManager::Init()
{
	m_levels[currentLevel]->Init();
	m_levels[currentLevel]->GetAllEntityLevel(&m_ActiveEntityList);
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
	for (const auto element : (m_ActiveEntityList))
	{
		element->Update(deltaTime);
	}
}

void GameManager::Render()
{
	for (const auto element : (m_ActiveEntityList))
	{
		element->Render();
	}
}

void GameManager::Shutdown()
{
	for (auto entity : m_ActiveEntityList)
	{
		if (entity != nullptr)
		{
			delete entity;
			entity = nullptr;
		}
	}
	m_ActiveEntityList.clear();

	m_levels[oldLevel]->Shutdown();

}

void GameManager::SetLevel(eCurrentLevel newLevel)
{
	oldLevel = currentLevel;
	currentLevel = newLevel;
}
