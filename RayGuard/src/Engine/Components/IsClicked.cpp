#include "IsClicked.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
IsClicked::IsClicked(Actor* owner) : Component::Component(owner)
{
	m_isClicked = false;
	m_placed = false;
}

IsClicked::~IsClicked()
{
}

void IsClicked::Start()
{
}

void IsClicked::Update(double deltaTime)
{

		if (CheckMousePosition(GetMousePosition()))
		{
			m_inPosition = true;
			DrawCircleLines(_owner->Transform->GlobalPosition().x, _owner->Transform->GlobalPosition().y, 10, BLACK);
		}
		else
		m_inPosition = false;
		if (m_inPosition && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			m_isClicked = true;
		}
		if (m_isClicked && !m_placed)
		{
			m_placed = true;
		}
	
}

void IsClicked::OnDisable()
{

}

bool IsClicked::CheckMousePosition(Vector2 position)
{
	if (position.x > _owner->Transform->GlobalPosition().x - (_owner->GetScale() / 2) && position.x < _owner->Transform->GlobalPosition().x + (_owner->GetScale() / 2))
		if (position.y > _owner->Transform->GlobalPosition().y - (_owner->GetScale() / 2) && position.y < _owner->Transform->GlobalPosition().y + (_owner->GetScale() / 2))
			return true;

	return false;
}
