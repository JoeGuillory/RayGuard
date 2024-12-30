#include "Sprite.h"
#include "Engine/Components/Component.h"
#include "TextureManager.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"


Sprite::Sprite(Actor* owner, int key) : Component::Component(owner)
{
	
	m_scaleX = 1;
	m_scaleY = 1;
	m_startingRotation = 0;
	m_texture = TextureManager::instance->GetTexture(key);
	m_textureWidth = (float)m_texture.width;
	m_textureHeight = (float)m_texture.height;
	m_source = { 0,0,m_textureWidth,m_textureHeight};
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
	m_source = { 0,0,m_textureWidth,m_textureHeight };
	m_destination = { _owner->Transform->GlobalPosition().x,_owner->Transform->GlobalPosition().y,_owner->Transform->GlobalScale().x * m_scaleX,_owner->Transform->GlobalScale().y * m_scaleY};
	
	DrawTexturePro(m_texture, m_source, m_destination, ConvertVector(m_origin), _owner->Transform->GetToDegrees(), WHITE);
}

void Sprite::End()
{
}

RAYLIB_H Vector2 Sprite::ConvertVector(MathLibrary::Vector2 vector)
{
	RAYLIB_H::Vector2 rayvector = {vector.x,vector.y};
	return rayvector;
}

void Sprite::SetWidthScaler(float size)
{
	m_scaleX = size;
}

void Sprite::SetHightScaler(float size)
{
	m_scaleY = size;
}

void Sprite::SetBothScaler(float size)
{
	m_scaleX = size;
	m_scaleY = size;
}

float Sprite::GetTextureWidth()
{
	return m_textureWidth;
}

float Sprite::GetTextureHeight()
{
	return m_textureHeight;
}

void Sprite::SetTextueHeight(float height)
{
	m_textureHeight = height;
}

void Sprite::SetTextureWidth(float width)
{
	m_textureWidth = width;
}
