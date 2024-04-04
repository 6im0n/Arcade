/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Bullet
*/

#pragma once

#include "Interfaces/IEntity.hpp"
#include "classes/Timer.hpp"

#define BULLET_SPEED 0.1

namespace Arcade {
    class Bullet : public IEntity {
        public:
            Bullet(std::size_t x, std::size_t y, float time);
            ~Bullet() = default;

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

            void moveBullet(Timer &timer);

        private:
            float _lastTime;
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            int _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;
    };
}
