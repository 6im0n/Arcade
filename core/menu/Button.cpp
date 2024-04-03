/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#include "Button.hpp"
#include <iostream>
#include "../Core.hpp"

Arcade::Button::Button(std::string label, std::vector<std::size_t> pos, std::vector<std::size_t> size, char c, std::string lib, std::string path, float rotation) : _label(label)
{
    _pos = pos;
    _size = size;
    _char = c;
    _color = std::make_shared<Color>(255, 255, 255, 0);
    _lib = lib;
    _path = path;
    _rotation = rotation;
    _nextButton = nullptr;
    _prevButton = nullptr;
    _upButton = nullptr;
    _downButton = nullptr;
    _destroy = false;
}

Arcade::Button::~Button()
{
    if (_destroy)
        return;
    _destroy = true;
    while (_nextButton != nullptr && _nextButton->_destroy == false) {
        if (_nextButton == nullptr || _nextButton->_destroy == true)
            break;
        delete _nextButton;
    }
}

void Arcade::Button::setPos(std::size_t x, std::size_t y)
{
    _pos = {x, y};
}

void Arcade::Button::setSize(std::size_t x, std::size_t y)
{
    _size = {x, y};
}

void Arcade::Button::setChar(char c)
{
    _char = c;
}

void Arcade::Button::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Button::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Button::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Button::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Button::getSize() const
{
    return _size;
}

int Arcade::Button::getChar() const
{
    return _char;
}

std::shared_ptr<Arcade::IColor> Arcade::Button::getColor() const
{
    return _color;
}

std::string Arcade::Button::getPath() const
{
    return _path;
}

float Arcade::Button::getRotation() const
{
    return _rotation;
}

std::string Arcade::Button::getLabel() const
{
    return _label;
}

void Arcade::Button::setNextButton(Button *nextButton)
{
    if (_nextButton == nextButton || _nextButton != nullptr)
        return;
    _nextButton = nextButton;
    if (nextButton == nullptr)
        return;
    nextButton->setPrevButton(this);
}

void Arcade::Button::setPrevButton(Button *prevButton)
{
    if (_prevButton == prevButton || _prevButton != nullptr)
        return;
    _prevButton = prevButton;
    prevButton->setNextButton(this);
}

void Arcade::Button::setUpButton(Button *upButton)
{
    if (_upButton == upButton || _upButton != nullptr)
        return;
    _upButton = upButton;
    upButton->setDownButton(this);
}

void Arcade::Button::setDownButton(Button *downButton)
{
    if (_downButton == downButton || _downButton != nullptr)
        return;
    _downButton = downButton;
    downButton->setUpButton(this);
}

Arcade::Button *Arcade::Button::getNextButton() const
{
    return _nextButton;
}

Arcade::Button *Arcade::Button::getPrevButton() const
{
    return _prevButton;
}

Arcade::Button *Arcade::Button::getUpButton() const
{
    return _upButton;
}

Arcade::Button *Arcade::Button::getDownButton() const
{
    return _downButton;
}

std::string Arcade::Button::getLib() const
{
    return _lib;
}
