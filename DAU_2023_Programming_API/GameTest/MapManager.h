#pragma once
#include <vector>


class MapManager
{
public:
	MapManager();

	void Init();
	void Update(float deltaTime);
	void Render();


private:
	std::vector<CSimpleSprite> spritesMap;
	std::vector<CSimpleSprite> currentMapShow;

	Vector2f position;
	float sideScroll =-2;
};

