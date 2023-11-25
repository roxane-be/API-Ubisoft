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



	Entity* buttonMainMenu = new Entity("MainMenu");
	//
	Button* componentButtonPlay = new Button();
	componentButtonPlay->Init();
	componentButtonPlay->SetText("Play");
	componentButtonPlay->SetTextPosition(Vector2f(-15, -5));
	componentButtonPlay->SetPosition(Vector2f(200, 600));
	componentButtonPlay->ptrF = []() { GameData::Instance.currentLevel = Game; };
	//
	Button* componentButtonShop = new Button();
	componentButtonShop->Init();
	componentButtonShop->SetText("Shop");
	componentButtonShop->SetTextPosition(Vector2f(-15, -5));
	componentButtonShop->SetPosition(Vector2f(200, 400));
	componentButtonShop->ptrF = []() {};
	//
	Button* componentButtonQuit = new Button();
	componentButtonQuit->Init();
	componentButtonQuit->SetText("Quit");
	componentButtonQuit->SetTextPosition(Vector2f(-15, -5));
	componentButtonQuit->SetPosition(Vector2f(200, 200));
	componentButtonQuit->ptrF = []() {exit(0); };

	buttonMainMenu->AddComponent(componentButtonPlay);
	buttonMainMenu->AddComponent(componentButtonShop);
	buttonMainMenu->AddComponent(componentButtonQuit);

	m_LevelsEntities[currentLevel].push_back(buttonMainMenu);



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
