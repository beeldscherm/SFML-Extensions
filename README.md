# SFML-Extensions
Simple Extensions for the C++ SFML library.

# Included:

## Spritesheets
### Files:
 - Spritesheet.cpp
 - Spritesheet.hpp

### Dependencies
-

### Use
The `sfext::Spritesheet` class can be used to break a spritesheet that you have created into `sf::Sprite` elements, which are then stored inside the class.


## Counters
### Files:
 - Counter.hpp

### Dependencies
-

### Use
The `sfext::Counter` class is a very simple class which can be used as a counter. It is used in various other `sfext` classes.


# Work in Progress

## Animations
### Files:
 - Animation.cpp
 - Animation.hpp

### Dependencies
 - Spritesheet.cpp
 - Spritesheet.hpp
 - Counter.hpp

### Use
The `sfext::Animation` class can be used to create an animation out of several `sf::Sprites`. 
There are currently 3 animation modes, stored in the `sfext::Animation::AnimationMode` enum.
 - ANIMATION_LOOP, the animation restarts after the last frame.
 - ANIMATION_RUN_ONCE, the animation stops after the last frame.
 - ANIMATION_BOOMERANG, the animation turns around after the last frame.

