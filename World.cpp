#include "World.hpp"
#include <memory>
#include <fstream>
#include <iostream>

World::World(const std::string& filepath, unsigned int width, unsigned int height,
             std::map<std::string, Tile> &tileRefResources)
{
    load(filepath,tileRefResources);
    //m_width = width;
    //m_height = height;
    //m_tileRefResources = tileRefResources;
    //if(!temp.loadFromFile("assets/Tile/grass.png"))std::cerr << "error loading tile";
    //tiles = new Tile[m_width*m_height];
    /*
    for(int i = 0; i < m_width * m_height; ++i)
    {
        tiles[i].m_assoSprite.setTexture(temp);
        tiles[i].m_assoSprite.setScale(m_scale,m_scale);
        tiles[i].m_type = TileType::EMPTY;
        m_tileVector.push_back(tiles[i]);
    }
    */
}

void World::load(const std::string& filepath, std::map<std::string, Tile> &tileRefResources)
{
    /*
        //TYPE
        0 - EMPTY
        1 - FOREST
        2 - COMMERCIAL
        itd.


        Format:
        width height // how many(not pixels)

        //Tiles:

    */
    std::ifstream inFile;
    inFile.open(filepath, std::ios::in);
    if(!inFile.is_open())
    {
        std::cerr << "unable to open file <" << filepath << ">\n";
        exit(1);
    }

    inFile >> m_width;
    inFile >> m_height;

    for(int i = 0; i < m_width * m_height; ++i)
    {
        int type;
        inFile >> type;

        switch(type)
        {
        case 0:
            m_tileVector.push_back(tileRefResources.at("empty"));
            //tile->m_type = TileType::EMPTY;
            //tile->m_assoSprite;
            break;
        case 1:
            m_tileVector.push_back(tileRefResources.at("forest"));
            //std::cerr << "loading tile 1 - forest";
            break;
        case 2:
            m_tileVector.push_back(tileRefResources.at("commercial"));
            //std::cerr << "loading tile 1 - forest";
            break;
        default:
            std::cerr << "inType error";
            break;
        }
    }
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
            sf::Vector2f position;
            //!!Depens on size//TODO change
            position.x = 16 * m_scale * j;
            position.y = 16 * m_scale * i;
            m_tileVector[i*m_width + j].m_assoSprite.setPosition(position);
            m_tileVector[i*m_width + j].draw(window,dt);
        }
    }
}

void World::select(sf::Vector2f mousePos)
{
    int x = mousePos.x/m_gridSize;
    int y = mousePos.y/m_gridSize;
    if(x < 0 || y < 0 || x >= m_width || y >= m_height)return;
    m_tileVector[y*m_width + x].m_assoSprite.setColor(sf::Color(0x53,0x85,0x8c,255));


}
