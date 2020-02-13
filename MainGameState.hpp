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
    void moveCamera();

    private:
        std::shared_ptr<GameData> m_data; //copy pointer?
        World* m_world;
        sf::Clock m_clock;
        sf::View m_view;
        sf::View m_guiView;
        sf::Sprite m_background;

        sf::Vector2f m_mousePosView;
        sf::Vector2f m_mousePosBeg;
        sf::Vector2f m_mousePosEnd;
        bool isSelecting = false;

        Tile m_currentTile;
        std::string m_replaceTile;

        float m_zoom;
};

#endif // MAINGAMESTATE_HPP_INCLUDED
