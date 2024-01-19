#pragma once
class FunctionLibrary
{
public:

	union UnionEnum {
		Collision::eCollisionObjectResponses CollisionObjectResponses;
		Collision::eCollisionResponses CollisionResponses;
		Collision::eCollisionOutside CollisionOutside;
	};

	static Collision::eCollisionObjectResponses ConvertStringToEnumCollisionObjectResponses(std::string str);
	static Collision::eCollisionResponses ConvertStringToEnumCollisionResponses(std::string str);
	static AnimationSprite::eAnimationSprite ConvertStringToEnumAnimationSprite(std::string str);

	static bool RaycastObject2D(Vector2f _origin, Vector2f _object, float distance);
};

