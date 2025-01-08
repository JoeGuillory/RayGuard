#pragma once
#include "Engine/Actor.h"
class Sprite;

class Tower : public Actor
{
public:
	Tower();
	~Tower();

	void Start();
	void Update(double deltaTime);
	void End();
private:
	Sprite* m_sprite;
};

