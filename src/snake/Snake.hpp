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

namespace Arcade {
    enum Direction {
        D_LEFT,
        D_DOWN,
        D_RIGHT,
        D_UP
    };

    class Snake {
        public:
            Snake();
            ~Snake() = default;

            int moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map);
            void growSnake();
            void setDirection(Direction dir);
            std::vector<std::shared_ptr<SnakeBody>> getSnake() const;

        protected:
        private:
            std::vector<std::shared_ptr<SnakeBody>> _snake;
            Direction _dirrection;
            Timer _timer;
            float _speed;
    };
}
