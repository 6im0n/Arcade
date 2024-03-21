/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Food
*/

#include "Food.hpp"
#include "Color.hpp"
#include "src/snake/SnakeGame.hpp"

std::size_t randomX()
{

    return (rand() % (AREA_GAME_WIDTH - 2)) + 1 + START_WIDTH;
}

std::size_t randomY()
{
    return (rand() % (AREA_GAME_HEIGHT - 2)) + 1 + START_HEIGHT;
}

std::vector<std::size_t> randomPos(Snake snake)
{
    std::size_t x = randomX();
    std::size_t y = randomY();

    for (auto &body : snake.getSnake()) {
        auto bodyPos = body->getPos();
        if (bodyPos[0] == x && bodyPos[1] == y) {
            return randomPos(snake);
        }
    }
    return {x, y};
}

Food::Food(Snake snake)
{
    _size = {17, 17};
    _pos = randomPos(snake);
    _path = "assets/apple";
    _rotation = 0;
    _char = 'O';
    _color = std::make_unique<Color>(40, 79, 42, 255);
}

Food::~Food()
{
}

void Food::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Food::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Food::setChar(char c)
{
    _char = c;
}

void Food::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Food::setPath(const std::string &path)
{
    _path = path;
}

void Food::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Food::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Food::getSize() const
{
    return _size;
}

int Food::getChar() const
{
    return _char;
}

std::shared_ptr<IColor> Food::getColor() const
{
    return _color;
}

std::string Food::getPath() const
{
    return _path;
}

float Food::getRotation() const
{
    return _rotation;
}
