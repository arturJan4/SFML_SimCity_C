#include "World.hpp"
#include <memory>
#include <fstream>
#include <iostream>

World::World()
{
    m_width = 64;
    m_height = 64;
    sf::Texture temp;
    if(!temp.loadFromFile("assets/Tile/commercial.png"))std::cerr << "error loading tile";
    Tile testTile(temp,TileType::EMPTY);
    for(int i = 0; i < 64*64; ++i)
    {
        m_tileVector.push_back(testTile);
    }

}

World::World(const std::string& filepath)
{
    load(filepath);
}

void World::load(const std::string& filepath)
{
    std::ifstream inFile;
    inFile.open(filepath, std::ios::in);
    if(!inFile)
    {
        std::cerr << "unable to open file <" << filepath << ">\n";
        exit(1);
    }

    inFile >> m_width;
    inFile >> m_height;

    //read rest
    //std::cerr << m_width << " "<< m_height;
    inFile.close();
}

void World::save(const std::string& filepath)
{
    std::ofstream outFile;
    outFile.open(filepath, std::ios::out);
    if(!outFile)
    {
        std::cerr << "unable to open file <" << filepath << ">\n";
        exit(1);
    }

    //save rest
    outFile.close();
}

void World::draw(sf::RenderWindow& window, float dt)
{
    for(int i = 0; i < m_height; ++i)
    {
        for(int j = 0; j < m_width; ++j)
        {
               // m_tileVector[i*m_width + j].m_assoSprite.setPosition(120,120);
                m_tileVector[i*m_width + j].draw(window,dt);
        }
    }
}
