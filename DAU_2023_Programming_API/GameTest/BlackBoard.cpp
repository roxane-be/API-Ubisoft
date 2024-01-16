#include "stdafx.h"
#include "BlackBoard.h"

void BlackBoard::Init()
{
}

void BlackBoard::Update(float deltaTime)
{
}

void BlackBoard::Render()
{
}

Component* BlackBoard::Clone(Entity* resultEntity)
{
	BlackBoard* blackBoard = new BlackBoard(resultEntity);

	return blackBoard;
}