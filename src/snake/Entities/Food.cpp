/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Food
*/

#include "Food.hpp"
#include "classes/Color.hpp"
#include "src/snake/SnakeGame.hpp"

std::size_t randomX()
{
    return (rand() % (AREA_GAME_WIDTH - 2)) + 1 + START_WIDTH;
}

std::size_t randomY()
{
    return (rand() % (AREA_GAME_HEIGHT - 2)) + 1 + START_HEIGHT;
}

std::vector<std::size_t> randomPos(Arcade::Snake snake)
{
    std::size_t x = randomX();
    std::size_t y = randomY();

    for (auto &body : snake.getSnake()) {
        std::vector<std::size_t> bodyPos = body->getPos();
        if (bodyPos[0] == x && bodyPos[1] == y) {
            return randomPos(snake);
        }
    }
    return {x, y};
}

Arcade::Food::Food(Arcade::Snake snake)
{
    _size = {29, 29};
    _pos = randomPos(snake);
    _path = FOOD_PATH;
    _rotation = 0;
    _char = 'O';
    _color = std::make_unique<Arcade::Color>(175, 79, 42, 255);
}

void Arcade::Food::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Food::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Food::setChar(char c)
{
    _char = c;
}

void Arcade::Food::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Food::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Food::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Food::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Food::getSize() const
{
    return _size;
}

int Arcade::Food::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Food::getColor() const
{
    return _color;
}

std::string Arcade::Food::getPath() const
{
    return _path;
}

float Arcade::Food::getRotation() const
{
    return _rotation;
}
