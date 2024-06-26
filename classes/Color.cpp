/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Color
*/

#include "Color.hpp"
#include <iostream>
#define IM_HERE std::cout << "I'm here " << __LINE__ << " on " << __FILE__ << std::endl;

Arcade::Color::Color(short r, short g, short b, short a)
    : _r(r), _g(g), _b(b), _a(a)
{
}

void Arcade::Color::setColor(short r, short g, short b, short a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

short Arcade::Color::getR()
{
    return _r;
}

short Arcade::Color::getG()
{
    return _g;
}

short Arcade::Color::getB()
{
    return _b;
}

short Arcade::Color::getA()
{
    return _a;
}
