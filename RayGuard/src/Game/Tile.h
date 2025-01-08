#pragma once
#include "Engine/Actor.h"
#include "raylib.h"
class Sprite;
class IsClicked;

class Tile : public Actor
{
public:
	Tile(int tile);
	~Tile();

	void Start();
	void Update(double deltaTime);
	void End();
	void SetTile(int tile);
	void SetSize(float size) { m_scale = size; }
	void SetTileNumber(int tilenumer) { m_tileNumber = tilenumer; }
	
private:
	int m_tile;
	Sprite* m_sprite;
	IsClicked* m_clicked;
	bool m_towerMade;
	int m_tileNumber;
	float time;


};