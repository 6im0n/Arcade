/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#include "Wall.hpp"
#include "classes/Color.hpp"

Arcade::Wall::Wall(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _char = 'x';
    _size = {17, 17};
    _color = std::make_unique<Color>(39, 122, 16, 255);
    _path = "assets/wall";
    _rotation = 0;
}

void Arcade::Wall::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Wall::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Wall::setChar(char c)
{
    _char = c;
}

void Arcade::Wall::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Wall::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Wall::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Wall::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Wall::getSize() const
{
    return _size;
}

int Arcade::Wall::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Wall::getColor() const
{
    return _color;
}

std::string Arcade::Wall::getPath() const
{
    return _path;
}

float Arcade::Wall::getRotation() const
{
    return _rotation;
}
