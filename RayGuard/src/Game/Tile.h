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
	void OnDisable();
	void OnEnable();
	void SetSize(float size) { m_scale = size; }
	

private:
	int m_tile;
	Sprite* m_sprite;
	IsClicked* m_clicked;
	
};