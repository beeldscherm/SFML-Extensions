#include "Spritesheet.hpp"


namespace sfext 
{

void Spritesheet::generateFromTexture(const sf::Texture& sheet, sf::Vector2i imageSize, int imageAmount)
{
    sf::Vector2u textureSize = sheet.getSize();

    /*
        Here we set the imageAmount variable to the correct value.

        There are 2 cases:
        1. The user did not provide an imageAmount. We will then assume that the spritesheet is completely full,
           so the imageAmount therefore will be spritesheet-width in images times spritesheet-height in images.
        
        2. The user did provide an imageAmount, so we will leave that unchanged.
    */
    imageAmount = imageAmount < 0 ? textureSize.x / imageSize.x * (textureSize.y / imageSize.y) : imageAmount;

    // We make the m_Sprites container big enough to fit all the sprites on the spritesheet.
    m_Sprites.resize(imageAmount);

    // This is the point on the texture from which we will create each of the sprites. 
    // The position of this sf::Vector2u will be changed for every sprite.
    sf::Vector2i textureFrom;

    /*
        The following loops will loop over the entire image.

        The main loop loop goes over the rows of the sprite (the y direction), 
        and the subloop will add sprites in that row to m_Sprites (the x direction).

        So the sprites will be stored in memory like this:
        Spritesheet
        |--------------------------|
        |Sprite 1|Sprite 2|Sprite 3|
        |--------------------------|
        |Sprite 4|Sprite 5|Sprite 6|
        |--------------------------|

        We initialize a variable called counter. This counter will count the sprites we have added to m_Sprites.
    */
    for (int counter = 0 ;; textureFrom.y += imageSize.y)
    {
        for (textureFrom.x = 0 ; textureFrom.x < textureSize.x; textureFrom.x += imageSize.x)
        {
            m_Sprites.at(counter++) = sf::Sprite(sheet, {textureFrom, imageSize});

            // When we have added all the sprites, we return.
            if (counter == imageAmount)
                return;
        }
    }
}


Spritesheet::Spritesheet(const sf::Texture& sheet, sf::Vector2i imageSize, int imageAmount)
{
    generateFromTexture(sheet, imageSize, imageAmount);
}

} // namespace sfext
