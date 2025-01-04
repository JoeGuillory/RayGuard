#pragma once
#include "Engine/Components/Component.h"
#include "raylib.h"
class IsClicked : public Component
{
public:
	IsClicked(Actor* owner);
	~IsClicked();

	void Start();
	void Update(double deltaTime);

private:
	bool m_isClicked;
	bool m_inPosition;
	bool CheckMousePosition( Vector2 position);
};

