#include "MainMenuState.hpp"
#include "MainGameState.hpp"

MainMenuState::MainMenuState(std::shared_ptr<GameData> gamedata)
{
    m_data = gamedata;
}

void MainMenuState::init()
{
    sf::Vector2f position = sf::Vector2f(this->m_data->window.getSize());
    m_view.setSize(position);
    position = 0.5f * position;
    m_view.setCenter(position);
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
        if(sf::Event::KeyPressed == event.type)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                m_data->window.close();
            }
            if(event.key.code == sf::Keyboard::Space)//new state
            {
                m_data->machine.pushState(new MainGameState(this->m_data));
            }
        }
        if(sf::Event::Resized == event.type)
        {
           m_view.setSize(event.size.width,event.size.height);
           //
           m_background.setPosition(m_data->window.mapPixelToCoords(sf::Vector2i(0,0),m_view));
           m_background.setScale(
           float(event.size.width) / float((m_background.getTexture()->getSize().x)),
           float(event.size.height)/ float((m_background.getTexture()->getSize().y)));


        }
    }
}

void MainMenuState::update(float dt)
{

}

void MainMenuState::draw(float dt)
{
    m_data->window.setView(m_view);
    m_data->window.clear();
    m_data->window.draw(m_background);
    m_data->window.display();
}
