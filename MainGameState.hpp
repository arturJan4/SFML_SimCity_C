#ifndef MAINGAMESTATE_HPP_INCLUDED
#define MAINGAMESTATE_HPP_INCLUDED

#include "State.hpp"
#include "GameLoop.hpp" //GameData
#include "World.hpp"

class MainGameState : public State
{
    public:

    MainGameState(std::shared_ptr<GameData> gamedata);//std::unique_ptr?

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

    private:
        std::shared_ptr<GameData> m_data; //copy pointer?
        World m_world;
        sf::Clock m_clock;
        sf::View m_view;
        sf::Sprite m_background;
};

#endif // MAINGAMESTATE_HPP_INCLUDED
