/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Void
*/

#include "Void.hpp"
#include "classes/Color.hpp"
#include "src/snake/SnakeGame.hpp"

Arcade::Void::Void(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _char = ' ';
    _size = {29, 29};
    _path = VOID_PATH;
    _rotation = 0;
    _color = std::make_unique<Color>(66, 242, 17, 255);
}

void Arcade::Void::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Void::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Void::setChar(char c)
{
    _char = c;
}

void Arcade::Void::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Void::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Void::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Void::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Void::getSize() const
{
    return _size;
}

int Arcade::Void::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Void::getColor() const
{
    return _color;
}

std::string Arcade::Void::getPath() const
{
    return _path;
}

float Arcade::Void::getRotation() const
{
    return _rotation;
}
