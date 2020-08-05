#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <vector>
#include <utility>
#include <string>
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

class GuiStyle
{
    public:
    sf::Font *m_ptrFont;
    float m_borderSize;

    sf::Color m_bodyCol;
    sf::Color m_borderCol;
    sf::Color m_textCol;

    sf::Color m_bodyHighlightCol;
    sf::Color m_borderHighlightCol;
    sf::Color m_textHighlightCol;

    private:
    GuiStyle(sf::Font* font, float borderSize, sf::Color bodyColor, sf::Color borderColor,
        sf::Color textColor, sf::Color bodyHighlightColor, sf::Color borderHighlightColor,
        sf::Color textHighlightColor)
        : m_ptrFont(font), m_borderSize(borderSize), m_bodyCol(bodyColor), m_borderCol(borderColor),
        m_textCol(textColor), m_bodyHighlightCol(bodyHighlightColor),
        m_borderHighlightCol(borderHighlightColor), m_textHighlightCol(textHighlightColor)
        {}
    GuiStyle(){};
};

class GuiEntry
{
    public:
    std::string m_message;
    sf::RectangleShape m_shape;
    sf::Text m_text;

    GuiEntry(const std::string& message, sf::RectangleShape shape, sf::Text text)
    :m_message(message), m_shape(shape), m_text(text)
    {}
    GuiEntry(){};
    private:
};
#endif // GUI_HPP_INCLUDED
