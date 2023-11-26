#include "stdafx.h"
#include "GameData.h"
#include "Entity.h"

GameData::GameData()
{
	for (int i = 0; i < eCurrentLevel::numberLevel; i++)
	{
		m_LevelsEntities.push_back(std::vector<Entity*>());
	}
}

void GameData::Init()
{
	//init Entity for Main Menu
	{
		//entity Button Play
		{
			Entity* buttonPlay = new Entity("ButtonPlay");
			buttonPlay->GetTransform()->SetPosition(Vector2f(200, 600));
			VisualSprite* componentVisualButtonPlay = new VisualSprite(buttonPlay);
			componentVisualButtonPlay->CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
			buttonPlay->AddComponent(componentVisualButtonPlay);
			Button* componentButtonPlay = new Button(buttonPlay);
			componentButtonPlay->Init();
			componentButtonPlay->SetText("Play");
			componentButtonPlay->SetOffsetTextPosition(Vector2f(-15, -5));
			componentButtonPlay->ptrF = []() { GameData::Instance.currentLevel = Game; };
			buttonPlay->AddComponent(componentButtonPlay);
			m_LevelsEntities[MainMenu].push_back(buttonPlay);

		}
		//entity Button Shop
		{
			Entity* buttonShop = new Entity("ButtonShop");
			buttonShop->GetTransform()->SetPosition(Vector2f(200, 400));
			VisualSprite* componentVisualButtonShop = new VisualSprite(buttonShop);
			componentVisualButtonShop->CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
			buttonShop->AddComponent(componentVisualButtonShop);
			Button* componentButtonShop = new Button(buttonShop);
			componentButtonShop->Init();
			componentButtonShop->SetText("Shop");
			componentButtonShop->SetOffsetTextPosition(Vector2f(-15, -5));
			componentButtonShop->ptrF = []() {};
			buttonShop->AddComponent(componentButtonShop);
			m_LevelsEntities[MainMenu].push_back(buttonShop);
		}
		//entity Button Quit
		{
			Entity* buttonQuit = new Entity("ButtonQuit");
			buttonQuit->GetTransform()->SetPosition(Vector2f(200, 200));
			VisualSprite* componentVisualButtonQuit = new VisualSprite(buttonQuit);
			componentVisualButtonQuit->CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
			buttonQuit->AddComponent(componentVisualButtonQuit);
			Button* componentButtonQuit = new Button(buttonQuit);
			componentButtonQuit->Init();
			componentButtonQuit->SetText("Quit");
			componentButtonQuit->SetOffsetTextPosition(Vector2f(-15, -5));
			componentButtonQuit->ptrF = []() {exit(0); };
			buttonQuit->AddComponent(componentButtonQuit);
			m_LevelsEntities[MainMenu].push_back(buttonQuit);
		}

	}

		//init Entity MapManager 
	{
		Entity* mapManager = new Entity("MapManager");
		MapManager* componentMapManager = new MapManager(mapManager);
		componentMapManager->Init();
		mapManager->AddComponent(componentMapManager);
		m_LevelsEntities[Game].push_back(mapManager);
	}
	//init Entity MainCharac 
	{
		Entity* mainCharac = new Entity("MainCharacter");
		VisualSprite* componentVisuelMainCharac = new VisualSprite(mainCharac);
		componentVisuelMainCharac->CreateSprite(".\\TestData\\Player\\spritesheet.png", 8, 1, 1.0f, ".\\TestData\\Player\\spritesheet.txt");
		componentVisuelMainCharac->SetAnimation(eAnimationSprite::ANIM_WALK);
		mainCharac->GetTransform()->SetPosition(Vector2f(150, 300));
		mainCharac->AddComponent(componentVisuelMainCharac);
		m_LevelsEntities[Game].push_back(mainCharac);
		m_mainCharacter = mainCharac;
	}
}

void GameData::Update(float deltaTime)
{
	for (int i = 0; i < m_LevelsEntities[currentLevel].size(); i++)
	{
		m_LevelsEntities[currentLevel][i]->Update(deltaTime);
	}
}

void GameData::Render()
{
	for (int i = 0; i < m_LevelsEntities[currentLevel].size(); i++)
	{
		m_LevelsEntities[currentLevel][i]->Render();
	}
}
