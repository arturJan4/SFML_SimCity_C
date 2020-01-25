#include "World.hpp"
#include <memory>
#include <fstream>
#include <iostream>

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

}
