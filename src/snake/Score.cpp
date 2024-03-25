/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Score
*/

#include "Score.hpp"
#include "classes/Color.hpp"

Score::Score()
{
    _pos = {8, 25};
    _size = 25;
    _rotation = 0;
    _color = std::make_shared<Color>(255, 255, 255, 255);
    _fontPath = "assets/Roboto-Regular";
    _text = "Score:";
    _score = 0;
}

void Score::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Score::setText(const std::string &text)
{
    _text = text;
}

void Score::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Score::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Score::setSize(std::size_t x)
{
    _size = x;
}

void Score::setRotation(float rotation)
{
    _rotation = rotation;
}

std::string Score::getFontPath()
{
    return _fontPath;
}

std::string Score::getText()
{
    _text = "Score: " + std::to_string(_score);
    return _text;
}

std::shared_ptr<IColor> Score::getColor() const
{
    return _color;
}

std::vector<std::size_t> Score::getPos() const
{
    return _pos;
}

std::size_t Score::getSize() const
{
    return _size;
}

float Score::getRotation() const
{
    return _rotation;
}

int Score::getScore() const
{
    return _score;
}

void Score::incrementScore()
{
    _score ++;
}

void Score::resetScore()
{
    _score = 0;
}
