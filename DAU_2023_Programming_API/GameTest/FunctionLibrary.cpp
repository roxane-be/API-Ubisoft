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
	return Collision::eCollisionObjectResponses::NONE;
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
	return Collision::eCollisionResponses::ERROR;
}

AnimationSprite::eAnimationSprite FunctionLibrary::ConvertStringToEnumAnimationSprite(std::string str)
{
	if (str == "ANIM_ATTACK")
		return AnimationSprite::eAnimationSprite::ANIM_ATTACK;
	else if (str == "ANIM_WALK")
		return AnimationSprite::eAnimationSprite::ANIM_WALK;
	else if (str == "ANIM_DEATH")
		return AnimationSprite::eAnimationSprite::ANIM_DEATH;

	assert(false);
	return AnimationSprite::eAnimationSprite::ERROR;
}

bool FunctionLibrary::ConvertStringToBoolean(std::string str)
{
	if (str == "false")
		return false;
	else if (str == "true")
		return true;

	assert(false);
	return false;
}

bool FunctionLibrary::RaycastObject2D(Vector2f _origin, Vector2f _object, float distance)
{
	Vector2f direction = _object - _origin;

	float distanceToObj = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	return distanceToObj <= distance;
}



