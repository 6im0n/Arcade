/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Entities/Wall.hpp"
#include "SnakeGame.hpp"

Arcade::Snake::Snake()
{
    _snake.push_back(std::make_shared<SnakeBody>(14, 17));
    _snake.push_back(std::make_shared<SnakeBody>(14, 18));
    _snake.push_back(std::make_shared<SnakeBody>(14, 19));
    _snake.push_back(std::make_shared<SnakeBody>(14, 20));
    _dirrection = D_RIGHT;
    _timer = Timer();
    _timer.start();
    _speed = 0.4;
}

bool checkCollision(std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map,
    std::vector<std::shared_ptr<Arcade::SnakeBody>> snake,
    std::size_t x, std::size_t y)
{
    Arcade::IEntity *mapElement = map[y][x].get();
    if (typeid(*mapElement) == typeid(Arcade::Wall))
        return false;
    for (auto &part : snake) {
        if (part->getPos()[0] == x + START_WIDTH && part->getPos()[1] == y + START_HEIGHT)
            return false;
    }
    return true;
}

void moveSnakePart(Arcade::SnakeBody *part, std::size_t x, std::size_t y)
{
    part->setPos(x + START_WIDTH, y + START_HEIGHT);
}

int Arcade::Snake::moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map)
{
    if (_timer.getElapsedTime() < _speed)
        return 0;

    for (std::size_t i = _snake.size() - 1; i > 0; i--) {
        SnakeBody *current = _snake[i].get();
        SnakeBody *prev = _snake[i - 1].get();
        std::size_t x = prev->getPos()[0] - START_WIDTH;
        std::size_t y = prev->getPos()[1] - START_HEIGHT;

        moveSnakePart(current, x, y);
    }

    SnakeBody *head = _snake[0].get();

    if (_dirrection == D_UP) {
        if (checkCollision(map, _snake, head->getPos()[0] - START_WIDTH, head->getPos()[1] - 1 - START_HEIGHT) == false)
            return -1;
        moveSnakePart(head, head->getPos()[0] - START_WIDTH, head->getPos()[1] - 1 - START_HEIGHT);
    }
    if (_dirrection == D_DOWN) {
        if (checkCollision(map, _snake, head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT) == false)
            return -1;
        moveSnakePart(head, head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT);
    }
    if (_dirrection == D_LEFT) {
        if (checkCollision(map, _snake, head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false)
            return -1;
        moveSnakePart(head, head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT);
    }
    if (_dirrection == D_RIGHT) {
        if (checkCollision(map, _snake, head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false)
            return -1;
        moveSnakePart(head, head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT);
    }

    _timer.reset();
    return 0;
}

void Arcade::Snake::growSnake()
{
    SnakeBody *end = _snake.back().get();
    std::size_t x = end->getPos()[0];
    std::size_t y = end->getPos()[1];

    _snake.push_back(std::make_shared<SnakeBody>(x, y));
}

void Arcade::Snake::setDirection(Direction dir)
{
    if ((_dirrection == D_UP && dir == D_DOWN) ||
        (_dirrection == D_DOWN && dir == D_UP) ||
        (_dirrection == D_LEFT && dir == D_RIGHT) ||
        (_dirrection == D_RIGHT && dir == D_LEFT))
        return;
    _dirrection = dir;
}

std::vector<std::shared_ptr<Arcade::SnakeBody>> Arcade::Snake::getSnake() const
{
    return _snake;
}
