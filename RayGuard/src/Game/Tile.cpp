#include "Tile.h"
#include "Engine/Actor.h"
#include "Engine/Components/Sprite.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Components/IsClicked.h"
Tile::Tile(int tile) 
{
	m_tile = tile;
}

Tile::~Tile()
{
}

void Tile::Start()
{
	Actor::Start();
	Sprite* m_sprite = AddComponent<Sprite>(new Sprite(this, m_tile));
	if (m_tile == 2)
	{
		AddComponent<IsClicked>(new IsClicked(this));
	}
	m_sprite->SetBothScaler(50.5);
	m_sprite->SetOffset({ 25,25 });
	Transform->Translate({ 25,25 });
}

void Tile::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	

}

void Tile::End()
{
	Actor::End();
}

void Tile::SetTile(int tile)
{
	m_tile = tile;
}
