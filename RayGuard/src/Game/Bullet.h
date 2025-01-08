#pragma once
#include "Engine/Actor.h"

class Bullet : public Actor
{
public:

	float bulletSize;
	float Speed;
	void Start();
	void Update(double deltaTime);
	void End();

};