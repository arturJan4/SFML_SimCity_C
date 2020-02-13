#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

enum MouseState
{
    VOID,
    HOVERING,
    PRESSED,
};

class Button
{
    private:
    sf::Sprite m_sprite;
    sf::RectangleShape m_shape;
    sf::Font m_font;

    public:
    Button();
    Button(float x, float y,float width, float height);
    ~Button();

    void update(const sf::Vector2f mousePos);
    void render(sf::RenderWindow& window);
    void setTexture(sf::Texture& texture);
    void updatePosition(float x, float y, float width, float height);

    bool isHovering();
    bool isPressed();

    MouseState m_mouseState;
    sf::Color m_backgroundRectColor;
};


#endif // BUTTON_H_INCLUDED
