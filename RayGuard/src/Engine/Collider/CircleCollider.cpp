#include "CircleCollider.h"
#include "Vector2.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "raylib.h"
CircleCollider::CircleCollider(Actor* owner, float radius) : Collider::Collider(owner)
{
	CollisionRadius = radius;
	m_offset = { 0,0 };
	m_enableDraw = false;

}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::CheckCollisionCircle(CircleCollider* collider)
{
	float sumRadi = collider->CollisionRadius + CollisionRadius;
	//Other collider
	MathLibrary::Vector2 left = { collider->Owner->Transform->GlobalPosition() };
	//This collider
	MathLibrary::Vector2 right = { Owner->Transform->GlobalPosition() + m_offset };
	float distance = left.getMagnitude() - right.getMagnitude();
	return sumRadi >= distance;
}
void CircleCollider::Draw()
{
	if (m_enableDraw)
	{
		DrawCircleLines(Owner->Transform->GlobalPosition().x, Owner->Transform->GlobalPosition().y, CollisionRadius, BLACK);
	}
}

void CircleCollider::SetOffset(MathLibrary::Vector2 offset)
{
	m_offset = offset;
}

void CircleCollider::EnableDraw(bool draw)
{
	m_enableDraw = draw;
}
