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
	App::Print(m_offsetPositionText.x + m_entity->GetTransform()->GetPosition()->x, m_offsetPositionText.y + m_entity->GetTransform()->GetPosition()->y, m_text.c_str());
}

void Button::OnClick()
{
	ptrF();
}

void Button::SetText(std::string _text)
{
	m_text = _text;
}

void Button::SetOffsetTextPosition(Vector2f _position)
{
	m_offsetPositionText = _position;
}

bool Button::IsHovered()
{
	Vector2f posMouse(0, 0);
	Vector2f size = m_entity->blackBoard->sizeSprite / 2;
	size += 10;

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

	Button* button = new Button(resultEntity);

	return button;
}