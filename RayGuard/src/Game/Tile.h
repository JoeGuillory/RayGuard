#pragma once
#include "Engine/Actor.h"

class Tile : public Actor
{
public:
	Tile(int tile);
	~Tile();

	void Start();
	void Update(double deltaTime);
	void End();

private:
	int m_tile;


};