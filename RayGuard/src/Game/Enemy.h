#pragma once
#include "Engine\Actor.h"
class Enemy : public Actor
{
public:
	Enemy();
	~Enemy();
	void Start();
	void Update(double deltatime);
	float health;
	void OnCollision(Actor* other);
	void End();
};