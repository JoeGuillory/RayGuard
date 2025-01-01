#pragma once
#include "Engine/Components/Component.h"
class IsClicked : public Component
{
public:
	IsClicked(Actor* owner);
	~IsClicked();

	void Start();
	void Update(double deltaTime);


private:
	bool m_isClicked;
};

