#pragma once
#include "Collider.h"
#include "Vector2.h"
class CircleCollider : public Collider
{
public:
	CircleCollider(Actor* owner, float radius);
	~CircleCollider();

	bool CheckCollisionCircle(CircleCollider* collider);
	void Draw();
	void SetOffset(MathLibrary::Vector2 offset);
	void EnableDraw(bool draw);
	float CollisionRadius;
	
private:
	MathLibrary::Vector2 m_offset;
	bool m_enableDraw;
	
};

