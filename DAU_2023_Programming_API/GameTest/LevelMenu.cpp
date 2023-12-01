#include "stdafx.h"
#include "LevelMenu.h"

void LevelMenu::Init()
{
	CreateButton("ButtonPlay", "Play", Vector2f(200, 600), std::bind(&LevelMenu::Play, this));
	CreateButton("ButtonShop", "Shop", Vector2f(200, 400), []() {});
	CreateButton("ButtonQuit", "Quit", Vector2f(200, 200), []() {exit(0); });
}

void LevelMenu::Update(float deltaTime)
{
	
}

void LevelMenu::Render()
{
	for (const auto& element : m_ButtonEntities)
	{
		element->Render();
	}
}


void LevelMenu::CreateButton(const char* nameEntity, const char* textButton, Vector2f positionButton, std::function<void()> ptrF)
{

	Entity* button = new Entity(nameEntity);
	button->GetTransform()->SetPosition(positionButton);
	VisualSprite* componentVisualButtonPlay = new VisualSprite(button);
	componentVisualButtonPlay->CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
	button->AddComponent(componentVisualButtonPlay);
	Button* componentButtonPlay = new Button(button);
	componentButtonPlay->Init();
	componentButtonPlay->SetText(textButton);
	componentButtonPlay->SetOffsetTextPosition(Vector2f(-15, -5));
	componentButtonPlay->ptrF = ptrF;
	button->AddComponent(componentButtonPlay);
	m_ButtonEntities.push_back(button);
}

void LevelMenu::Play()
{
	m_gameManager->currentLevel = Game;
	Init();
}