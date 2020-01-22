#ifndef MAINMENUSTATE_HPP_INCLUDED
#define MAINMENUSTATE_HPP_INCLUDED

#include "State.hpp"
#include "GameLoop.hpp" //GameData

class MainMenuState : public State
{
    public:

    MainMenuState(std::shared_ptr<GameData> gamedata);//std::unique_ptr?

    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

    private:
        std::shared_ptr<GameData> m_data; //copy pointer?
        sf::Clock m_clock;

        sf::Sprite m_background;
};
#endif // MAINMENUSTATE_HPP_INCLUDED