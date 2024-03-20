/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#include "Wall.hpp"
#include "Color.hpp"

Wall::Wall(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _char = 'x';
    _color = std::make_unique<Color>(39, 122, 16, 255);
}

Wall::~Wall()
{
}

void Wall::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Wall::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Wall::setChar(char c)
{
    _char = c;
}

void Wall::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Wall::setPath(const std::string &path)
{
    _path = path;
}

void Wall::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Wall::getPos()
{
    return _pos;
}

std::vector<std::size_t> Wall::getSize()
{
    return _size;
}

int Wall::getChar()
{
    return _char;
}

std::shared_ptr<IColor> Wall::getColor()
{
    return _color;
}

std::string Wall::getPath()
{
    return _path;
}

float Wall::getRotation()
{
    return _rotation;
}
