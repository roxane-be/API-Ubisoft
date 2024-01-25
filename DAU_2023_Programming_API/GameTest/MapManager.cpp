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
	if (GameManager::Instance.GetStatusGame() == GameManager::eStatusGame::INGAME)
		InitBackgroundSpriteMap();
}

void MapManager::Update(float deltaTime)
{
	if (!backgroundList.empty())
		UpdateBackgroundSpriteMap(deltaTime);
}

void MapManager::Render()
{
	//render all entities of the game
	if (GameManager::Instance.GetActiveEntitiesList())
	{
		GameManager::Instance.GetActiveEntitiesList()->sort(MapManager::SortLayer);
		for (const auto& element : *GameManager::Instance.GetActiveEntitiesList())
			if (element != nullptr)
				element->Render();
	}
	//render text
	if (GameManager::Instance.GetStatusGame() == GameManager::eStatusGame::INGAME)
	{
		//render text counter EnemiesKilled
		std::string enemiesKillsString = "Enemy :";
		if (GameManager::Instance.GetEnemiesKilled() > 1)
			enemiesKillsString = "Enemies : ";
		enemiesKillsString += std::to_string(GameManager::Instance.GetEnemiesKilled());
		App::Print(APP_VIRTUAL_WIDTH / 2 - 20, 690, enemiesKillsString.c_str(), 1, 0, 0);

		//render text information for attack
		App::Print(380, 720, "Click the left mouse button to attack", 1, 0, 0);
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
			std::string pathSprite = entry.path().string();
			char* charFile = new char[pathSprite.length() + 1];
			std::strcpy(charFile, pathSprite.c_str());
			VisualSprite::m_stringFile[pathSprite] = charFile;

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
		blackBoard->layerSprite = -1;
		backgroundMap->blackBoard = blackBoard;

		backgroundMap->GetTransform()->SetPosition({ -500,-500 });
		backgroundList[i] = backgroundMap;
		GameManager::Instance.GetActiveEntitiesList()->push_back(backgroundList[i]);
	}
	srand((unsigned int)time(0));

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
	//side scroll to left 
	backgroundList[currentMapShow[0]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x + SpeedSideScroll, backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->y);
	backgroundList[currentMapShow[1]]->GetTransform()->SetPosition(backgroundList[currentMapShow[1]]->GetTransform()->GetPosition()->x + SpeedSideScroll, backgroundList[currentMapShow[1]]->GetTransform()->GetPosition()->y);

	if (backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x <= -backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite / 2)
	{
		//set the current outside screen
		backgroundList[currentMapShow[0]]->GetTransform()->SetPosition({ -500,-500 });

		//switch current map 
		currentMapShow[0] = currentMapShow[1];
		//have different map than the first 
		while (currentMapShow[0] == currentMapShow[1])
		{
			currentMapShow[1] = rand() % backgroundList.size();
		}
		//Reset position map
		backgroundList[currentMapShow[0]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.y / 2.f * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite);
		backgroundList[currentMapShow[1]]->GetTransform()->SetPosition(backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->x + backgroundList[currentMapShow[0]]->blackBoard->sizeSprite.x * backgroundList[currentMapShow[0]]->blackBoard->scaleSprite, backgroundList[currentMapShow[0]]->GetTransform()->GetPosition()->y);
	}
}
