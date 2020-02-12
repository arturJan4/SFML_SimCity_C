#include "MainGameState.hpp"

MainGameState::MainGameState(std::shared_ptr<GameData> gamedata)
{
    m_data = gamedata;
    m_world = new World("mapData.txt",64,64,gamedata->m_TileMap);
    init();
}

void MainGameState::init()
{
    //size in pixels
    sf::Vector2f position = sf::Vector2f(this->m_data->window.getSize());
    m_view.setSize(position.x,position.y);
    m_guiView.setSize(position.x,position.y);
    m_guiView.setCenter(position);
    m_view.setCenter((position.x*0.5f),(position.y*0.5f));
    m_zoom = 1.0;//cummulative zoom

    m_background.setTexture(this->m_data->graphics.getTexture("background"));
    m_background.setPosition(m_data->window.mapPixelToCoords(sf::Vector2i(0,0),m_guiView));
    m_background.setScale(
               float(position.x) / float((m_background.getTexture()->getSize().x)),
               float(position.y) / float((m_background.getTexture()->getSize().y)));
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
            else if(event.key.code == sf::Keyboard::Left)
            {
                m_view.move(-4.0f * m_zoom,0);
            }
            else if(event.key.code == sf::Keyboard::Right)
            {
                m_view.move(4.0f * m_zoom,0);
            }
            else if(event.key.code == sf::Keyboard::Up)
            {
                m_view.move(0,-4.0f * m_zoom);
            }
            else if(event.key.code == sf::Keyboard::Down)
            {
                m_view.move(0,4.0f * m_zoom);
            }
        }
        if(sf::Event::MouseMoved)
        {
            //przeniesione do update
        }
        if(sf::Event::MouseWheelScrolled == event.type)
        {
            //std::cerr << event.mouseWheelScroll.delta;
            if(event.mouseWheelScroll.delta > 0)//up
            {
                m_zoom = m_zoom * 0.9f;
                m_view.zoom(0.9f);
            }
            else if(event.mouseWheelScroll.delta < 0)
            {
                m_zoom = m_zoom * 1.1f;
                m_view.zoom(1.1f);
            }
        }
        if(sf::Event::Resized == event.type)
        {
            m_view.setSize(event.size.width,event.size.height);
            m_view.zoom(m_zoom);
            m_guiView.setSize(event.size.width, event.size.height);
            //
            m_background.setPosition(m_data->window.mapPixelToCoords(sf::Vector2i(0,0),m_guiView));
            m_background.setScale(
                float(event.size.width) / float((m_background.getTexture()->getSize().x)),
                float(event.size.height)/ float((m_background.getTexture()->getSize().y)));
        }
    }
}

void MainGameState::update(float dt)
{
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_data->window);
        sf::Vector2f position = sf::Vector2f(this->m_data->window.getSize());
        if(mousePos.x > 0.97f * position.x)//right
        {
                m_view.move(2.0f * m_zoom,0);
        }
        else if(mousePos.x < 0.03f * position.x)//left
        {
                m_view.move(-2.0f * m_zoom,0);
        }
        if(mousePos.y > 0.97f * position.y)//up
        {
                m_view.move(0,2.0f * m_zoom);
        }
        else if(mousePos.y < 0.03f * position.y)//down
        {
                m_view.move(0,-2.0f * m_zoom);
        }
   // m_view.zoom(m_zoom); klatkuje
}

void MainGameState::draw(float dt)
{
    m_data->window.clear();

    m_data->window.setView(m_guiView);
    m_data->window.draw(m_background);

    m_data->window.setView(m_view);
    m_world->draw(m_data->window,dt);

    m_data->window.display();
}
