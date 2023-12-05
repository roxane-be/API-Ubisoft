#pragma once

//#include "MainCharacter.h"
//#include "UIGame.h"
//#include "MapManager.h"
#include <vector>
#include <list>

class Level;
class Entity;

enum eCurrentLevel
{
	MainMenu,
	Game,
	Shop,
	numberLevel
};


class GameManager
{
public:
	GameManager();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	//MainCharacter* mainCharacter;
	//static GameManager Instance;

	//
	//
	//
	//UIGame* mainMenu;
	//MapManager* mapManager;

	//deviens le Game Manager

	Level* GetCurrentLevel() { return m_levels[currentLevel]; };
	eCurrentLevel currentLevel = MainMenu;
	std::list<Entity*>* GetActiveEntity() { return &m_ActiveEntityList; };
	//	Entity* m_mainCharacter; //pas forcément besoin dans le jeu
private:


	std::list<Entity*> m_ActiveEntityList;

	std::vector<Level*> m_levels;
	//std::vector<Level> 
	//ou 
	// Level Game
	//Level Shop
	//Level Menu


};

