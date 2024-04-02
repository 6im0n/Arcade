/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text
*/

#pragma once

#include "Interfaces/IText.hpp"
#include "Color.hpp"

namespace Arcade {
    class Text : public IText {
        public:
            Text(std::string text, std::vector<std::size_t> pos, std::vector<std::size_t> size, char c);
            ~Text() = default;

            void setFontPath(const std::string &fontPath);
            void setText(const std::string &text);
            void setColor(std::unique_ptr<IColor> color);
            void setPos(std::size_t x, std::size_t y);
            void setSize(std::size_t x);
            void setRotation(float rotation);

            //getters
            std::string getFontPath() const;
            std::string getText() const;
            std::shared_ptr<IColor> getColor() const;
            std::vector<std::size_t> getPos() const;
            std::size_t getSize() const;
            float getRotation() const;
        private:
            std::string _text;
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            std::unique_ptr<IColor> _color;
            std::string _fontPath;
            float _rotation;
            char _c;
    };
}
