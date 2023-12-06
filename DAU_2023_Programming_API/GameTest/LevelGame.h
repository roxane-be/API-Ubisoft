#pragma once
#include "Level.h"
class LevelGame : public Level
{
public:
	LevelGame(GameManager* gameManager = nullptr) : Level(gameManager) {};

	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	protected :
	
};

