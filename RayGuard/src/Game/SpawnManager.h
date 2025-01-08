#pragma once
#include "Engine/Actor.h"

class SpawnManager : public Actor
{
public:
	SpawnManager();
	~SpawnManager();

	void Start();
	void Update(double deltaTime);
	void End();




};