#include "Transform2D.h"
#include "Actor.h"

Transform2D::Transform2D() {}

Transform2D::Transform2D(Actor* owner)
{
	m_owner = owner;
}

Transform2D::~Transform2D()
{
}



