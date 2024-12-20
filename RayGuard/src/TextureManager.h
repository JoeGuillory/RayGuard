#pragma once
#include "raylib.h"
#include <map>
class TextureManager
{
public:
	TextureManager();
	~TextureManager();


	void LoadTextures();
	Texture2D GetTexture(const char* key);

private:
	 std::map<const char*, Texture2D> m_texturemanager;


	







};