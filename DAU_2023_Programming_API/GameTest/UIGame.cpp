#include "stdafx.h"
#include "UIGame.h"
#include "Button.h"
#include "GameManager.h"
#include <functional>
#include "App/app.h"

UIGame::UIGame()
{
	//buttonPlay = new Button;
	//buttonShop = new Button;
	//buttonQuit = new Button;
}

void UIGame::Init()
{
	//buttonPlay->Init();
	//buttonPlay->SetText("Play");
	//buttonPlay->SetTextPosition(Vector2f(-15, -5));
	//buttonPlay->SetPosition(Vector2f(200, 600));
	//
	//buttonShop->Init();
	//buttonShop->SetText("Shop");
	//buttonShop->SetTextPosition(Vector2f(-15, -5));
	//buttonShop->SetPosition(Vector2f(200, 400));
	//
	//buttonQuit->Init();
	//buttonQuit->SetText("Quit");
	//buttonQuit->SetTextPosition(Vector2f(-15, -5));
	//buttonQuit->SetPosition(Vector2f(200, 200));
	////bind function OnClick
	//buttonPlay->ptrF = std::bind(&UIGame::PlayGame, this);
	//buttonShop->ptrF = std::bind(&UIGame::ShopWindow, this);
	//buttonQuit->ptrF = std::bind(&UIGame::QuitGame, this);
}

void UIGame::Update(float deltaTime)
{
	//if (App::IsKeyPressed(VK_LBUTTON))
	//{
	//	if (buttonPlay->IsHovered())
	//		buttonPlay->OnClick();
	//	else if (buttonShop->IsHovered())
	//		buttonShop->OnClick();
	//	else if (buttonQuit->IsHovered())
	//		buttonQuit->OnClick();
	//}
}

void UIGame::Render()
{
	//buttonPlay->Render();
	//buttonShop->Render();
	//buttonQuit->Render();
}

void UIGame::PlayGame()
{
	//GameData::Instance.gameStatue = Game;

}

void UIGame::ShopWindow()
{
}

void UIGame::QuitGame()
{
	exit(0);
}

