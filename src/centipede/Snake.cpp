/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Entities/Wall.hpp"
#include "CentipedeGame.hpp"

#include <stdlib.h>

#include <iostream>

Arcade::Snake::Snake(Direction dir, short size, std::vector<std::size_t> pos, bool headPos, int id)
{
    if (!headPos) {
        if (dir == D_RIGHT) {
            pos[POSX] += (std::size_t)size -1;
        } else if (dir == D_DOWN) {
            pos[POSY] += (std::size_t)size - 1;
        } else if (dir == D_LEFT) {
            pos[POSX] -= (std::size_t)size - 1;
        } else if (dir == D_UP) {
            pos[POSY] -= (std::size_t)size - 1;
        }
    }
    _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY], SNAKE_HEAD_PATH, dir));
    for (short i = 1; i < size - 1; i++) {
        if (dir == D_RIGHT) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] - i, pos[POSY], SNAKE_BODY_PATH, dir));
        } else if (dir == D_DOWN) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] - i, SNAKE_BODY_PATH, dir));
        } else if (dir == D_LEFT) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] + i, pos[POSY], SNAKE_BODY_PATH, dir));
        } else if (dir == D_UP) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] + i, SNAKE_BODY_PATH, dir));
        }
    }
    if (dir == D_RIGHT) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] - size + 1, pos[POSY], SNAKE_TAIL_PATH, dir));
    } else if (dir == D_DOWN) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] - size + 1, SNAKE_TAIL_PATH, dir));
    } else if (dir == D_LEFT) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] + size - 1, pos[POSY], SNAKE_TAIL_PATH, dir));
    } else if (dir == D_UP) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] + size - 1, SNAKE_TAIL_PATH, dir));
    }
    _direction = dir;
    _lastDirection = dir;
    _timer = Timer();
    _timer.start();
    _speed = 0.15;
    _id = id;
}

Arcade::Snake::Snake(Direction dir, short size, std::vector<std::size_t> pos, bool headPos)
{
    if (!headPos) {
        if (dir == D_RIGHT) {
            pos[POSX] += (std::size_t)size -1;
        } else if (dir == D_DOWN) {
            pos[POSY] += (std::size_t)size - 1;
        } else if (dir == D_LEFT) {
            pos[POSX] -= (std::size_t)size - 1;
        } else if (dir == D_UP) {
            pos[POSY] -= (std::size_t)size - 1;
        }
    }
    _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY], SNAKE_HEAD_PATH, dir));
    for (short i = 1; i < size - 1; i++) {
        if (dir == D_RIGHT) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] - i, pos[POSY], SNAKE_BODY_PATH, dir));
        } else if (dir == D_DOWN) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] - i, SNAKE_BODY_PATH, dir));
        } else if (dir == D_LEFT) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] + i, pos[POSY], SNAKE_BODY_PATH, dir));
        } else if (dir == D_UP) {
            _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] + i, SNAKE_BODY_PATH, dir));
        }
    }
    if (dir == D_RIGHT) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] - size + 1, pos[POSY], SNAKE_TAIL_PATH, dir));
    } else if (dir == D_DOWN) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] - size + 1, SNAKE_TAIL_PATH, dir));
    } else if (dir == D_LEFT) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX] + size - 1, pos[POSY], SNAKE_TAIL_PATH, dir));
    } else if (dir == D_UP) {
        _snake.push_back(std::make_shared<SnakeBody>(pos[POSX], pos[POSY] + size - 1, SNAKE_TAIL_PATH, dir));
    }
    _direction = dir;
    _lastDirection = dir;
    _timer = Timer();
    _timer.start();
    _speed = 0.15;
    _id = rand();
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

    SnakeBody *head = _snake.front().get();
    head->setPath(SNAKE_BODY_PATH);
    auto newHead = std::make_shared<SnakeBody>(0, 0, SNAKE_HEAD_PATH, _direction);

    if (_direction == D_LEFT) {
        if (!checkCollision(map, _snake, head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false) {
            if (_lastDirection == D_DOWN) {
                head->setPath(SNAKE_CORNER_PATH);
                head->setDirection(D_LEFT);
                head->setRotation(270);
                _lastDirection = D_LEFT;
            }
            moveSnakePart(newHead.get(), head->getPos()[0] - 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT, 270, SNAKE_HEAD_PATH);
        } else {
            _lastDirection = D_LEFT;
            _direction = D_DOWN;
        }
    }
    if (_direction == D_RIGHT) {
        if (!checkCollision(map, _snake, head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT) == false) {
            if (_lastDirection == D_DOWN) {
                head->setPath(SNAKE_CORNER_PATH);
                head->setDirection(D_RIGHT);
                head->setRotation(0);
                _lastDirection = D_RIGHT;
            }
            moveSnakePart(newHead.get(), head->getPos()[0] + 1 - START_WIDTH, head->getPos()[1] - START_HEIGHT, 90, SNAKE_HEAD_PATH);
        } else {
            _lastDirection = D_RIGHT;
            _direction = D_DOWN;
        }
    }
    if (_direction == D_DOWN) {
        if (head->getPos()[POSY] == GET_POSY_AREA(AREA_GAME_HEIGHT - 1)) {
            return -1;
        }
        if (_lastDirection == D_LEFT) {
            head->setPath(SNAKE_CORNER_PATH);
            head->setDirection(D_DOWN);
            head->setRotation(90);
            _lastDirection = D_DOWN;
            _direction = D_RIGHT;
        } else if (_lastDirection == D_RIGHT){
            head->setPath(SNAKE_CORNER_PATH);
            head->setDirection(D_DOWN);
            head->setRotation(180);
            _lastDirection = D_DOWN;
            _direction = D_LEFT;
        }
        moveSnakePart(newHead.get(), head->getPos()[0] - START_WIDTH, head->getPos()[1] + 1 - START_HEIGHT, 180, SNAKE_HEAD_PATH);
    }

    _snake.pop_back();
    _snake.insert(_snake.begin(), newHead);
    _snake.back()->setPath(SNAKE_TAIL_PATH);
    _snake.back()->updateRotation();
    _timer.reset();
    return 0;
}

void Arcade::Snake::growSnake()
{
    SnakeBody *end = _snake.back().get();
    std::size_t x = end->getPos()[0];
    std::size_t y = end->getPos()[1];
    end->setPath(SNAKE_TAIL_PATH);

    _snake.push_back(std::make_shared<SnakeBody>(x, y, SNAKE_TAIL_PATH, end->getDirection()));
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

Arcade::Direction Arcade::Snake::getDirection() const
{
    return _direction;
}

std::vector<std::shared_ptr<Arcade::SnakeBody>> Arcade::Snake::getSnake() const
{
    return _snake;
}

int Arcade::Snake::getId() const
{
    return _id;
}

bool Arcade::Snake::operator==(const Snake &other) const
{
    return _snake == other._snake;
}

bool Arcade::Snake::operator!=(const Snake &other) const
{
    return _snake != other._snake;
}
