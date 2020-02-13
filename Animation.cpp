#include "Animation.hpp"

AnimationComponent::AnimationComponent(int maxID,float animSpeed, int width, int height)
{
    m_startBound = sf::IntRect(0,0,width,height);
    m_width = width;
    m_height = height;
    m_currentBound = m_startBound;
    m_maxID = maxID;
    m_currentID = 0;
    m_duration = 0.0f;
}

void AnimationComponent::update(float& dt)
{
    m_duration += dt;
    if(m_duration >= m_timer)
    {
        m_duration = 0;
        if(m_currentID < m_maxID)
        {
            m_currentBound.left += m_width;
        }
        else
        {
            m_currentID = 0;
            m_currentBound = m_startBound;
        }
        m_currentID++;
    }
}
