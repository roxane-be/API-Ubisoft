#pragma once

#include "MainCharacter.h"


enum GameStatue
{
	Menu,
	Game,
	Shop,
};

struct GameData
{
	MainCharacter* mainCharacter;

	GameStatue gameStatue = Menu;
};

