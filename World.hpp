#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <vector>
#include <map>
#include "Tile.hpp"

class World
{
    //TODO passing tileREF
    public:
    //World(const std::string& filepath, int width); // always square?
   // World(Tile testTile);
    World(const std::string& filepath,unsigned int width, unsigned int height
          ,std::map<std::string, Tile> &m_tileRefResources);//height width in first line
    ~World(){};

    int m_width;
    int m_height;
    int m_gridSize;
    float m_scale = 1.0;

    std::vector<Tile> m_tileVector;
    //std::map<std::string, Tile> m_tileRefResources;
    //Tile tile;
    sf::Texture temp;

    //("assets/Tile/commercial.png",TileType::EMPTY);
    //Tile** m_tileArray;//2d array of size width x width
    //int& at(int x, int y);//returns refernce to arr[x][y]

    void load(const std::string& filepath,std::map<std::string, Tile> &m_tileRefResources);//load from disk
    void save(const std::string& filepath);//save to disk
    void draw(sf::RenderWindow& window, float dt);

};
#endif // WORLD_HPP_INCLUDED
