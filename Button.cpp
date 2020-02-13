#include "Button.hpp"
#include <iostream>

Button::Button()
{

}

Button::Button(float x, float y, float width, float height)
{
    float newXO = (m_sprite.getPosition().x)/2;
    float newYO = (m_sprite.getPosition().y)/2;
    m_sprite.setOrigin(newXO, newYO);
    m_shape.setOrigin(newXO,newYO);
    m_sprite.setPosition(x,y);
    m_shape.setPosition(x,y);
    //m_sprite.setScale(2,2);
}

Button::~Button()
{

}

void Button::update(const sf::Vector2f mousePos)
{
    m_mouseState = MouseState::VOID;
    m_backgroundRectColor = sf::Color::Yellow;
    if(m_sprite.getGlobalBounds().contains(mousePos))
    {
        m_mouseState = MouseState::HOVERING;
        m_backgroundRectColor = sf::Color::Green;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_mouseState = MouseState::PRESSED;
            m_backgroundRectColor = sf::Color::Black;
        }
    }

    m_shape.setFillColor(m_backgroundRectColor);
}

bool Button::isHovering()
{
    //TODO
    return false;
}

bool Button::isPressed()
{
    if(m_mouseState == MouseState::PRESSED)return true;
    return false;
}

void Button::updatePosition(float x, float y, float width, float height)
{
    //m_shape.setPosition(sf::Vector2f(x,y));
    m_shape.setFillColor(m_backgroundRectColor);

    float newXO = (m_sprite.getGlobalBounds().width)/2;
    float newYO = (m_sprite.getGlobalBounds().height)/2;
    //std::cerr << newXO << " " << newYO << "\n";
    m_sprite.setOrigin(newXO, newYO);
    m_shape.setOrigin(newXO*0.95f,newYO*0.97f);
    m_shape.setSize(sf::Vector2f(m_sprite.getGlobalBounds().width*0.95,m_sprite.getGlobalBounds().height*0.97f));
    m_sprite.setPosition(x,y);
    m_shape.setPosition(x,y);
   // m_sprite.setScale(width,height);

}
void Button::render(sf::RenderWindow& window)
{
    window.draw(m_shape);
    window.draw(m_sprite);
}

void Button::setTexture(sf::Texture& texture)
{
    m_sprite.setTexture(texture);
}
