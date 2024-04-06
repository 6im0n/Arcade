/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Text::Text(std::string text, std::vector<std::size_t> pos, std::vector<std::size_t> size, char c)
{
    _text = text;
    _pos = pos;
    _size = size;
    _c = c;
}

void Arcade::Text::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Arcade::Text::setText(const std::string &text)
{
    _text = text;
}

void Arcade::Text::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Text::setPos(std::size_t x, std::size_t y)
{
    _pos[0] = x;
    _pos[1] = y;
}

void Arcade::Text::setSize(std::size_t x)
{
    _size[0] = x;
}

void Arcade::Text::setRotation(float rotation)
{
    _rotation = rotation;
}

std::string Arcade::Text::getFontPath()
{
    return _fontPath;
}

std::string Arcade::Text::getText()
{
    return _text;
}

std::shared_ptr<Arcade::IColor> Arcade::Text::getColor() const
{
    return this->_color;
}

std::vector<std::size_t> Arcade::Text::getPos() const
{
    return _pos;
}

std::size_t Arcade::Text::getSize() const
{
    return _size[0];
}

float Arcade::Text::getRotation() const
{
    return _rotation;
}
