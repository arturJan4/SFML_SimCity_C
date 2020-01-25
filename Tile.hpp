#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

enum class TileType : unsigned char
{
    EMPTY,
    FOREST,
    WATER,
    MINE,
    ROAD,
    RESIDENTIAL,
    COMMERCIAL,
    INDUSTRIAL,
};

class Tile
{
    public:
    Tile(sf::Texture& texture, TileType type);
    ~Tile();

    sf::Sprite m_assoSprite;
    TileType m_type;

    void update();
    void draw(sf::RenderWindow& window, float dt);
};

#endif // TILE_HPP_INCLUDED
