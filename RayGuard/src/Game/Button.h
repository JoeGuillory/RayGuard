#include "Engine/Actor.h"
#pragma once
class Sprite;

class Button : public Actor
{
public:
	Button(int key);
	~Button();
	void Start();
	void Update(double deltaTime);
	void End();

private:
	Sprite* m_sprite;
	int m_key;
};
	