#pragma once
#include "Engine\Actor.h"
class Enemy : Actor
{
public:
	Enemy(const char* name);
	~Enemy();
	void Start();
	void Update(double deltatime);
	void End();
};