#pragma once

#include "MainCharacter.h"
#include "UIGame.h"
#include "MapManager.h"



enum GameStatue
{
	Menu,
	Game,
	Shop,
};


class GameData
{
public:
	MainCharacter* mainCharacter;
	UIGame* mainMenu;
	MapManager* mapManager;
	GameStatue gameStatue = Menu;



	static GameData Instance;
};

