#pragma once
#include "Engine/Actor.h"
class Spawner;
class SpawnManager : public Actor
{
public:
	SpawnManager();
	~SpawnManager();

	void Start();
	void Update(double deltaTime);
	void End();

	int GetRound() { return m_round; }

private:
	int m_round;
	int m_roundSpawnCount;
	Spawner* m_spawner;


};