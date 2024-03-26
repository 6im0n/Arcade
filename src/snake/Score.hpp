/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Score
*/

#pragma once

#include <string>

#include "Interfaces/IText.hpp"

class Score : public IText {
    public:
        Score();
        ~Score() = default;

        // setters
        void setFontPath(const std::string &fontPath);
        void setText(const std::string &text);
        void setColor(std::unique_ptr<IColor> color);
        void setPos(std::size_t x, std::size_t y);
        void setSize(std::size_t x);
        void setRotation(float rotation);

        // getters
        std::string getFontPath();
        std::string getText();
        std::shared_ptr<IColor> getColor() const;
        std::vector<std::size_t> getPos() const;
        std::size_t getSize() const;
        float getRotation() const;
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
