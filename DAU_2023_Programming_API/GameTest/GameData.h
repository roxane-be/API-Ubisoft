#pragma once

#include "MainCharacter.h"


enum GameStatue
{
	Menu,
	Game,
};

struct GameData
{
	MainCharacter* mainCharacter;

	GameStatue gameStatue = Menu;
};

