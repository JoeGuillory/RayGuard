#pragma once
#include "Engine/Actor.h"
class Sprite;
class Shoot;

class Tower : public Actor
{
public:
	Tower();
	~Tower();

	void Start();
	void Update(double deltaTime);
	void End();
	void OnCollision(Actor* other);
private:
	Sprite* m_sprite;
	Shoot* m_shoot;
};

