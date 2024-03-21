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
    D_LEFT,
    D_DOWN,
    D_RIGHT,
    D_UP
};

class Snake {
    public:
        Snake();
        ~Snake();

        void placeSnake(std::vector<std::shared_ptr<IEntity>>) const;
        void moveSnake();
        void growSnake();
        void setDirection(bool left);
        std::vector<std::shared_ptr<SnakeBody>> getSnake() const;

    protected:
    private:
        std::vector<std::shared_ptr<SnakeBody>> _snake;
        Direction _dir;
};
