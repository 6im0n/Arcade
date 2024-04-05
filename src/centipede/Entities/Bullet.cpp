/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Bullet
*/

#include "Bullet.hpp"
#include "classes/Color.hpp"
#include "src/centipede/CentipedeGame.hpp"

#include <algorithm>

Arcade::Bullet::Bullet(std::size_t x, std::size_t y, float time)
{
    _pos = {x, y};
    _size = {1, 1};
    _path = FOOD_PATH;
    _char = '|';
    _rotation = 0;
    _color = std::make_unique<Color>(39, 122, 16, 255);
    _lastTime = time;
}

void Arcade::Bullet::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Bullet::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Bullet::setChar(char c)
{
    _char = c;
}

void Arcade::Bullet::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Bullet::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Bullet::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Bullet::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Bullet::getSize() const
{
    return _size;
}

int Arcade::Bullet::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Bullet::getColor() const
{
    return _color;
}

std::string Arcade::Bullet::getPath() const
{
    return _path;
}

float Arcade::Bullet::getRotation() const
{
    return _rotation;
}

std::vector<std::size_t> Arcade::Bullet::moveBullet(float time, std::vector<Snake> &snakes)
{
    std::vector<std::size_t> pos = _pos;

    if (time - _lastTime > BULLET_SPEED) {
        _pos[1] -= 1;
        _lastTime = time;
    }
    for (std::size_t i = 0; i < snakes.size(); i++ ) {
        for (auto snakePart : snakes[i].getSnake()) {
            if (snakePart.get()->getPos()[0] == _pos[0] && snakePart.get()->getPos()[1] == _pos[1]) {
                pos.insert(pos.begin(), 2);
                pos.push_back(i);
                return pos;
            }
        }
    }
    if (_pos[1] <= 8) {
        pos.insert(pos.begin(), 1);
        return pos;
    }
    pos.insert(pos.begin(), 0);
    return pos;
}
