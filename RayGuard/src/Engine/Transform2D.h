#pragma once
#include "Vector2.h"

namespace MathLibrary
{
	struct Matrix3;
}
class Actor;

class Transform2D
{
public:
	Transform2D(Actor* owner = nullptr);
	~Transform2D();

	//Functions
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void Rotate(float radians);
	void SetAngle(float radians);
	void UpdateTransforms();
	void AddChild(Transform2D* child);
	void RemoveChild(Transform2D* child);


	//Getters and Setters
	MathLibrary::Vector2 LocalPosition();
	void LocalPosition(MathLibrary::Vector2 position);
	MathLibrary::Vector2 LocalScale();
	void LocalScale(MathLibrary::Vector2 scale);
	MathLibrary::Vector2 GlobalPosition();
	MathLibrary::Vector2 GlobalScale();
	MathLibrary::Matrix3 LocalRotation();
	void LocalRotation(MathLibrary::Matrix3 rotation);
	float LocalRotationAngle() { return m_localRotationAngle; };
	float GetToDegrees();
	float ToDegrees(float radian);
	Transform2D* GetParent() {return m_parent; }
	Transform2D** GetChild() { return m_children; }
	Actor* GetOwner() { return m_owner; }
	
	MathLibrary::Vector2 GetForward();
	MathLibrary::Vector2 GetRight();

private:
	//Variables
	MathLibrary::Matrix3* m_localMatrix;
	MathLibrary::Matrix3* m_globalMatrix;
	MathLibrary::Matrix3* m_localTranslation;
	MathLibrary::Matrix3* m_localRotation;
	MathLibrary::Matrix3* m_localScale;

	Transform2D* m_parent;
	Transform2D** m_children;
	Actor* m_owner;
	float m_localRotationAngle;
	




};