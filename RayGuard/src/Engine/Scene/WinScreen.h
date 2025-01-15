#pragma once
#include "Scene.h"


class WinScreen : public Scene
{
public:
	WinScreen();
	~WinScreen();

	void Start();
	void Update(double deltaTime);
	void End();
	void DrawTiles();



};