/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeBody
*/

#include "SnakeBody.hpp"
#include "classes/Color.hpp"

#include "src/centipede/CentipedeGame.hpp"

Arcade::SnakeBody::SnakeBody(std::size_t x, std::size_t y, std::string path, Direction dir)
{
    _pos = {x, y};
    _size = {1, 1};
    _path = path;
    _char = '=';
    _color = std::make_unique<Color>(39, 122, 16, 255);
    _direction = dir;
    updateRotation();
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

void Arcade::SnakeBody::setDirection(Direction dir)
{
    _direction = dir;
}

void Arcade::SnakeBody::updateRotation()
{
    if (_direction == D_LEFT)
        _rotation = 270;
    if (_direction == D_DOWN)
        _rotation = 180;
    if (_direction == D_RIGHT)
        _rotation = 90;
    if (_direction == D_UP)
        _rotation = 0;
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

Arcade::Direction Arcade::SnakeBody::getDirection() const
{
    return _direction;
}
