#pragma once
#include "Component.h"
class Spawner : public Component
{
public:
	Spawner();
	~Spawner();
	
	void Start();
	void Update(double deltaTime);
	void End();
private:
	double m_time;


};