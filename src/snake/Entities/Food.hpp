/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Food
*/

#pragma once

#include "Interfaces/IEntity.hpp"
#include "src/snake/Snake.hpp"

namespace Arcade {
    class Food : public IEntity {
        public:
            Food(Snake snake);
            ~Food() = default;

            //setters
            void setPos(std::size_t x, std::size_t y);
            void setSize(std::size_t x, std::size_t y);
            void setChar(char c);
            void setColor(std::unique_ptr<IColor> color);
            void setPath(const std::string &path);
            void setRotation(float rotation);

            //getters
            std::vector<std::size_t> getPos() const;
            std::vector<std::size_t> getSize() const;
            int getChar() const;
            std::shared_ptr<IColor> getColor() const;
            std::string getPath() const;
            float getRotation() const;

        private:
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            int _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;
    };
}
