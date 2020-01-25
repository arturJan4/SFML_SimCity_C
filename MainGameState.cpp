#include "MainGameState.hpp"

MainGameState::MainGameState(std::shared_ptr<GameData> gamedata)
{
    m_data = gamedata;
}

void MainGameState::init()
{

}

void MainGameState::handleInput()
{
    sf::Event event;
    while(m_data->window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            m_data->window.close();
        }
        if(sf::Event::KeyPressed == event.type)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                m_data->window.close();
            }
        }
        if(sf::Event::Resized == event.type)
        {
           m_background.setScale(
           float(event.size.width) / float((m_background.getTexture()->getSize().x)),
           float(event.size.height)/ float((m_background.getTexture()->getSize().y)));
        }
    }
}

void MainGameState::update(float dt)
{

}

void MainGameState::draw(float dt)
{
    m_data->window.clear();
    m_data->window.draw(m_background);
    m_data->window.display();
}
