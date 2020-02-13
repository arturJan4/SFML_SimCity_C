#include "MainMenuState.hpp"
#include "MainGameState.hpp"

MainMenuState::MainMenuState(std::shared_ptr<GameData> gamedata)
{
    m_data = gamedata;
}

void MainMenuState::init()
{
    sf::Vector2f position = sf::Vector2f(this->m_data->window.getSize());

    m_rectBackground.setSize(position);
    m_rectBackground.setFillColor(sf::Color::Cyan);

    m_view.setSize(position);
    position = 0.5f * position;
    m_view.setCenter(position);

    m_playButton.setTexture(m_data->graphics.getTexture("UIPlayButton"));
    m_playButton.updatePosition(position.x,position.y,0,0);

    m_exitButton.setTexture(m_data->graphics.getTexture("UIExitButton"));
    m_exitButton.updatePosition(position.x,position.y * 1.25f,0,0);
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
        else if(sf::Event::KeyPressed == event.type)
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
        else if(sf::Event::Resized == event.type)
        {
            sf::Vector2f position;
            position.x = event.size.width;
            position.y = event.size.height;
            m_view.setSize(position.x,position.y);
            m_rectBackground.setScale(position.x,position.y);
            m_rectBackground.setPosition(m_data->window.mapPixelToCoords(sf::Vector2i(0,0),m_view));

            m_playButton.updatePosition(m_view.getCenter().x,m_view.getCenter().y*0.4f,position.x/m_position.x,position.y/m_position.y);
            m_exitButton.updatePosition(m_view.getCenter().x,m_view.getCenter().y*1.3f,position.x/m_position.x,position.y/m_position.y);
            m_position = position;
        }
    }
}

void MainMenuState::update(float dt)
{
    m_mousePosView = m_data->window.mapPixelToCoords(sf::Mouse::getPosition(m_data->window));
    m_playButton.update(m_mousePosView);
    m_exitButton.update(m_mousePosView);

    if(m_playButton.isPressed())
        m_data->machine.pushState(new MainGameState(this->m_data));
    else if(m_exitButton.isPressed())
        m_data->window.close();

    //std::cerr << "\033[2J\033[1;1H";
    //std::cerr << mousePosView.x << " , " << mousePosView.y;
}

void MainMenuState::draw(float dt)
{
    m_data->window.setView(m_view);
    m_data->window.clear();
    m_data->window.draw(m_rectBackground);
    m_playButton.draw(m_data->window);
    m_exitButton.draw(m_data->window);
    m_data->window.display();
}
