#pragma once
#include "Transform.h"
#include "VisualSprite.h"
#include "Component.h"

#define SpeedSideScroll -5.f

class MapManager : public Component
{
public:
	MapManager();
	MapManager(Entity* parent);

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();


private:
	//std::vector<CSimpleSprite> spritesMap;
	//std::vector<CSimpleSprite> currentMapShow;
	std::vector<VisualSprite> spritesMap;
	int currentMapShow[2] {0,0};
	//Transform transform;
	//float sideScroll =-5;
};

