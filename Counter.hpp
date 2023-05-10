/* 
    sfext - Simple extensions for SFML
    beeldscherm (https://github.com/beeldscherm)

    Use this software for whatever you want, on your own resposibility. 

    10.05.2023
*/

#pragma once


namespace sfext 
{

class Counter
{
public:
    int value, goal;

    bool tick()  { return ++value >= goal ? true : false; };
    void reset() { value = 0; }

    Counter();
    Counter(int _goal): value(0), goal(_goal) {}
};

} // namespace sfext
