#include "Tile.hpp"

Tile::Tile(sf::Texture& texture, TileType type, const unsigned int tileSize)
{
    //read all tiles first
    m_assoSprite.setTexture(texture);
    m_type = type;
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
    window.draw(m_assoSprite);
}
