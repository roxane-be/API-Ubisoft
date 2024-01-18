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
	static VisualSprite::eAnimationSprite ConvertStringToEnumAnimationSprite(std::string str);
};

