#include "MediaHandler.hpp"

void MediaHandler::loadTexture(const std::string texName,const std::string filepath)
{
    sf::Texture temp;
    if(temp.loadFromFile(filepath))
    {
        this->m_textures[texName] = temp;
    }
}

sf::Texture& MediaHandler::getTexture(const std::string texName)
{
    return this->m_textures.at(texName);
}

void MediaHandler::loadFont(const std::string fontName,const std::string filepath)
{
    sf::Font temp;
    if(temp.loadFromFile(filepath))
    {
        this->m_fonts[fontName] = temp;
    }
}

sf::Font& MediaHandler::getFont(const std::string fontName)
{
    return this->m_fonts.at(fontName);
}

