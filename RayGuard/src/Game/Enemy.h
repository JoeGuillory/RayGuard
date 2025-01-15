#pragma once
#include "Engine\Actor.h"
class Enemy : public Actor
{
public:
	Enemy();
	~Enemy();
	void Start();
	void Update(double deltatime);
	void OnCollision(Actor* other);
	void End();
private:
	float m_enemyHealth ;
};