#pragma once
#include "Behavior.h"

class BehaviorAI : public Behavior
{
	public : 
		BehaviorAI(Entity* parent = nullptr, BlackBoard* blackBoard = nullptr) : Behavior(parent, blackBoard) {};

		virtual void Init()override;
		virtual void Update(float deltaTime)override;
		virtual void Render()override;

		virtual Component* Clone(Entity* resultEntity) override;



};

