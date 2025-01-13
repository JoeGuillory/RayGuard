#pragma once
#include "Engine/Actor.h"

class Bullet : public Actor
{
public:
	Bullet();
	~Bullet();
	
	
	void Start();
	void Update(double deltaTime);
	void End();

};