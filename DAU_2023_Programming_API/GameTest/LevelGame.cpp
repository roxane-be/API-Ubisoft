#include "stdafx.h"
#include "LevelGame.h"

void LevelGame::Init()
{
	//init Entity MainCharac 
	{
		mainCharacter = new Entity("MainCharacter");
		BlackBoard* blackBoard = new BlackBoard(mainCharacter);
		VisualSprite* componentVisuelMainCharac = new VisualSprite(mainCharacter, blackBoard);
		componentVisuelMainCharac->CreateSprite(".\\TestData\\Player\\spritesheet.png", 8, 1, 1.0f, 1,".\\TestData\\Player\\spritesheet.txt");
		componentVisuelMainCharac->SetAnimation(eAnimationSprite::ANIM_WALK);
		blackBoard->SetLayerVisualSprite(componentVisuelMainCharac->GetLayer());
		mainCharacter->GetTransform()->SetPosition(Vector2f(150, 300));
		mainCharacter->AddComponent(componentVisuelMainCharac);

	}
}

void LevelGame::Update(float deltaTime)
{
}

void LevelGame::Render()
{
mainCharacter->Render();
}
