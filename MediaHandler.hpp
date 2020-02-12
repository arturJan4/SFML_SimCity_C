#ifndef MEDIAHANDLER_HPP_INCLUDED
#define MEDIAHANDLER_HPP_INCLUDED

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class MediaHandler
{
    public:
        MediaHandler(){}
        ~MediaHandler(){}

        void loadTexture(const std::string texName,const std::string filepath);
        sf::Texture &getTexture(const std::string texName);

        void loadFont(const std::string fontName,const std::string filepath);
        sf::Font &getFont(const std::string fontName);

    private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
};


#endif // MEDIAHANDLER_HPP_INCLUDED
