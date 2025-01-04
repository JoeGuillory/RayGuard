#include "Tile.h"
#include "Engine/Actor.h"
#include "Engine/Components/Sprite.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Components/IsClicked.h"
Tile::Tile(int tile) 
{
	m_tile = tile;
	m_scale = 50.5;
	
}

Tile::~Tile()
{
}

void Tile::Start()
{
	Actor::Start();
	m_sprite = AddComponent<Sprite>(new Sprite(this, m_tile));
	if (m_tile == 2)
	{
		AddComponent<IsClicked>(new IsClicked(this));
	}
	m_sprite->SetBothScaler(m_scale);
	m_sprite->SetOffset({ 25,25 });
	Transform->Translate({ 25,25 });
	
}

void Tile::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	
	DrawRectangleLinesEx(m_sprite->GetDestination(), 1 , BLACK);
}

void Tile::End()
{
	Actor::End();
}

void Tile::SetTile(int tile)
{
	m_tile = tile;
}
