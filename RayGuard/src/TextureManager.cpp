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
	
	Texture2D tower = LoadTexture("res/Images/Tower.png");
	Texture2D grasstile = LoadTexture("res/Images/GrassTile.png");
	Texture2D pathtile = LoadTexture("res/Images/PathTile.png");
	Texture2D arrow = LoadTexture("res/Images/arrow.png");
	Texture2D bettledown = LoadTexture("res/Images/BettleDown.png");
	Texture2D bettleleft = LoadTexture("res/Images/BettleLeft.png");


	m_texturemanager.insert(std::pair<int, Texture2D>(1, tower));
	m_texturemanager.insert(std::pair<int, Texture2D>(2, grasstile));
	m_texturemanager.insert(std::pair<int, Texture2D>(3, pathtile));
	m_texturemanager.insert(std::pair<int, Texture2D>(4, arrow));
	m_texturemanager.insert(std::pair<int, Texture2D>(5, bettledown));
	m_texturemanager.insert(std::pair<int, Texture2D>(6, bettleleft));

}

 Texture2D TextureManager::GetTexture(int key)
{
	return m_texturemanager[key];
}
