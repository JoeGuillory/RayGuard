#pragma once
#include "raylib.h"
#include <map>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();


	 void LoadTextures();
	 Texture2D GetTexture(int key);
public:
	static TextureManager* instance;
private:
	  std::map<int, Texture2D> m_texturemanager;

};