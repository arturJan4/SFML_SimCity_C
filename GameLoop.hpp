#ifndef GAMELOOP_HPP_INCLUDED
#define GAMELOOP_HPP_INCLUDED

#include "StateMachine.hpp"
#include "MediaHandler.hpp"
#include <string>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct GameData
{
    MediaHandler graphics;
    StateMachine machine;
    sf::RenderWindow window;
};

class GameLoop
{
    public:
    GameLoop(int width, int height, std::string title);
    ~GameLoop();

    private:
        const float dt = 1.0f / 60.0f;

        sf::Clock m_clock;
        std::shared_ptr<GameData> m_data = std::make_shared<GameData>(); //copy pointer

        void run();
        void loadTextures();
};

#endif // GAMELOOP_HPP_INCLUDED