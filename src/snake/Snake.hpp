/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <chrono>

#include "src/snake/Entities/SnakeBody.hpp"
#include "Interfaces/IEntity.hpp"
#include "classes/Timer.hpp"

enum Direction {
    D_LEFT,
    D_DOWN,
    D_RIGHT,
    D_UP
};

class Snake {
    public:
        Snake();
        ~Snake();

        int moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map);
        void growSnake();
        void setDirection(Direction dir);
        std::vector<std::shared_ptr<SnakeBody>> getSnake() const;

    protected:
    private:
        std::vector<std::shared_ptr<SnakeBody>> _snake;
        Direction _dir;
        Timer _timer;
        float _speed;
};
