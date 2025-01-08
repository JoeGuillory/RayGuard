#include "Button.h"
#include "Engine/Actor.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Transform2D.h"

Button::Button(int key)
{
	m_key = key;
}

Button::~Button()
{
}

void Button::Start()
{
	Actor::Start();
	m_sprite = AddComponent<Sprite>(new Sprite(this, m_key));
	m_sprite->SetBothScaler(55);
	
	
	
}

void Button::Update(double deltaTime)
{
	Actor::Update(deltaTime);
}

void Button::End()
{
	Actor::End();
}
