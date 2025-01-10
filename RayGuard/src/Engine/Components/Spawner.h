#pragma once
#include "Component.h"
class Spawner : public Component
{
public:
	Spawner(Actor* owner, int spawncount);
	~Spawner();
	
	void Start();
	void Update(double deltaTime);
	void End();

	bool Finished() { return m_finishedSpawning; }
private:
	double m_time;
	int m_spawncount;
	int m_spawned;
	bool m_finishedSpawning;

};