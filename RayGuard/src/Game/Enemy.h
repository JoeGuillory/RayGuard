#pragma once
#include "Engine\Actor.h"
class Enemy : public Actor
{
public:
	Enemy(const char* name);
	~Enemy();
	void Start();
	void Update(double deltatime);
	void End();
};