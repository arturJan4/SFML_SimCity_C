#ifndef MAINMENUSTATE_HPP_INCLUDED
#define MAINMENUSTATE_HPP_INCLUDED

#include "State.hpp"
#include "GameLoop.hpp" //GameData
#include "Button.hpp"

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
        sf::View m_view;
        sf::Vector2f m_position;
        sf::RectangleShape m_rectBackground;
        sf::Vector2f m_mousePosView;
        Button m_playButton = Button();
        Button m_exitButton = Button();
        //Button button;
};
#endif // MAINMENUSTATE_HPP_INCLUDED
