/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeBody
*/

#include "SnakeBody.hpp"
#include "classes/Color.hpp"

Arcade::SnakeBody::SnakeBody(std::size_t x, std::size_t y)
{
    _pos = {x, y};
    _size = {29, 29};
    _path = path;
    _char = '=';
    _rotation = 0;
    _color = std::make_unique<Color>(39, 122, 16, 255);
}

void Arcade::SnakeBody::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::SnakeBody::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::SnakeBody::setChar(char c)
{
    _char = c;
}

void Arcade::SnakeBody::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::SnakeBody::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::SnakeBody::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::SnakeBody::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::SnakeBody::getSize() const
{
    return _size;
}

int Arcade::SnakeBody::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::SnakeBody::getColor() const
{
    return _color;
}

std::string Arcade::SnakeBody::getPath() const
{
    return _path;
}

float Arcade::SnakeBody::getRotation() const
{
    return _rotation;
}
