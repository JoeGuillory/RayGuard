#include "Transform2D.h"
#include "Actor.h"
#include "Matrix3.h"

Transform2D::Transform2D() {}

Transform2D::Transform2D(Actor* owner)
{
	m_owner = owner;
}

Transform2D::~Transform2D()
{
}

//Public Functions
void Transform2D::Translate(MathLibrary::Vector2 direction)
{
	
}

void Transform2D::Translate(float x, float y)
{
}

void Transform2D::Rotate(float radians)
{
}

void Transform2D::SetAngle(float radians)
{
}

void Transform2D::UpdateTransforms()
{
	m_localMatrix
}



