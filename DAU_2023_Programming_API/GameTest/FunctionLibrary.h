#pragma once
class FunctionLibrary
{
public:

	static Collision::eCollisionObjectResponses ConvertStringToEnumCollisionObjectResponses(std::string str);
	static Collision::eCollisionResponses ConvertStringToEnumCollisionResponses(std::string str);
	static AnimationSprite::eAnimationSprite ConvertStringToEnumAnimationSprite(std::string str);
	static bool ConvertStringToBoolean(std::string str);

	static bool RaycastObject2D(Vector2f _origin, Vector2f _object, float distance);
};

