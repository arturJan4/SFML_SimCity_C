#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include "Animation.hpp"

enum class TileType : unsigned char
{
    EMPTY,
    FOREST,
    COMMERCIAL,
    RESIDENTIAL,
    INDUSTRIAL,
    ROAD,
    WATER,
    MINE,
};

class Tile
{
    public:
    Tile():m_animationComponent(0,6.0f,0,0)
    {
    //std::cerr<<"empty tile instance";
    };
    Tile(sf::Texture& texture, TileType type,const unsigned int tileSize,
    int maxId, float animationSpeed, int cost);
    ~Tile();

    sf::Sprite m_assoSprite;
    TileType m_type;
    int m_tileSize; //in pixels
    int m_cost;
    AnimationComponent m_animationComponent;

    void update();
    void draw(sf::RenderWindow& window, float dt);
};

#endif // TILE_HPP_INCLUDED
