/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Color
*/

#include "Color.hpp"

Color::Color(short r, short g, short b, short a)
    : _r(r), _g(g), _b(b), _a(a)
{
}

Color::~Color()
{
}

void Color::setColor(short r, short g, short b, short a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

short Color::getR()
{
    return _r;
}

short Color::getG()
{
    return _g;
}

short Color::getB()
{
    return _b;
}

short Color::getA()
{
    return _a;
}