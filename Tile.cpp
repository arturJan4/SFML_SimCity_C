#include "Tile.hpp"

Tile::Tile(sf::Texture& texture, TileType type, const unsigned int tileSize,
           int maxId, float animationSpeed, int cost):m_animationComponent(maxId,animationSpeed,tileSize,tileSize)
{
    //read all tiles first
    m_assoSprite.setTexture(texture);
    m_type = type;
    m_tileSize = tileSize;
}

Tile::~Tile()
{

}

void Tile::update()
{
    //UPDATE changes to current tile(ex. population)
}

void Tile::draw(sf::RenderWindow& window, float dt)
{
    //TODO animations
    m_animationComponent.update(dt);
    m_assoSprite.setTextureRect(m_animationComponent.m_currentBound);
    window.draw(m_assoSprite);
}
