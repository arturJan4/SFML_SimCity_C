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
        3 - RESIDENTIAL
        4 - INDUSTRIAL
        5 - ROAD
        6 - WATER
        7 - MINE
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
            m_tileVector.push_back(tileRefResources.at("grass"));
            //tile->m_type = TileType::EMPTY;
            //tile->m_assoSprite;
            break;
        case 1:
            m_tileVector.push_back(tileRefResources.at("forest"));
            break;
        case 2:
            m_tileVector.push_back(tileRefResources.at("commercial"));
            break;
        case 3:
            m_tileVector.push_back(tileRefResources.at("residential"));
            break;
        case 4:
            m_tileVector.push_back(tileRefResources.at("industrial"));
            break;
        case 5:
            m_tileVector.push_back(tileRefResources.at("road"));
            break;
        case 6:
            m_tileVector.push_back(tileRefResources.at("water"));
            break;
        case 7:
            m_tileVector.push_back(tileRefResources.at("mine"));
            break;
        default:
            std::cerr << "inType error";
            break;
        }
    }
    //read rest
    //std::cerr << m_width << " "<< m_height;
    inFile.close();

    for(int i = 0; i < m_width * m_height; ++i)
        m_selected.push_back(0);
    rotateRoads();
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

    outFile << m_width << " ";
    outFile << m_height << " ";

    for(int i = 0; i < m_width * m_height; ++i)
    {
        switch(m_tileVector[i].m_type)
        {
        case TileType::EMPTY:
            outFile << 0;
            break;
        case TileType::FOREST:
            outFile << 1;
            break;
        case TileType::COMMERCIAL:
            outFile << 2;
            break;
        case TileType::RESIDENTIAL:
            outFile << 3;
            break;
        case TileType::INDUSTRIAL:
            outFile << 4;
            break;
        case TileType::ROAD:
            outFile << 5;
            break;
        case TileType::WATER:
            outFile << 6;
            break;
        case TileType::MINE:
            outFile << 7;
            break;

        default:
            std::cerr << "inType error";
            break;
        }
        outFile << " ";
    }
    //save rest
    outFile.close();
    rotateRoads();
}
void World::rotateRoads()
{
    for(int i = 0; i < m_height; ++i)
    {
        for(int j = 0; j < m_width; ++j)
        {
            bool adjTiles[4] = {0,0,0,0};//UP DOWN LEFT RIGHT
            if(i > 0)
            {
                 if(m_tileVector[(i-1)*m_width + j].m_type == TileType::ROAD)
                    adjTiles[0] = 1;
            }
            if(i < m_height - 1)
            {
                if(m_tileVector[(i+1)*m_width + j].m_type == TileType::ROAD)
                    adjTiles[1] = 1;
            }
            if(j > 0)
            {
                if(m_tileVector[i*m_width + j-1].m_type == TileType::ROAD)
                    adjTiles[2] = 1;
            }
            if(j < m_width - 1)
            {
                if(m_tileVector[i*m_width + j+1].m_type == TileType::ROAD)
                    adjTiles[3] = 1;
            }

            int variant = 0;
            if(adjTiles[0] && adjTiles[1] && adjTiles[2] && adjTiles[3])//all
                variant = 7;
            else if(adjTiles[0] && adjTiles[1] && adjTiles[2])//UP DOWN LEFT
                variant = 3;
            else if(adjTiles[0] && adjTiles[1] && adjTiles[3])//UP DOWN RIGHT
                variant = 6;
            else if(adjTiles[1] && adjTiles[2] && adjTiles[3])//DOWN LEFT RIGHT
                variant = 4;
            else if(adjTiles[0] && adjTiles[2] && adjTiles[3])//UP LEFT RIGHT
                variant = 5;
            else if(adjTiles[0] && adjTiles[2])//UP LEFT
                variant = 11;
            else if(adjTiles[0] && adjTiles[3])//UP RIGHT
                variant = 10;
            else if(adjTiles[1] && adjTiles[2])//DOWN LEFT
                variant = 8;
            else if(adjTiles[1] && adjTiles[3])//DOWN RIGHT
                variant = 9;
            else if(adjTiles[2] || adjTiles[3])//LEFT RIGHT
                variant = 1;
            else if(adjTiles[0] || adjTiles[1])//UP DOWN
                variant = 2;


            if(m_tileVector[i*m_width + j].m_type != TileType::ROAD)continue;

            m_tileVector[i*m_width + j].m_animationComponent.m_startBound.top = 16 * variant;


        }
    }
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
    if(x < 0 || y < 0 || x >= m_width || y >= m_height)
        return;
    m_tileVector[y*m_width + x].m_assoSprite.setColor(sf::Color(0x53,0x85,0x8c,255));
    m_selected[y*m_width + x] = 1;
}

void World::selectArea(sf::Vector2f mousePosBeg, sf::Vector2f mousePosEnd)
{
    //bounds
    if(mousePosBeg.x < 0)mousePosBeg.x = 0;
    else if(mousePosBeg.x >= m_width)mousePosBeg.x = m_width - 1;
    if(mousePosEnd.x < 0)mousePosEnd.x = 0;
    else if(mousePosEnd.x >= m_width)mousePosEnd.x = m_width - 1;
    if(mousePosBeg.y < 0)mousePosBeg.y = 0;
    else if(mousePosBeg.y >= m_height)mousePosBeg.y = m_height - 1;
    if(mousePosEnd.y < 0)mousePosEnd.y = 0;
    else if(mousePosEnd.y >= m_height)mousePosEnd.y = m_height - 1;

    //swap
    if(mousePosBeg.x > mousePosEnd.x)
    {
        float temp = mousePosBeg.x;
        mousePosBeg.x = mousePosEnd.x;
        mousePosEnd.x = temp;
    }
    if(mousePosBeg.y > mousePosEnd.y)
    {
        float temp = mousePosBeg.y;
        mousePosBeg.y = mousePosEnd.y;
        mousePosEnd.y = temp;
    }

    for(int i = mousePosBeg.y; i <= mousePosEnd.y; ++i)
    {
        for(int j = mousePosBeg.x; j <= mousePosEnd.x; ++j)
        {
            m_selected[i*m_width + j] = 1;
            m_tileVector[i*m_width + j].m_assoSprite.setColor(sf::Color(0x53,0x85,0x8c,255));
        }
    }
}

void World::replaceTiles(Tile tile)
{
    for(int i = 0; i < m_height; ++i)
    {
        for(int j = 0; j < m_width; ++j)
        {
            if(m_selected[i*m_width + j] == 1)
            {
                m_tileVector[i*m_width + j] = tile;
            }
        }
    }
    rotateRoads();
}

void World::clearSelected()
{
    for(int i = 0; i < m_height; ++i)
    {
        for(int j = 0; j < m_width; ++j)
        {
            m_selected[i*m_width + j] = 0;
            m_tileVector[i*m_width +j].m_assoSprite.setColor(sf::Color(0xff,0xff,0xff));
        }
    }
}
