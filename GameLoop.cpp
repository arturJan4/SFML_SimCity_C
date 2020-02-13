#include "GameLoop.hpp"
#include "MainMenuState.hpp"
#include <iostream>

GameLoop::GameLoop(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width,height),
                          title, sf::Style::Default);
    m_data->window.setFramerateLimit(60);
    this->loadTextures();
    m_data->machine.pushState(new MainMenuState(this->m_data));
    this->run();
}

void GameLoop::loadTextures()
{
    m_data->graphics.loadTexture("background", "assets/background.png");

    //MENU
    m_data->graphics.loadFont("Gellosia","assets/UI/Gellosia.ttf");

    m_data->graphics.loadTexture("UIEmptyButtoon", "assets/UI/EmptyButton.png");
    m_data->graphics.loadTexture("UIExitButton", "assets/UI/ExitButton.png");
    m_data->graphics.loadTexture("UILargeEmptyButton", "assets/UI/LargeEmptyButton.png");
    m_data->graphics.loadTexture("UIMenuButton", "assets/UI/MenuButton.png");
    m_data->graphics.loadTexture("UIPlayButton", "assets/UI/PlayButton.png");
    m_data->graphics.loadTexture("UISmallEmptyButton", "assets/UI/SmallEmptyButton.png");

    //TILES
    m_data->graphics.loadTexture("commercial", "assets/Tile/commercial.png");
    m_data->graphics.loadTexture("forest", "assets/Tile/forest.png");
    m_data->graphics.loadTexture("grass", "assets/Tile/grass.png");
    m_data->graphics.loadTexture("industrial", "assets/Tile/industrial.png");
    m_data->graphics.loadTexture("residential", "assets/Tile/residential.png");
    m_data->graphics.loadTexture("water", "assets/Tile/waterAnim.png");
    //m_data->graphics.loadTexture("empty", "assets/Tile/empty.png");
    //m_data->graphics.loadTexture("mine", "assets/Tile/mine.png");
    //m_data->graphics.loadTexture("road", "assets/Tile/roads.png");

    //TILEMAP
    m_data->m_TileMap["grass"] = Tile(m_data->graphics.getTexture("grass"),TileType::EMPTY,tileSize,0,6.0f,0);
    //m_data->m_TileMap[""] = Tile(m_data->graphics.getTexture("forest"),TileType::FOREST,tileSize,0,6.0f,0);
    //m_data->m_TileMap["forest"] = Tile(m_data->graphics.getTexture("forest"),TileType::FOREST,tileSize,0,6.0f,0);
    m_data->m_TileMap["forest"] = Tile(m_data->graphics.getTexture("forest"),TileType::FOREST,tileSize,0,6.0f,0);
    m_data->m_TileMap["industrial"] = Tile(m_data->graphics.getTexture("industrial"),TileType::INDUSTRIAL,tileSize,0,6.0f,0);
    m_data->m_TileMap["residential"] = Tile(m_data->graphics.getTexture("residential"),TileType::RESIDENTIAL,tileSize,0,6.0f,0);
    m_data->m_TileMap["commercial"] = Tile(m_data->graphics.getTexture("commercial"),TileType::COMMERCIAL,tileSize,0,6.0f,0);
    m_data->m_TileMap["water"] = Tile(m_data->graphics.getTexture("water"),TileType::WATER,tileSize,3,6.0f,0);
}

void GameLoop::run()
{
    //?convert to sf::Time
    float currentTime = this->m_clock.getElapsedTime().asSeconds();
    float newTime;
    float sumTime = 0.0f; //accumulator for differences in rendering
    float frameTime;
    float interpolation;

    while(this->m_data->window.isOpen())
    {
        this->m_data->machine.applyPendingChanges();

        newTime = this->m_clock.getElapsedTime().asSeconds();

        frameTime = newTime - currentTime;

        if(frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }
        currentTime = newTime;

        sumTime += frameTime;

        while(sumTime >= dt)
        {
            this->m_data->machine.getTopState()->handleInput();
            this->m_data->machine.getTopState()->draw(dt);
            this->m_data->machine.getTopState()->update(dt);
            //this->m_data->window.clear(sf::Color::Black);
            //this->m_data->window.display();
            sumTime -= dt;
        }

        //draw in-between frame
        interpolation = sumTime / dt;
        this->m_data->machine.getTopState()->draw(interpolation);
        //this->m_data->window.display();
    }
}

GameLoop::~GameLoop()
{
    while(this->m_data->machine.getTopState() != nullptr)
        this->m_data->machine.popState();//? Test this
}
