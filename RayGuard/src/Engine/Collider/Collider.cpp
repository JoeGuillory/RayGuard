#include "Collider.h"
#include "Engine/Actor.h"
#include "CircleCollider.h"
Collider::Collider(Actor* owner)
{
	Owner = owner;
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Actor* other)
{
	if (other->m_Collider != nullptr && dynamic_cast<CircleCollider*>(other->m_Collider) != nullptr)
	{
		return CheckCollisionCircle(dynamic_cast<CircleCollider*>(other->m_Collider));
	}
	return false;
}

bool Collider::CheckCollisionCircle(CircleCollider* collider)
{
	return false;
}

bool Collider::CheckCollisionBox(BoxCollider* collider)
{
	return false;
}

void Collider::Draw()
{
}
