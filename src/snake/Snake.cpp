/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Entities/Wall.hpp"
#include "SnakeGame.hpp"

Snake::Snake()
{
    _snake.push_back(std::make_shared<SnakeBody>(14, 17));
    _snake.push_back(std::make_shared<SnakeBody>(14, 18));
    _snake.push_back(std::make_shared<SnakeBody>(14, 19));
    _snake.push_back(std::make_shared<SnakeBody>(14, 20));
    _dir = D_RIGHT;
    _timer = Timer();
    _timer.start();
    _speed = 0.4;
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

int moveSnakePart(SnakeBody *part, std::vector<std::vector<std::shared_ptr<IEntity>>> map, std::size_t x, std::size_t y)
{
    IEntity *mapElement = map[y][x].get();
    if (typeid(*mapElement) == typeid(Wall) || typeid(*mapElement) == typeid(SnakeBody))
        return -1;
    part->setPos(x + START_WIDTH, y + START_HEIGHT);
    return 0;
}

int Snake::moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map)
{
    if (_timer.getElapsedTime() < _speed)
        return 0;

    for (std::size_t i = _snake.size() - 1; i > 0; i--) {
        SnakeBody *current = _snake[i].get();
        SnakeBody *prev = _snake[i - 1].get();
        std::size_t x = prev->getPos()[0] - START_WIDTH;
        std::size_t y = prev->getPos()[1] - START_HEIGHT;

        if (moveSnakePart(current, map, x, y) == 1)
            return -1;
    }

    SnakeBody *head = _snake.front().get();
    if (_dir == D_UP)
        if (moveSnakePart(head, map, head->getPos()[0] - START_WIDTH, head->getPos()[1] - 1 - START_HEIGHT) == -1)
            return -1;
    if (_dir == D_DOWN)
        if (moveSnakePart(head, map, head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT) == -1)
            return -1;
    if (_dir == D_LEFT)
        if (moveSnakePart(head, map, head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == -1)
            return -1;
    if (_dir == D_RIGHT)
        if (moveSnakePart(head, map, head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == -1)
            return -1;

    _timer.reset();
    return 0;
}

void Snake::growSnake()
{
    SnakeBody *end = _snake.back().get();
    std::size_t x = end->getPos()[0];
    std::size_t y = end->getPos()[1];

    _snake.push_back(std::make_shared<SnakeBody>(x, y));
}

void Snake::setDirection(Direction dir)
{
    _dir = dir;
}

std::vector<std::shared_ptr<SnakeBody>> Snake::getSnake() const
{
    return _snake;
}
