#pragma once
#include "Matrix3.h"
#include "Vector2.h"

class Actor;

using namespace MathLibrary;

class Transform2D
{
public:
	Transform2D();
	Transform2D(Actor* owner);
	~Transform2D();

	//Functions
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);
	void SetAngle(float radians);
	void UpdateTransforms();


	//Getters and Setters
	MathLibrary::Vector2 GetLocalPosition();
	MathLibrary::Vector2 GetLocalScale();
	MathLibrary::Vector2 GetGlobalPosition();
	MathLibrary::Vector2 GetGlobalScale();
	float GetLocalRotation();
	float GetGlobalRotation();

	MathLibrary::Vector2 GetForward();
	MathLibrary::Vector2 GetRight();
	Actor* GetOwner() { return m_owner; }

private:
	//Variables
	Matrix3 m_localMatrix;
	Matrix3 m_globalMatrix;
	Matrix3 m_localTranslation;
	Matrix3 m_localRotation;
	Matrix3 m_localScale;

	Transform2D* m_parent;
	Transform2D** m_children;
	Actor* m_owner;
	float m_localRotationAngle;





};