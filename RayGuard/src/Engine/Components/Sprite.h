#pragma once
#include "Engine/Components/Component.h"
#include "raylib.h"
#include "Vector2.h"
class Sprite : public Component
{
public:
	Sprite(Actor* owner, int key);
	~Sprite();

	void Start();
	void Update(double deltaTime);
	void End();
	/// <summary>
	/// Converts Mathlibrary to Raylib vector2
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	RAYLIB_H::Vector2 ConvertVector(MathLibrary::Vector2 vector);
	void SetWidthScaler(float size);
	void SetHightScaler(float size);
	void SetBothScaler(float size);

private:
	float m_scaleX;
	float m_scaleY;
	float m_startingRotation;
	Texture2D m_texture;
	Rectangle m_source;
	Rectangle m_destination;
	MathLibrary::Vector2 m_origin;
	MathLibrary::Vector2 m_offset;
	MathLibrary::Vector2 m_vectorscaler;
};

