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
	
}


void LevelMenu::CreateButton(const char* nameEntity, const char* textButton, Vector2f positionButton, std::function<void()> ptrF)
{

	Entity* button = new Entity(nameEntity);
	BlackBoard* blackBoard = new BlackBoard(button);
	button->blackBoard =blackBoard;
	button->GetTransform()->SetPosition(positionButton);
	VisualSprite* componentVisualButtonPlay = new VisualSprite(button, blackBoard);
	componentVisualButtonPlay->CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
	blackBoard->SetLayerVisualSprite(componentVisualButtonPlay->GetLayer());
	button->AddComponent(componentVisualButtonPlay);
	Button* componentButtonPlay = new Button(button,blackBoard);
	componentButtonPlay->Init();
	componentButtonPlay->SetText(textButton);
	componentButtonPlay->SetOffsetTextPosition(Vector2f(-15, -5));
	componentButtonPlay->ptrF = ptrF;
	button->AddComponent(componentButtonPlay);
	m_ButtonEntities.push_back(button);
}

void LevelMenu::Play()
{

	m_gameManager->SetLevel(Game);
	
}