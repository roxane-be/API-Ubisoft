#pragma once
#include "Transform.h"
#include "VisualSprite.h"
#include <list>
#include "Entity.h"
#include "BlackBoard.h"


#define SpeedSideScroll -8.f

class Level;
class GameManager;

class MapManager
{
public:
	MapManager(GameManager* gameManager) { m_gameManager = gameManager; };

	void Init();
	void Update(float deltaTime);
	void Render();


	//pour faire spawn les entités dispo dans le level
	Level* currentLevel; // point vers le current level

	std::list<Entity*>* activeEntitiesSpriteList;

	static bool CompareLayer(const Entity* entity1, const Entity* entity2)
	{
		if (entity1->blackBoard && entity2->blackBoard)
		{
			return  entity1->blackBoard->GetLayervisualSprite()
				< entity2->blackBoard->GetLayervisualSprite();
		}
		return false;
	};

protected:
	void InitBackgroundSpriteMap();
	void UpdateBackgroundSpriteMap(float deltaTime);



private:
	std::vector<Entity*> backgroundList;
	int currentMapShow[2]{ 0,0 };
	// pour afficher les sprites avec un layer
	GameManager* m_gameManager;
};

