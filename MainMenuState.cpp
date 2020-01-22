#include "MainMenuState.hpp"

MainMenuState::MainMenuState(std::shared_ptr<GameData> gamedata)
{
    m_data = gamedata;
}

void MainMenuState::init()
{
    m_background.setTexture(this->m_data->graphics.getTexture("background"));
}

void MainMenuState::handleInput()
{
    sf::Event event;
    while(m_data->window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            m_data->window.close();
        }
    }
}

void MainMenuState::update(float dt)
{

}

void MainMenuState::draw(float dt)
{
    m_data->window.clear();
    m_data->window.draw(m_background);
    m_data->window.display();
}
