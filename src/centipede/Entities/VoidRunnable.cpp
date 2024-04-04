/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** VoidRunnable
*/

#include "VoidRunnable.hpp"
#include "classes/Color.hpp"
#include "src/snake/SnakeGame.hpp"

Arcade::VoidRunnable::VoidRunnable(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _char = ' ';
    _size = {1, 1};
    _path = VOID_PATH;
    _rotation = 0;
    _color = std::make_unique<Color>(66, 242, 17, 255);
}

void Arcade::VoidRunnable::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::VoidRunnable::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::VoidRunnable::setChar(char c)
{
    _char = c;
}

void Arcade::VoidRunnable::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::VoidRunnable::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::VoidRunnable::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::VoidRunnable::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::VoidRunnable::getSize() const
{
    return _size;
}

int Arcade::VoidRunnable::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::VoidRunnable::getColor() const
{
    return _color;
}

std::string Arcade::VoidRunnable::getPath() const
{
    return _path;
}

float Arcade::VoidRunnable::getRotation() const
{
    return _rotation;
}
