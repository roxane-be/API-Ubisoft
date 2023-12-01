#pragma once
#include "Transform.h"
#include "VisualSprite.h"
#include <list>


#define SpeedSideScroll -5.f

class Level;
class GameManager;

class MapManager
{
public:
	MapManager(GameManager* gameManager) {m_gameManager = gameManager;};

	void Init();
	void Update(float deltaTime);
	void Render();

	Level* currentLevel; // point vers le current level




protected:
	void InitBackgroundSpriteMap();
	void UpdateBackgroundSpriteMap(float deltaTime);
	void RenderBackgroundSpriteMap();
private:
	std::vector<VisualSprite> backgroundSpritesMap;
	int currentBackgroundShow[2]{ 0,0 };
	// pour afficher les sprites avec un layer
	std::list<VisualSprite> activeEntitiesSpriteList;
	GameManager* m_gameManager;
};

