#include "IsClicked.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
IsClicked::IsClicked(Actor* owner) : Component::Component(owner)
{
	m_isClicked = false;
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
		DrawCircleLines(_owner->Transform->GlobalPosition().x, _owner->Transform->GlobalPosition().y, 10, BLACK);
	}
	
}

bool IsClicked::CheckMousePosition(Vector2 position)
{
	if (position.x > _owner->Transform->GlobalPosition().x - (_owner->GetScale() / 2.5) && position.x < _owner->Transform->GlobalPosition().x + (_owner->GetScale() / 2.5))
		if (position.y > _owner->Transform->GlobalPosition().y - (_owner->GetScale() / 2.5) && position.y < _owner->Transform->GlobalPosition().y + (_owner->GetScale() / 2.5))
			return true;

	return false;
}
