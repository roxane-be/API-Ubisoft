#pragma once

#include "MainCharacter.h"
#include "UIGame.h"


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

	GameStatue gameStatue = Menu;



	static GameData Instance;
};

