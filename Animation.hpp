/* 
    sfext - Simple extensions for SFML
    beeldscherm (https://github.com/beeldscherm)

    Use this software for whatever you want, on your own resposibility. 

    10.05.2023
*/

#pragma once

#include "Spritesheet.hpp"
#include "Counter.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <vector>


namespace sfext 
{

class Animation
{
public:

enum AnimationMode : char
{
    ANIMATION_LOOP,     // Animation goes back to the first frame after the last one
    ANIMATION_RUN_ONCE, // Animation stops after the last frame
    ANIMATION_BOOMERANG // Animation turns around after the last frame
};

    sf::Sprite& next();
    sf::Sprite& frame() { return m_Frames.at(m_CurrentFrame); }

    void generateFromSpritesheet(const Spritesheet&        frames, int startIndex = 0, int endIndex = -1);
    void generateFromSprites(const std::vector<sf::Sprite> frames, int startIndex = 0, int endIndex = -1);

    Animation(){};
    Animation(const Spritesheet&            frames, int callsPerFrame = 1, AnimationMode mode = ANIMATION_LOOP, int startIndex = 0, int endIndex = -1);
    Animation(const std::vector<sf::Sprite> frames, int callsPerFrame = 1, AnimationMode mode = ANIMATION_LOOP, int startIndex = 0, int endIndex = -1);

private:
    Counter shouldChange;
    AnimationMode m_AnimationMode = ANIMATION_LOOP;
    int m_CurrentFrame = 0;
    int m_Increment = 1;
    std::vector<sf::Sprite> m_Frames;

    void increment();
};

} // namespace sfext
