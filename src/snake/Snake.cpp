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
    _snake.push_back(std::make_shared<SnakeBody>(14, 17, SNAKE_HEAD_PATH));
    _snake.push_back(std::make_shared<SnakeBody>(14, 18, SNAKE_BODY_PATH));
    _snake.push_back(std::make_shared<SnakeBody>(14, 19, SNAKE_BODY_PATH));
    _snake.push_back(std::make_shared<SnakeBody>(14, 20, SNAKE_TAIL_PATH));
    _direction = D_RIGHT;
    _lastDirection = D_RIGHT;
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

void moveSnakePart(Arcade::SnakeBody *part, std::size_t x, std::size_t y, std::size_t rotation, std::string path)
{
    part->setPos(x + START_WIDTH, y + START_HEIGHT);
    part->setRotation(rotation);
    part->setPath(path);
}

int Arcade::Snake::moveSnake(std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map)
{
    if (_timer.getElapsedTime() < _speed)
        return 0;

    SnakeBody *head = _snake[0].get();
    head->setPath(SNAKE_BODY_PATH);
    auto newHead = std::make_shared<SnakeBody>(0, 0, SNAKE_HEAD_PATH);

    if (_direction == D_UP) {
        if (checkCollision(map, _snake, head->getPos()[0] - START_WIDTH, head->getPos()[1] - 1 - START_HEIGHT) == false)
            return -1;
        if (_lastDirection == D_LEFT) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(0);
            _lastDirection = D_UP;
        } else if (_lastDirection == D_RIGHT) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(270);
            _lastDirection = D_UP;
        }
        moveSnakePart(newHead.get(), head->getPos()[0] - START_WIDTH, head->getPos()[1] - 1 - START_HEIGHT, 0, SNAKE_HEAD_PATH);
    }
    if (_direction == D_DOWN) {
        if (checkCollision(map, _snake, head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT) == false)
            return -1;
        if (_lastDirection == D_LEFT) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(90);
            _lastDirection = D_DOWN;
        } else if (_lastDirection == D_RIGHT){
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(180);
            _lastDirection = D_DOWN;
        }
        moveSnakePart(newHead.get(), head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT, 180, SNAKE_HEAD_PATH);
    }
    if (_direction == D_LEFT) {
        if (checkCollision(map, _snake, head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false)
            return -1;
        if (_lastDirection == D_UP) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(180);
            _lastDirection = D_LEFT;
        } else if (_lastDirection == D_DOWN) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(270);
            _lastDirection = D_LEFT;
        }
        moveSnakePart(newHead.get(), head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT, 270, SNAKE_HEAD_PATH);
    }
    if (_direction == D_RIGHT) {
        if (checkCollision(map, _snake, head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false)
            return -1;
        if (_lastDirection == D_UP) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(90);
            _lastDirection = D_RIGHT;
        } else if (_lastDirection == D_DOWN) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setRotation(0);
            _lastDirection = D_RIGHT;
        }
        moveSnakePart(newHead.get(), head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT, 90, SNAKE_HEAD_PATH);
    }

    _snake.pop_back();
    _snake.insert(_snake.begin(), newHead);
    _snake.back()->setPath(SNAKE_TAIL_PATH);
    _timer.reset();
    return 0;
}

void Arcade::Snake::growSnake()
{
    SnakeBody *end = _snake.back().get();
    std::size_t x = end->getPos()[0];
    std::size_t y = end->getPos()[1];
    end->setPath(SNAKE_TAIL_PATH);

    _snake.push_back(std::make_shared<SnakeBody>(x, y, SNAKE_TAIL_PATH));
}

void Arcade::Snake::setDirection(Direction dir)
{
    if ((_direction == D_UP && dir == D_DOWN) ||
        (_direction == D_DOWN && dir == D_UP) ||
        (_direction == D_LEFT && dir == D_RIGHT) ||
        (_direction == D_RIGHT && dir == D_LEFT))
        return;
    _direction = dir;
}

std::vector<std::shared_ptr<Arcade::SnakeBody>> Arcade::Snake::getSnake() const
{
    return _snake;
}
