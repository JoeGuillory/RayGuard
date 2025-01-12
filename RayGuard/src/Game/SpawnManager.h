#pragma once
#include "Engine/Actor.h"
class Spawner;
class SpawnManager : public Actor
{
public:
	SpawnManager(int maxrounds);
	~SpawnManager();

	void Start();
	void Update(double deltaTime);
	void End();

	int GetRound() { return m_round; }
	bool IsRoundFinished();
	bool IsCompleted() { return m_allCompleted; }

private:
	int m_maxRounds;
	int m_round;
	int m_roundSpawnCount;
	bool m_allCompleted;
	Spawner* m_spawner;
	

};