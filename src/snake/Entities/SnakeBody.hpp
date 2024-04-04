/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeBody
*/

#pragma once

#include "Interfaces/IEntity.hpp"

#include "src/snake/direction.hpp"

namespace Arcade {
    class SnakeBody : public IEntity {
        public:
            SnakeBody(std::size_t x, std::size_t y, std::string path, Direction dir);
            ~SnakeBody() = default;

            //setters
            void setPos(std::size_t x, std::size_t y);
            void setSize(std::size_t x, std::size_t y);
            void setChar(char c);
            void setColor(std::unique_ptr<IColor> color);
            void setPath(const std::string &path);
            void setRotation(float rotation);
            void setDirection(Direction dir);
            void updateRotation();

            //getters
            std::vector<std::size_t> getPos() const;
            std::vector<std::size_t> getSize() const;
            int getChar() const;
            std::shared_ptr<IColor> getColor() const;
            std::string getPath() const;
            float getRotation() const;
            Direction getDirection() const;

        private:
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            int _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;
            Direction _direction;
    };
}
