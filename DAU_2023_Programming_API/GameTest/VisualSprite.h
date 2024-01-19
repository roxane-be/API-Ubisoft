#pragma once
#include "Component.h"


class CSimpleSprite;
class BlackBoard;

class VisualSprite : public Component
{
public:

	enum eAnimationSprite
	{
		ANIM_WALK,
		ANIM_ATTACK,
		ANIM_DEATH,
		TPOSE,
	};


	VisualSprite(Entity* parent = nullptr) : Component(parent) {};
	
	~VisualSprite()
	{
		delete sprite;
	}

	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual Component* Clone(Entity* resultEntity) override;


	void CreateSprite(const char* fileName, int columns, int rows, float scale = 1.0f, int layer = 0,
		std::string = "None");
	void SetScaleSprite(float scale);
	void SetAnimation(eAnimationSprite id);



	Vector2f GetSize();
	float GetScale();
	bool IsNull();

	Vector2f* GetOffsetSpritePosition() { return &m_offsetSpritePosition; };

	void SetLayer(int _layer) { m_layer = _layer; };
	int GetLayer() { return m_layer; };

	static void DestroyMap()
	{
		std::map<std::string, const char*>::iterator it;
		for (it = VisualSprite::m_stringFile.begin(); it != VisualSprite::m_stringFile.end(); it++)
		{
			delete it->second;
		}
	}


	static std::map< std::string, const char* > m_stringFile;

private:
	void CreateAnimations(std::string fileNameAnimation);

	const char* m_fileName{ nullptr };
	CSimpleSprite* sprite{ nullptr };
	Vector2f m_offsetSpritePosition = Vector2f();
	//le Z, fond
	int m_layer = 0;
	eAnimationSprite currentAnimation = TPOSE;
};


