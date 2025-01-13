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
	bool IfPlaced() { return m_placed; }
	bool IfClicked() { return m_isClicked; }
	void Reset();
private:
	bool m_isClicked;
	bool m_inPosition;
	bool m_placed;
	bool CheckMousePosition( Vector2 position);
};

