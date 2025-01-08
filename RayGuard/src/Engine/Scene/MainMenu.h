#pragma once
#include "Scene.h"


class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

	void Start();
	void Update(double deltatime);
	void DrawTiles();
	
};