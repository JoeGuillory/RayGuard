#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include "Actor.h"
using namespace MathLibrary;

class Transform2D
{
public:
	Transform2D();
	Transform2D(Actor owner);
	~Transform2D();
public:

	//Gets and sets the local Rotation
	float LocalRotation();
	float GlobalRotation();

	//Gets local and Global Scale and Positon
	MathLibrary::Vector2 LocalPosition();
	MathLibrary::Vector2 LocalScale();
	MathLibrary::Vector2 GlobalPosition();
	MathLibrary::Vector2 GlobalScale();

	// Getter for Owner
	Actor GetOwner() { return m_owner; }

	// Gets the Forward Vector
	MathLibrary::Vector2 Forward();
	// Gets the Right Vector
	MathLibrary::Vector2 Right();

	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);
	void SetAngle(float radians);

	void UpdateTransforms();

private:
	
	Matrix3 m_localMatrix;
	Matrix3 m_globalMatrix;
	Matrix3 m_localTranslation;
	Matrix3 m_localRotation;
	Matrix3 m_localScale;

	Actor m_owner;
	float m_localRotationAngle;





};