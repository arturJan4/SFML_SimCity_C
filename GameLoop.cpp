#include "GameLoop.hpp"
#include "MainMenuState.hpp"

GameLoop::GameLoop(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width,height),
                          title, sf::Style::Close | sf::Style::Titlebar);
    this->loadTextures();
    m_data->machine.pushState(new MainMenuState(this->m_data));
    this->run();
}

void GameLoop::loadTextures()
{
    m_data->graphics.loadTexture("background", "assets/background.png");

}
void GameLoop::run()
{
    //?convert to sf::Time
    float currentTime = this->m_clock.getElapsedTime().asSeconds();
    float newTime;
    float sumTime = 0.0f; //accumulator for differences in rendering and physics
    float frameTime;
    float interpolation;

    while(this->m_data->window.isOpen())
    {
        this->m_data->machine.applyPendingChanges();

        newTime = this->m_clock.getElapsedTime().asSeconds();

        frameTime = newTime - currentTime;

        if(frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }
        currentTime = newTime;

        sumTime += frameTime;

        while(sumTime >= dt)
        {
            this->m_data->machine.getTopState()->handleInput();
            this->m_data->machine.getTopState()->update(dt);
            //this->m_data->window.clear(sf::Color::Black);
            //this->m_data->machine.getTopState()->draw(dt);
            //this->m_data->window.display();
            sumTime -= dt;
        }

        //draw in-between frame
        interpolation = sumTime / dt;
        this->m_data->machine.getTopState()->draw(interpolation);
        this->m_data->window.display();
    }
}

GameLoop::~GameLoop()
{
   while(this->m_data->machine.getTopState() != nullptr)
       this->m_data->machine.popState();//? Test this
}
