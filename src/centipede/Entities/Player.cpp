/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#include "Player.hpp"
#include "classes/Color.hpp"
#include "src/centipede/CentipedeGame.hpp"

Arcade::Player::Player()
{
    _pos = {GET_POSXY_AREA(7, AREA_GAME_HEIGHT - 3)};
    _size = {1, 1};
    _path = SNAKE_HEAD_PATH;
    _char = '=';
    _rotation = 0;
    _color = std::make_unique<Color>(39, 122, 16, 255);
}

void Arcade::Player::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Player::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Player::setChar(char c)
{
    _char = c;
}

void Arcade::Player::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Player::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Player::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Player::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Player::getSize() const
{
    return _size;
}

int Arcade::Player::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Player::getColor() const
{
    return _color;
}

std::string Arcade::Player::getPath() const
{
    return _path;
}

float Arcade::Player::getRotation() const
{
    return _rotation;
}

void Arcade::Player::shoot(std::vector<std::shared_ptr<Bullet>> &bullets, Timer &timer)
{
    if (bullets.size() >= 1)
        return;
    std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(_pos[POSX], _pos[POSY] - 1, timer.getElapsedTime());
    bullets.push_back(bullet);
}

void Arcade::Player::move(Direction dir)
{
    if (dir == Direction::D_UP && _pos[POSY] > GET_POSY_AREA(AREA_GAME_HEIGHT - 5))
        _pos[POSY] -= 1;
    if (dir == Direction::D_DOWN && _pos[POSY] < GET_POSY_AREA(AREA_GAME_HEIGHT - 1))
        _pos[POSY] += 1;
    if (dir == Direction::D_LEFT && _pos[POSX] > GET_POSX_AREA(1))
        _pos[POSX] -= 1;
    if (dir == Direction::D_RIGHT && _pos[POSX] < GET_POSX_AREA(AREA_GAME_WIDTH - 2))
        _pos[POSX] += 1;
}
