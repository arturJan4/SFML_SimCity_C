#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <iostream>

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
    Tile()
    {
    //std::cerr<<"empty tile instance";
    };
    Tile(sf::Texture& texture, TileType type,const unsigned int tileSize);
    ~Tile();

    sf::Sprite m_assoSprite;
    TileType m_type;
    int m_tileSize; //in pixels

    void update();
    void draw(sf::RenderWindow& window, float dt);
};

#endif // TILE_HPP_INCLUDED
