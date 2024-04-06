/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Score
*/

#pragma once

#include <string>

#include "Interfaces/IText.hpp"

namespace Arcade {
    class Score : public IText {
        public:
            Score();
            ~Score() override = default;

            // setters
            void setFontPath(const std::string &fontPath) override;
            void setText(const std::string &text) override;
            void setColor(std::unique_ptr<IColor> color) override;
            void setPos(std::size_t x, std::size_t y) override;
            void setSize(std::size_t x) override;
            void setRotation(float rotation) override;

            // getters
            std::string getFontPath() override;
            std::string getText() override;
            std::shared_ptr<IColor> getColor() const override;
            std::vector<std::size_t> getPos() const override;
            std::size_t getSize() const override;
            float getRotation() const override;
            int getScore() const;

            void incrementScore();
            void resetScore();

        private:
            std::string _fontPath;
            std::string _text;
            std::shared_ptr<IColor> _color;
            std::vector<std::size_t> _pos;
            std::size_t _size;
            float _rotation;
            int _score;
    };
}
