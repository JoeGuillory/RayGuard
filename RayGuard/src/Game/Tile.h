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
	void SetTile(int tile);

private:
	int m_tile;


};