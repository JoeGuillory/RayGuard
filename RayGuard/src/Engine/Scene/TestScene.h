#pragma once
#include "Scene.h"


class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	void Start();
	void Update(double deltatime);

};
