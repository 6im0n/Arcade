/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "lib/snake/Snake.hpp"

Snake::Snake()
{
    _snake.push_back(std::make_shared<SnakeBody>(10, 10));
    _snake.push_back(std::make_shared<SnakeBody>(10, 11));
    _snake.push_back(std::make_shared<SnakeBody>(10, 12));
    _snake.push_back(std::make_shared<SnakeBody>(10, 13));
    _dir = D_RIGHT;
}

Snake::~Snake()
{
}

void Snake::placeSnake(std::vector<std::shared_ptr<IEntity>> entities) const
{
    for (auto &entity : _snake) {
        entities.push_back(entity);
    }
}

void Snake::moveSnake()
{
    SnakeBody *head = _snake.front().get();

    if (_dir == D_UP)
        head->setPos(head->getPos()[0], head->getPos()[1] - 1);
    if (_dir == D_DOWN)
        head->setPos(head->getPos()[0], head->getPos()[1] + 1);
    if (_dir == D_LEFT)
        head->setPos(head->getPos()[0] - 1, head->getPos()[1]);
    if (_dir == D_RIGHT)
        head->setPos(head->getPos()[0] + 1, head->getPos()[1]);

    for (std::size_t i = 1; i < _snake.size(); i++) {
        SnakeBody *body = _snake[i].get();
        SnakeBody *prev = _snake[i - 1].get();
        std::size_t x = prev->getPos()[0];
        std::size_t y = prev->getPos()[1];

        body->setPos(x, y);
    }
}

void Snake::growSnake()
{
    SnakeBody *end = _snake.back().get();
    std::size_t x = end->getPos()[0];
    std::size_t y = end->getPos()[1];

    _snake.push_back(std::make_shared<SnakeBody>(x, y));
}

void Snake::setDirection(bool left)
{
    if (left) {
        _dir = static_cast<Direction>(_dir + 1);
    } else {
        _dir = static_cast<Direction>(_dir - 1);
    }
}
