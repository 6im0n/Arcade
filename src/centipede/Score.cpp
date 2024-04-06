/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Score
*/

#include "Score.hpp"
#include "classes/Color.hpp"

Arcade::Score::Score()
{
    _pos = {8, 25};
    _size = 25;
    _rotation = 0;
    _color = std::make_shared<Arcade::Color>(255, 255, 255, 255);
    _fontPath = "assets/Roboto-Regular";
    _text = "Score:";
    _score = 0;
}

void Arcade::Score::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Arcade::Score::setText(const std::string &text)
{
    _text = text;
}

void Arcade::Score::setColor(std::unique_ptr<Arcade::IColor> color)
{
    _color = std::move(color);
}

void Arcade::Score::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Score::setSize(std::size_t x)
{
    _size = x;
}

void Arcade::Score::setRotation(float rotation)
{
    _rotation = rotation;
}

std::string Arcade::Score::getFontPath()
{
    return _fontPath;
}

std::string Arcade::Score::getText()
{
    _text = "Score: " + std::to_string(_score);
    return _text;
}

std::shared_ptr<Arcade::IColor> Arcade::Score::getColor() const
{
    return _color;
}

std::vector<std::size_t> Arcade::Score::getPos() const
{
    return _pos;
}

std::size_t Arcade::Score::getSize() const
{
    return _size;
}

float Arcade::Score::getRotation() const
{
    return _rotation;
}

int Arcade::Score::getScore() const
{
    return _score;
}

void Arcade::Score::incrementScore()
{
    _score ++;
}

void Arcade::Score::decrementScore(int value)
{
    _score -= value;
}

void Arcade::Score::resetScore()
{
    _score = 0;
}
