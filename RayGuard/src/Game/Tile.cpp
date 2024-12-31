#include "Tile.h"
#include "Engine/Actor.h"
#include "Engine/Components/Sprite.h"

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
	m_sprite->SetBothScaler(50);
}

void Tile::Update(double deltaTime)
{
	Actor::Update(deltaTime);



}

void Tile::End()
{
	Actor::End();
}
