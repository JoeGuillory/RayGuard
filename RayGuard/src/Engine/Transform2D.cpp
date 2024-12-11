#include "Transform2D.h"
#include "Actor.h"
#include "Matrix3.h"
#include <cmath>

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
	LocalPosition(LocalPosition() + direction)
}

void Transform2D::Translate(float x, float y)
{
	LocalPosition((LocalPosition() + MathLibrary::Vector2(x,y)))
}

void Transform2D::Rotate(float radians)
{
	
}

void Transform2D::SetAngle(float radians)
{
}
/// <summary>
/// Updates the Transforms Matricies
/// </summary>
void Transform2D::UpdateTransforms()
{
	*m_localMatrix = *m_localTranslation * *m_localRotation * *m_localScale;

	if (m_parent != nullptr)
	{
		*m_globalMatrix = *m_parent->m_globalMatrix * *m_localMatrix;
	}
	else
	{
		*m_globalMatrix = *m_localMatrix;
	}

	// Update each childs transform needs to be added
}

//Getters and Setters 

/// <summary>
/// Gets the Local Position
/// </summary>
/// <returns></returns>
MathLibrary::Vector2 Transform2D::LocalPosition()
{
	return MathLibrary::Vector2(m_localTranslation->m02, m_localTranslation->m12);
}
/// <summary>
/// Sets the local Position
/// </summary>
/// <param name="position"></param>
void Transform2D::LocalPosition(MathLibrary::Vector2 position)
{
	m_localTranslation->m02 = position.x;
	m_localTranslation->m11 = position.y;
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::LocalScale()
{
	return MathLibrary::Vector2(m_localScale->m02, m_localScale->m12);
}

void Transform2D::LocalScale(MathLibrary::Vector2 scale)
{
	m_localScale->m02 = scale.x;
	m_localScale->m11 = scale.y;
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::GlobalPosition()
{
	return MathLibrary::Vector2(m_globalMatrix->m02, m_globalMatrix->m12);
}

MathLibrary::Vector2 Transform2D::GlobalScale()
{
	MathLibrary::Vector2 xAxis = MathLibrary::Vector2(m_globalMatrix->m00, m_globalMatrix->m10);
	MathLibrary::Vector2 xAxis = MathLibrary::Vector2(m_globalMatrix->m01, m_globalMatrix->m11);
	
	return MathLibrary::Vector2(xAxis.getMagnitude(),xAxis.getMagnitude());
}

float Transform2D::LocalRotation()
{
	return m_localRotationAngle
}

void Transform2D::LocalRotation(float radians)
{
	
}

MathLibrary::Vector2 Transform2D::GetForward()
{
	return MathLibrary::Vector2(m_globalMatrix->m00,m_globalMatrix->m10).getNormalized();
}

MathLibrary::Vector2 Transform2D::GetRight()
{
	return MathLibrary::Vector2(m_globalMatrix->m01,m_globalMatrix->m11).getNormalized();
}




