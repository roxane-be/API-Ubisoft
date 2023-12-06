#include "stdafx.h"
#include "MapManager.h"
#include "App/app.h"
#include "App/SimpleSprite.h"
#include <string>
#include <ctime>  
#include <filesystem>
#include "GameManager.h"
#include "Entity.h"
#include "VisualSprite.h"

void MapManager::Init()
{
	if (m_gameManager->currentLevel == eCurrentLevel::Game)
		InitBackgroundSpriteMap();

}

void MapManager::Update(float deltaTime)
{
	UpdateBackgroundSpriteMap(deltaTime);

}




void MapManager::Render()
{
	if (activeEntitiesSpriteList)
	{
		activeEntitiesSpriteList->sort(MapManager::CompareLayer);
		for (const auto& element : *activeEntitiesSpriteList)
			if (element != nullptr)
				element->Render();

	}
}

void MapManager::Shutdown()
{

	for (auto it = (*activeEntitiesSpriteList).begin(); it !=(*activeEntitiesSpriteList).end();)
	{
		delete* it;
		it = activeEntitiesSpriteList->erase(it);
	}
}



void MapManager::InitBackgroundSpriteMap()
{
	const std::string pathFile = ".\\TestData\\Map";
	int nbElemenet = 0;

	for (const auto& entry : std::filesystem::directory_iterator(pathFile))
		nbElemenet++;
	backgroundList.resize(nbElemenet);

	for (int i = 0; i < nbElemenet; i++)
	{
		std::string stringFile = ".\\TestData\\Map\\Map";
		stringFile += std::to_string(i);
		stringFile += ".png";
		stringFile += "\0";
		char* charFile = new char[stringFile.length() + 1];
		std::strcpy(charFile, stringFile.c_str());

		Entity* backgroundMap = new Entity("BackGroundMap" + i);
		BlackBoard* blackBoard = new BlackBoard(backgroundMap);
		VisualSprite* componentVisualSpriteBackground = new VisualSprite(backgroundMap, blackBoard);
		componentVisualSpriteBackground->CreateSprite(charFile, 1, 1, 0.8f, 0);
		backgroundMap->AddComponent(componentVisualSpriteBackground);
		blackBoard->sizeSprite = componentVisualSpriteBackground->GetSize();
		blackBoard->scaleSprite = componentVisualSpriteBackground->GetScale();
		backgroundMap->blackBoard = blackBoard;

		backgroundMap->GetTransform()->SetPosition({ -500,-500 });
		backgroundList[i] = backgroundMap;

		activeEntitiesSpriteList->push_back(backgroundList[i]);
		//(*activeEntitiesSpriteList).push_back(backgroundList[i]);
		//m_gameManager->GetActiveEntity()->push_back(backgroundList[i]);
	}
	srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		do
		{
			currentMapShow[i] = rand() % backgroundList.size();
		} while (currentMapShow[i] == currentMapShow[i - 1]);

	}
	backgroundList[currentMapShow[0]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.y / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite);
	backgroundList[currentMapShow[1]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x + backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->y);
}

void MapManager::UpdateBackgroundSpriteMap(float deltaTime)
{
	backgroundList[currentMapShow[0]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x + SpeedSideScroll, backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->y);
	backgroundList[currentMapShow[1]]->GetTransform()->SetPosition(backgroundList[currentMapShow[1]]->GetTransform()->GetPosition()->x + SpeedSideScroll, backgroundList[currentMapShow[1]]->GetTransform()->GetPosition()->y);

	if (backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x <= -backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite / 2)
	{
		backgroundList[currentMapShow[0]]->GetTransform()->SetPosition({ -500,-500 });

		currentMapShow[0] = currentMapShow[1];
		while (currentMapShow[0] == currentMapShow[1])
		{
			currentMapShow[1] = rand() % backgroundList.size();
		}
		backgroundList[currentMapShow[0]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.y / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite);
		backgroundList[currentMapShow[1]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x + backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->y);
	}
}
