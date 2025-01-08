#include "Tile.h"
#include "Engine/Actor.h"
#include "Engine/Components/Sprite.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Engine/Components/IsClicked.h"
#include "Game/Tower.h"
Tile::Tile(int tile) 
{
	m_tile = tile;
	m_scale = 50.5;
	m_towerMade = false;
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
		m_clicked = AddComponent<IsClicked>(new IsClicked(this));
	}
	m_sprite->SetBothScaler(m_scale);
	m_sprite->SetOffset({ 25,25 });
	Transform->Translate({ 25,25 });
	
}

void Tile::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	if (m_clicked != nullptr)
		if (m_clicked->IfClicked() && m_clicked->IfPlaced())
			if (!m_towerMade)
			{
				Actor::Instantiate(new Tower(), nullptr, Transform->GlobalPosition() - MathLibrary::Vector2(16.5,20));
				m_towerMade = true;
			}
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


