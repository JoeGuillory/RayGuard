#include "TextureManager.h"
#include <map>

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
}

void TextureManager::LoadTextures()
{

}

Texture2D TextureManager::GetTexture(const char* key)
{
	return m_texturemanager[key];
}
