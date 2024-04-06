/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Void
*/

#pragma once

#include "Interfaces/IEntity.hpp"

namespace Arcade {
    class Void : public IEntity {
        public:
            Void(std::size_t x, std::size_t y);
            ~Void() override = default;

            //setters
            void setPos(std::size_t x, std::size_t y) override;
            void setSize(std::size_t x, std::size_t y) override;
            void setChar(char c) override;
            void setColor(std::unique_ptr<IColor> color) override;
            void setPath(const std::string &path) override;
            void setRotation(float rotation) override;

            //getter overrides
            std::vector<std::size_t> getPos() const override;
            std::vector<std::size_t> getSize() const override;
            int getChar() const override;
            std::shared_ptr<IColor> getColor() const override;
            std::string getPath() const override;
            float getRotation() const override;

        private:
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            int _char;
            std::shared_ptr<IColor> _color;
            std::string _path;
            float _rotation;
    };
}