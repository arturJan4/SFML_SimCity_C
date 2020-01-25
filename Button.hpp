#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

class Button
{
    private:
    sf::Sprite m_sprite;

    public:
    Button(float x, float y,float width, float height);
    ~Button();

    void update(const sf::Vector2f mousePos);
    bool isHoverin(sf::FloatRect, sf::Vector2f);
    void render();
};


#endif // BUTTON_H_INCLUDED
