/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Void
*/

#pragma once

#include "Interfaces/IEntity.hpp"

class Void : public IEntity {
    public:
        Void(std::size_t x, std::size_t y);
        ~Void();

        //setters
        void setPos(std::size_t x, std::size_t y);
        void setSize(std::size_t x, std::size_t y);
        void setChar(char c);
        void setColor(std::unique_ptr<IColor> color);
        void setPath(const std::string &path);
        void setRotation(float rotation);

        //getters
        std::vector<std::size_t> getPos();
        std::vector<std::size_t> getSize();
        int getChar();
        std::shared_ptr<IColor> getColor();
        std::string getPath();
        float getRotation();

    private:
        std::vector<std::size_t> _pos;
        std::vector<std::size_t> _size;
        int _char;
        std::shared_ptr<IColor> _color;
        std::string _path;
        float _rotation;
};
