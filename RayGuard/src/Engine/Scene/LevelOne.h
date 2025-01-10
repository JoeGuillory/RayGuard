#pragma once
#include "Scene.h"


class LevelOne : public Scene
{
public:
	LevelOne();
	~LevelOne();

	void Start();
	void Update(double deltaTime);
	void End();
	void DrawTiles();




};
