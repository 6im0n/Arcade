/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Void
*/

#include "Void.hpp"
#include "Color.hpp"

Void::Void(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _char = ' ';
    _color = std::make_unique<Color>(66, 242, 17, 255);
}

Void::~Void()
{
}

void Void::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Void::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Void::setChar(char c)
{
    _char = c;
}

void Void::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Void::setPath(const std::string &path)
{
    _path = path;
}

void Void::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Void::getPos()
{
    return _pos;
}

std::vector<std::size_t> Void::getSize()
{
    return _size;
}

int Void::getChar()
{
    return _char;
}

std::shared_ptr<IColor> Void::getColor()
{
    return _color;
}

std::string Void::getPath()
{
    return _path;
}

float Void::getRotation()
{
    return _rotation;
}
