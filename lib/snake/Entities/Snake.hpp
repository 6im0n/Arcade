/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include "Interfaces/IEntity.hpp"
#include <lib/snake/Entities/SnakeBody.hpp>

enum Direction {
    LEFT,
    DOWN,
    RIGHT,
    UP
};

class Snake {
    public:
        Snake();
        ~Snake();

        void placeSnake(std::vector<std::shared_ptr<IEntity>>) const;
        void moveSnake();
        void growSnake();
        void setDirection(bool left);

    protected:
    private:
        std::vector<std::shared_ptr<SnakeBody>> _snake;
        Direction _dir;
};
