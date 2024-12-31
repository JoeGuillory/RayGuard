#include "TextureManager.h"
#include <map>

TextureManager* TextureManager::instance = nullptr;
TextureManager::TextureManager()
{
	if (instance == nullptr)
		instance = this;
}

TextureManager::~TextureManager()
{
}

void TextureManager::LoadTextures()
{
	
	Texture2D tower = LoadTexture("res/Images/Tower 01.png");
	Texture2D grasstile = LoadTexture("res/Images/GrassTile.png");
	Texture2D pathtile = LoadTexture("res/Images/PathTile.png");


	m_texturemanager.insert(std::pair<int, Texture2D>(1, tower));
	m_texturemanager.insert(std::pair<int, Texture2D>(2, grasstile));
	m_texturemanager.insert(std::pair<int, Texture2D>(3, pathtile));

}

 Texture2D TextureManager::GetTexture(int key)
{
	return m_texturemanager[key];
}
