#include "stdafx.h"
#include "FunctionLibrary.h"
#include <cassert>


Collision::eCollisionObjectResponses FunctionLibrary::ConvertStringToEnumCollisionObjectResponses(std::string str)
{
	// Collision object responses
	if (str == "NONE")
		return  Collision::eCollisionObjectResponses::NONE;
	else if (str == "MAINCHARACTER")
		return Collision::eCollisionObjectResponses::MAINCHARACTER;
	else if (str == "ENEMYGROUND")
		return Collision::eCollisionObjectResponses::ENEMYGROUND;
	else if (str == "WEAPONS")
		return Collision::eCollisionObjectResponses::WEAPONS;

	assert(false);
}

Collision::eCollisionResponses FunctionLibrary::ConvertStringToEnumCollisionResponses(std::string str)
{
	// Collision responses
	if (str == "IGNORE")
		return Collision::eCollisionResponses::IGNORECOLLISION;
	else if (str == "OVERLAP")
		return Collision::eCollisionResponses::OVERLAP;
	else if (str == "BLOCK")
		return Collision::eCollisionResponses::BLOCK;

	assert(false);

}



