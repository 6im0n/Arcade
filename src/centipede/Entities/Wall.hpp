/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Wall
*/

#pragma once

#include "Interfaces/IEntity.hpp"

namespace Arcade {
    class Wall : public IEntity {
        public:
            Wall(std::size_t x, std::size_t y);
            ~Wall() = default;

            //setters
            void setPos(std::size_t x, std::size_t y);
            void setSize(std::size_t x, std::size_t y);
            void setChar(char c);
            void setColor(std::unique_ptr<IColor> color);
            void setPath(const std::string &path);
            void setRotation(float rotation);
            void hit();

            //getters
            std::vector<std::size_t> getPos() const;
            std::vector<std::size_t> getSize() const;
            int getChar() const;
            std::shared_ptr<IColor> getColor() const;
            std::string getPath() const;
            float getRotation() const;
            short getLife() const;

        private:
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            int _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;
            short _life;
    };
}