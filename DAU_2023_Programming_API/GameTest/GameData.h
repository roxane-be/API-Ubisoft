#pragma once

//#include "MainCharacter.h"
//#include "UIGame.h"
//#include "MapManager.h"
#include <vector>



enum eCurrentLevel
{
	MainMenu,
	Game,
	Shop,
};


class GameData
{
public:
	//MainCharacter* mainCharacter;

	//Entity* m_mainCharacter;
	//
	//
	//
	//UIGame* mainMenu;
	//MapManager* mapManager;
	eCurrentLevel currentLevel = MainMenu;



	static GameData Instance;

private:
	//std::vector<Entity*> m_GlobalEntities;

	std::vector<std::vector<Entity>> m_LevelsEntities;
};

