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

	Actor* m_spawnmanager;
	char m_round[256];
	char m_money[256];

};
