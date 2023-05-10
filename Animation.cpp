/* 
    sfext - Simple extensions for SFML
    beeldscherm (https://github.com/beeldscherm)

    Use this software for whatever you want, on your own resposibility. 

    10.05.2023
*/

#include "Animation.hpp"


namespace sfext 
{

void Animation::increment()
{
    m_CurrentFrame += m_Increment;

    if (m_AnimationMode == ANIMATION_BOOMERANG && m_CurrentFrame == 0 && m_Increment < 0)
        m_Increment = -m_Increment;
    
    else if (m_CurrentFrame == m_Frames.size())
    {
        switch (m_AnimationMode) 
        {
        case ANIMATION_LOOP:
        m_CurrentFrame = 0;
        break;

        case ANIMATION_RUN_ONCE:
        m_CurrentFrame -= m_Increment;
        break;

        case ANIMATION_BOOMERANG:
        m_Increment = -m_Increment;
        m_CurrentFrame += 2 * m_Increment;
        break;
        }
    }
    shouldChange.reset();
}


sf::Sprite& Animation::next()
{
    if (shouldChange.tick())
        increment();
    
    return frame();
}


void Animation::generateFromSprites(const std::vector<sf::Sprite> frames, int startIndex, int endIndex)
{
    // If endIndex is not in between 0 and frames.size(), 
    // then it is invalid and we set the end of the frames vector as our endIndex.
    endIndex = endIndex < 0 || endIndex > frames.size() ? frames.size() : endIndex;

    // We resize the frames vector to be able to fit all frames from startIndex to endIndex.
    m_Frames.resize(endIndex - startIndex);

    // Since the m_Frames vector is perfectly sized now, we can just loop over it and set all sprites equal to
    // those from the frames vector with an offset of startIndex.
    for (int i = 0; i < m_Frames.size(); ++i)
    {
        m_Frames.at(i) = frames.at(startIndex + i);
    }
}


// Since this ^^ piece of code can be utilized for both std::vectors and Spritesheets, we connect all other generation functions to it.
void Animation::generateFromSpritesheet(const Spritesheet& frames, int startIndex, int endIndex) 
{ 
    generateFromSprites(frames.sprites(), startIndex, endIndex); 
}


Animation::Animation(const Spritesheet& frames, int callsPerFrame, AnimationMode mode, int startIndex, int endIndex) 
: shouldChange(callsPerFrame), m_AnimationMode(mode)
{ 
    generateFromSprites(frames.sprites(), startIndex, endIndex); 
}


Animation::Animation(const std::vector<sf::Sprite> frames, int callsPerFrame, AnimationMode mode, int startIndex, int endIndex) 
: shouldChange(callsPerFrame), m_AnimationMode(mode)
{ 
    generateFromSprites(frames, startIndex, endIndex); 
}


} // namespace sfext
