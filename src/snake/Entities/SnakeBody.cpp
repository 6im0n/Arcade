/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeBody
*/

#include "SnakeBody.hpp"
#include "classes/Color.hpp"

SnakeBody::SnakeBody(std::size_t x, std::size_t y, std::string path)
{
    _pos = {x, y};
    _size = {29, 29};
    _path = path;
    _char = '=';
    _rotation = 0;
    _color = std::make_unique<Color>(39, 122, 16, 255);
}

void SnakeBody::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void SnakeBody::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void SnakeBody::setChar(char c)
{
    _char = c;
}

void SnakeBody::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void SnakeBody::setPath(const std::string &path)
{
    _path = path;
}

void SnakeBody::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> SnakeBody::getPos() const
{
    return _pos;
}

std::vector<std::size_t> SnakeBody::getSize() const
{
    return _size;
}

int SnakeBody::getChar() const
{
    return _char;
}

std::shared_ptr<IColor> SnakeBody::getColor() const
{
    return _color;
}

std::string SnakeBody::getPath() const
{
    return _path;
}

float SnakeBody::getRotation() const
{
    return _rotation;
}
