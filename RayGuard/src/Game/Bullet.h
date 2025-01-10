#pragma once
#include "Engine/Actor.h"

class Bullet : public Actor
{
public:
	Bullet();
	~Bullet();
	float bulletSize;
	
	void Start();
	void Update(double deltaTime);
	void End();

};