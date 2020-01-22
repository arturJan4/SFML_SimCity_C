#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <SFML/System.hpp>

class State
{
    public:

    //sf::Time -> float?
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(float dt) = 0;//deltaTime

    virtual void stop(){};
    virtual void resume(){};
};

#endif // STATE_HPP_INCLUDED
