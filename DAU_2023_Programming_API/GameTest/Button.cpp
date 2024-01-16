#include "stdafx.h"
#include <assert.h>
#include "Button.h"
#include "App/app.h"


void Button::Init()
{
}

void Button::Update(float deltaTime)
{
	if (App::IsKeyPressed(VK_LBUTTON) && IsHovered())
		OnClick();
}

void Button::Render()
{
	App::Print(offsetPositionText.x + m_entity->GetTransform()->GetPosition()->x, offsetPositionText.y + m_entity->GetTransform()->GetPosition()->y, text.c_str());

	float r = 1.0f;
	float g = 0.0f;
	float b = 0.0f;
}


void Button::OnClick()
{
	ptrF();
}

void Button::SetText(std::string _text)
{
	text = _text;
}

void Button::SetOffsetTextPosition(Vector2f _position)
{
	offsetPositionText = _position;
}



bool Button::IsHovered()
{
	Vector2f posMouse(0, 0);
	App::GetMousePos(posMouse.x, posMouse.y);
	if (posMouse.x > m_entity->GetTransform()->GetPosition()->x - size.x
		&& posMouse.x < m_entity->GetTransform()->GetPosition()->x + size.x
		&& posMouse.y > m_entity->GetTransform()->GetPosition()->y - size.y
		&& posMouse.y < m_entity->GetTransform()->GetPosition()->y + size.y
		)
		return true;
	return false;
}

Component* Button::Clone(Entity* resultEntity)
{
	assert(false); // should not me used currently

	Button* button = new Button(resultEntity, resultEntity->blackBoard);

	return button;
}