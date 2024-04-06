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
            ~Text() override = default;

            void setFontPath(const std::string &fontPath) override;
            void setText(const std::string &text) override;
            void setColor(std::unique_ptr<IColor> color) override;
            void setPos(std::size_t x, std::size_t y) override;
            void setSize(std::size_t x) override;
            void setRotation(float rotation) override;

            //getters
            std::string getFontPath() override;
            std::string getText() override;
            std::shared_ptr<IColor> getColor() const override;
            std::vector<std::size_t> getPos() const override;
            std::size_t getSize() const override;
            float getRotation() const override;
        private:
            std::string _text;
            std::vector<std::size_t> _pos;
            std::vector<std::size_t> _size;
            std::shared_ptr<IColor> _color;
            std::string _fontPath;
            float _rotation;
            char _c;
    };
}
