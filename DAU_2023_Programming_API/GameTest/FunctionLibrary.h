#pragma once
class FunctionLibrary
{
public:
	
	/// <summary>
	/// Convert string in enum Collision Object Responses
	/// </summary>
	/// <param name="str">string to convert in enum</param>
	/// <returns>return NONE, MAINCHARACTER, ENEMYGROUND or WEAPONS, return NONE if string isn't correct</returns>
	static Collision::eCollisionObjectResponses ConvertStringToEnumCollisionObjectResponses(std::string str);
	/// <summary>
	/// Convert string in enum Collision Responses
	/// </summary>
	/// <param name="str">string to convert in enum</param>
	/// <returns> return BLOCK, OVERLAP or IGNORECOLLISION, return ERROR if string isn't correct</returns>
	static Collision::eCollisionResponses ConvertStringToEnumCollisionResponses(std::string str);
	/// <summary>
	/// Convert string in enum Animation sprite
	/// </summary>
	/// <param name="str">string to convert in enum </param>
	/// <returns>return ANIM_WALK, ANIM_ATTACK or ANIM_DEATH, return ERROR if string isn't correct</returns>
	static AnimationSprite::eAnimationSprite ConvertStringToEnumAnimationSprite(std::string str);
	/// <summary>
	/// convert string in boolean 
	/// </summary>
	/// <param name="str"> string to convert in boolean  </param>
	/// <returns>return TRUE or FALSE, return FALSE if string isn't correct</returns>
	static bool ConvertStringToBoolean(std::string str);




	/// <summary>
	/// Trace line between 2 vector and return true if the distance is less than the length tested
	/// </summary>
	static bool RaycastObject2D(Vector2f pointOrigin, Vector2f pointOther, float distance);
};

