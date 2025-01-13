#pragma once
#include "Engine\Actor.h"
class Base : public Actor
{
public:
	Base();
	~Base();
	void Start();
	void Update(double deltatime);
	
	void OnCollision(Actor* other);
	void End();
};