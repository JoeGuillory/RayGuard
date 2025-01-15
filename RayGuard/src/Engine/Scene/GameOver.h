#pragma once
#include "Scene.h"


class GameOver : public Scene
{
public:
	GameOver();
	~GameOver();

	void Start();
	void Update(double deltaTime);
	void End();
	void DrawTiles();

	

};