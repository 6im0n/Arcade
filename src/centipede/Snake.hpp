/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <chrono>

#include "src/centipede/Entities/SnakeBody.hpp"
#include "Interfaces/IEntity.hpp"
#include "classes/Timer.hpp"
#include "includes/Direction.hpp"

namespace Arcade {
    class   Snake {
        public:
            Snake();
            Snake(Direction dir, short size, std::vector<std::size_t> pos, bool headPos, int id);
            Snake(Direction dir, short size, std::vector<std::size_t> pos, bool headPos);
            ~Snake() = default;

            int moveSnake(std::vector<std::vector<std::shared_ptr<IEntity>>> map);
            void growSnake();
            void setDirection(Direction dir);
            Direction getDirection() const;
            std::vector<std::shared_ptr<SnakeBody>> getSnake() const;
            int getId() const;

            bool operator==(const Snake& other) const;
            bool operator!=(const Snake& other) const;

        protected:
        private:
            std::vector<std::shared_ptr<SnakeBody>> _snake;
            Direction _direction;
            Direction _lastDirection;
            Timer _timer;
            float _speed;
            int _id;
    };
}
