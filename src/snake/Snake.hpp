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
#include "includes/Direction.hpp"

namespace Arcade {
    class Snake {
        public:
            Snake();
            ~Snake() = default;

            int moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map);
            void growSnake();
            void setDirection(Arcade::Direction dir);
            std::vector<std::shared_ptr<SnakeBody>> getSnake() const;

        protected:
        private:
            std::vector<std::shared_ptr<SnakeBody>> _snake;
            Arcade::Direction _direction;
            Arcade::Direction _lastDirection;
            Timer _timer;
            float _speed;
    };
}
