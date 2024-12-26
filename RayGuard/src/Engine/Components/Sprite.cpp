#include "Sprite.h"
#include "Engine/Components/Component.h"
#include "TextureManager.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"


Sprite::Sprite(Actor* owner, int key)
{
	m_owner = owner;
	m_scaler = 1;
	m_startingRotation = 0;
	m_texture = TextureManager::instance->GetTexture(key);
	m_source = { 0,0,(float)m_texture.height,(float)m_texture.width};
}

Sprite::~Sprite()
{
}

void Sprite::Start()
{
	Component::Start();
}

void Sprite::Update(double deltaTime)
{
	m_destination = { m_owner->Transform->GlobalPosition().x,m_owner->Transform->GlobalPosition().y,m_owner->Transform->GlobalScale().x,m_owner->Transform->GlobalScale().y };

	DrawTexturePro(m_texture, m_source, m_destination, ConvertVector(m_origin), m_owner->Transform->GetToDegrees(), WHITE);
}

void Sprite::End()
{
}

RAYLIB_H Vector2 Sprite::ConvertVector(MathLibrary::Vector2 vector)
{
	RAYLIB_H::Vector2 rayvector = {vector.x,vector.y};
	return rayvector;
}
