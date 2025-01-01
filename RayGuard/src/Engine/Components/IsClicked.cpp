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
	if (m_isClicked)
	{
		DrawCircleLines(_owner->Transform->GlobalPosition().x, _owner->Transform->GlobalPosition().y, 10, BLACK);
	}

}
