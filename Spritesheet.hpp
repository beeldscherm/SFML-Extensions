/* 
    sfext - Simple extensions for SFML
    beeldscherm (https://github.com/beeldscherm)

    Use this software for whatever you want, on your own resposibility. 

    10.05.2023
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>


namespace sfext
{

class Spritesheet
{
public:
    // Make the Spritesheet iterable.
    std::vector<sf::Sprite>::iterator begin() { return m_Sprites.begin(); }
    std::vector<sf::Sprite>::iterator end()   { return m_Sprites.end();   }

    /// Get the amount of sf::Sprites in the Spritesheet.
    size_t getSize() const { return m_Sprites.size(); }

    // Get a reference to the sf::Sprite at a certain index from the sheet using the function or the [] operator.
    sf::Sprite& getSprite (int index) { return m_Sprites.at(index); }
    sf::Sprite& operator[](int index) { return getSprite(index); }

    // Get a reference to the std::vector<sf::Sprite> used to contain the sprites.
    const std::vector<sf::Sprite>& sprites() const { return m_Sprites; }

    // Get sf::Sprites from an sf::Texture.
    void generateFromTexture(const sf::Texture& sheet, sf::Vector2i imageSize, int imageAmount = -1);

    Spritesheet(){};
    Spritesheet(const sf::Texture& sheet, sf::Vector2i imageSize, int imageAmount = -1);

private:
    std::vector<sf::Sprite> m_Sprites; // The std::vector that stores the sf::Sprites.
};

} // namespace sfext
