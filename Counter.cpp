#include "Counter.hpp"


namespace sfext 
{

bool Counter::tick()
{
    if (value + 1 >= goal)
        return true;
    
    ++value;

    return false;
}

} // namespace sfext
