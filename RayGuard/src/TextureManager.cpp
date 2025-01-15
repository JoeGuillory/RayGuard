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
	Texture2D grasstile = LoadTexture("res/Images/towerDefense_tile129.png");
	Texture2D pathtile = LoadTexture("res/Images/towerDefense_tile093.png");
	Texture2D arrow = LoadTexture("res/Images/arrow.png");
	Texture2D bettledown = LoadTexture("res/Images/BettleDown.png");
	Texture2D bettleleft = LoadTexture("res/Images/BettleLeft.png");
	Texture2D esckey = LoadTexture("res/Images/esckey.png");
	Texture2D enterkey = LoadTexture("res/Images/enterkey.png");
	Texture2D othergrass = LoadTexture("res/Images/OtherGrass.png");
	Texture2D placetile = LoadTexture("res/Images/PlaceTile.png");
	Texture2D bullet = LoadTexture("res/Images/Bullet.png");
	Texture2D base = LoadTexture("res/Images/Base.png");

	m_texturemanager.insert(std::pair<int, Texture2D>(1, tower));
	m_texturemanager.insert(std::pair<int, Texture2D>(2, grasstile));
	m_texturemanager.insert(std::pair<int, Texture2D>(3, pathtile));
	m_texturemanager.insert(std::pair<int, Texture2D>(4, arrow));
	m_texturemanager.insert(std::pair<int, Texture2D>(5, bettledown));
	m_texturemanager.insert(std::pair<int, Texture2D>(6, bettleleft));
	m_texturemanager.insert(std::pair<int, Texture2D>(7, esckey));
	m_texturemanager.insert(std::pair<int, Texture2D>(8, enterkey));
	m_texturemanager.insert(std::pair<int, Texture2D>(9, othergrass));
	m_texturemanager.insert(std::pair<int, Texture2D>(10,placetile));
	m_texturemanager.insert(std::pair<int, Texture2D>(11,bullet));
	m_texturemanager.insert(std::pair<int, Texture2D>(12,base));

}

 Texture2D TextureManager::GetTexture(int key)
{
	return m_texturemanager[key];
}
