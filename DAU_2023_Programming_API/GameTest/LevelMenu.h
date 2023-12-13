#pragma once

class LevelMenu : public Level
{
public:

	LevelMenu(GameManager* gameManager = nullptr) : Level(gameManager){};

	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

};

