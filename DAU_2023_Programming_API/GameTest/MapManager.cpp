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
	if (m_gameManager->currentLevel == eCurrentLevel::GAME)
		InitBackgroundSpriteMap();
}

void MapManager::Update(float deltaTime)
{
	if (!backgroundList.empty())
		UpdateBackgroundSpriteMap(deltaTime);
}




void MapManager::Render()
{
	if (m_gameManager->GetActiveEntitiesList())
	{
		m_gameManager->GetActiveEntitiesList()->sort(MapManager::CompareLayer);
		for (const auto& element : *m_gameManager->GetActiveEntitiesList())
			if (element != nullptr)
				element->Render();
	}

	if (GameManager::Instance.currentLevel == GAME)
	{
		 std::string enemiesKills = std::to_string( GameManager::Instance.GetEnemiesKill());
		char* charFile = new char[enemiesKills.length() + 1];
		std::strcpy(charFile, enemiesKills.c_str());
		App::Print(APP_VIRTUAL_WIDTH/2, 700, charFile, 1, 0, 0);
	}

}

void MapManager::Shutdown()
{
	backgroundList.clear();
}



void MapManager::InitBackgroundSpriteMap()
{
	const std::string pathFile = ".\\TestData\\Map";
	int nbElemenet = 0;

	for (const auto& entry : std::filesystem::directory_iterator(pathFile))
	{
		if (entry.is_regular_file() && VisualSprite::m_stringFile.find(entry.path().string()) == VisualSprite::m_stringFile.end())
		{
			std::string machin = entry.path().string();
			char* charFile = new char[machin.length() + 1];
			std::strcpy(charFile, machin.c_str());
			VisualSprite::m_stringFile[machin] = charFile;

		}
			nbElemenet++;
	}
	backgroundList.resize(nbElemenet);

	for (int i = 0; i < nbElemenet; i++)
	{
		std::string stringFile = ".\\TestData\\Map\\Map";
		stringFile += std::to_string(i);
		stringFile += ".png";
		stringFile += "\0";

		Entity* backgroundMap = new Entity("BackGroundMap" + i);
		BlackBoard* blackBoard = new BlackBoard(backgroundMap);
		VisualSprite* componentVisualSpriteBackground = new VisualSprite(backgroundMap);
		componentVisualSpriteBackground->CreateSprite(VisualSprite::m_stringFile[stringFile], 1, 1, 0.8f, -1);
		backgroundMap->AddComponent(componentVisualSpriteBackground);
		blackBoard->sizeSprite = componentVisualSpriteBackground->GetSize();
		blackBoard->scaleSprite = componentVisualSpriteBackground->GetScale();
		blackBoard->SetLayerVisualSprite(-1);
		backgroundMap->blackBoard = blackBoard;

		backgroundMap->GetTransform()->SetPosition({ -500,-500 });
		backgroundList[i] = backgroundMap;
		m_gameManager->GetActiveEntitiesList()->push_back(backgroundList[i]);
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
