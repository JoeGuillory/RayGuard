#pragma once
#include "Scene.h"

class Actor;

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	void Start();
	void Update(double deltatime);
	void DrawTiles();
	
};
