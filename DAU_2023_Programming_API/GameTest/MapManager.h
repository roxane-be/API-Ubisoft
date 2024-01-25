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
	MapManager() { };

	void Init();
	void Update(float deltaTime);
	void Render();

	void Shutdown();


	//Ptr GameManager current level
	Level* currentLevel = nullptr; 

	//Sort layer from the smallest to the largest number
	static bool SortLayer(const Entity* entity1, const Entity* entity2)
	{
		if (entity1->blackBoard && entity2->blackBoard)
		{
			return  entity1->blackBoard->layerSprite
				< entity2->blackBoard->layerSprite;
		}
		return false;
	};

protected:

	void InitBackgroundSpriteMap();
	void UpdateBackgroundSpriteMap(float deltaTime);


private:

	/// <summary>
	/// background/map of game
	/// </summary>
	std::vector<Entity*> backgroundList;
	/// <summary>
	/// Only 2 map is showing, this array indicates which map is displayed
	/// </summary>
	int currentMapShow[2]{ 0,0 };
};

