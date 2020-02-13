#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

#include <iostream>
#include <map>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//class Animation
//{
//    public:
//    Animation(int startFrame, int endFrame, float duration)
//    :m_startFrame(startFrame), m_endFrame(endFrame),m_duration(duration)
//    {};
//    ~Animation(){};
//
//    int m_startFrame;
//    int m_endFrame;
//    float m_duration;
//
//    private:
//
//};

class AnimationComponent
{
    public:
    //std::vector<Animation> m_animations;
    float m_duration; //since new frame
    int m_width;
    int m_height;
    float m_timer = 3.0f;//since beginning animation
    sf::IntRect m_currentBound;
    sf::IntRect m_startBound;

    int m_currentID;
    int m_maxID;

    AnimationComponent(int maxID, float animSpeed, int width, int height);

    //void play();
    void update(float& dt);
    //void pause();
    //void reset();

    private:

};

#endif // ANIMATION_HPP_INCLUDED
