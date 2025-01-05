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
	void OnDisable();
private:
	bool m_isClicked;
	bool m_inPosition;
	bool m_placed;
	bool CheckMousePosition( Vector2 position);
};

