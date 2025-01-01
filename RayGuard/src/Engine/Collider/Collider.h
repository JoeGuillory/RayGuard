#pragma once
class Actor;
class CircleCollider;
class BoxCollider;
class Collider
{
public:

	Collider(Actor* owner);
	~Collider();

	bool CheckCollision(Actor* other);
	virtual bool CheckCollisionCircle(CircleCollider* collider);
	virtual bool CheckCollisionBox(BoxCollider* collider);
	virtual void Draw();

	Actor* Owner;
};