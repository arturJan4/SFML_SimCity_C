#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <vector>

#include "Tile.hpp"

class World
{
    public:
    //World(const std::string& filepath, int width); // always square?
    World():m_width(0){};
    World(const std::string& filepath);//height width in first line
    ~World(){};

    int m_width;
    int m_height;

    std::vector<Tile> m_tileVector;
    //Tile** m_tileArray;//2d array of size width x width
    //int& at(int x, int y);//returns refernce to arr[x][y]

    void load(const std::string& filepath);//load from disk
    void save(const std::string& filepath);//save to disk
    void draw(sf::RenderWindow& window, float dt);

};
#endif // WORLD_HPP_INCLUDED
