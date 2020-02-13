#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Button.hpp"

class DropDownList
{
    public:
    DropDownList();
    ~DropDownList();

    void update(sf::Vector2f mousePos);
    void draw(sf::RenderWindow renderWindow);


    private:
    sf::RectangleShape m_currentElement;
    std::vector<Button*> m_list;

};

#endif // GUI_HPP_INCLUDED
