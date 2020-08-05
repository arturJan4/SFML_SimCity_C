#ifndef GAMELOOP_HPP_INCLUDED
#define GAMELOOP_HPP_INCLUDED

#include "StateMachine.hpp"
#include "MediaHandler.hpp"
#include "Tile.hpp"
#include <string>
#include <map>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct GameData
{
    MediaHandler graphics;
    StateMachine machine;
    sf::RenderWindow window;
    bool isFullScreen = false;
    std::string title;
    std::map<std::string, Tile> m_TileMap;
};

class GameLoop
{
    public:
    GameLoop(int width, int height, const char *title);
    ~GameLoop();

    const static int tileSize = 16; //size of tile-textures in pixels

    private:
        const float dt = 1.0f / 60.0f;

        sf::Clock m_clock;
        std::shared_ptr<GameData> m_data = std::make_shared<GameData>(); //copy pointer

        void run();
        void loadTextures();
};

#endif // GAMELOOP_HPP_INCLUDED
