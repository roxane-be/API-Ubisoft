//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------

GameManager gameManager;
MapManager mapManager(&gameManager);


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	gameManager.Init();
	mapManager.Init();
	mapManager.currentLevel = gameManager.GetCurrentLevel();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	if (mapManager.currentLevel != gameManager.GetCurrentLevel())
	{
		mapManager.Shutdown();
		gameManager.Shutdown();
		mapManager.currentLevel = gameManager.GetCurrentLevel();
		gameManager.Init();
		mapManager.Init();
	}
	if (gameManager.currentLevel == Game)
		mapManager.Update(deltaTime);
	gameManager.Update(deltaTime);


	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	//{
	//	App::PlaySound(".\\TestData\\Test.wav");
	//}

	if (App::IsKeyPressed(VK_RETURN) || App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		gameManager.currentLevel = MainMenu;
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{

	mapManager.Render();




	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	//static float a = 0.0f;
	//float r = 1.0f;
	//float g = 1.0f;
	//float b = 1.0f;
	//a += 0.1f;
	//for (int i = 0; i < 20; i++)
	//{
	//	float sx = 200 + sinf(a + i * 0.1f)*60.0f;
	//	float sy = 200 + cosf(a + i * 0.1f)*60.0f;
	//	float ex = 700 - sinf(a + i * 0.1f)*60.0f;
	//	float ey = 700 - cosf(a + i * 0.1f)*60.0f;
	//	g = (float)i / 20.0f;
	//	b = (float)i / 20.0f;
	//	App::DrawLine(sx, sy, ex, ey,r,g,b);
	//}

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{

VisualSprite::DestroyMap();
	//------------------------------------------------------------------------
	// Example Sprite Code....
	// 
	//------------------------------------------------------------------------

	//std::ofstream saveFile(".\\TestData\\Save.txt");
	//if (saveFile)
	//{
	//	saveFile << "pos player " << gd.mainCharacter->position.X << " et " << gd.mainCharacter->position.Y;
	//}
}