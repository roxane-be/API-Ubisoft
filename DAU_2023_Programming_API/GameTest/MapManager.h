#pragma once
#include <vector>
#include "Transform.h"
#include "VisualSprite.h"


class MapManager
{
public:
	MapManager();

	void Init();
	void Update(float deltaTime);
	void Render();


private:
	//std::vector<CSimpleSprite> spritesMap;
	//std::vector<CSimpleSprite> currentMapShow;
	std::vector<VisualSprite> spritesMap;
	std::vector<VisualSprite> currentMapShow;
	Transform transform;
	float sideScroll =-5;
};

