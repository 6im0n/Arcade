/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "sdl.hpp"

Arcade::Sdl::Sdl()
{
}

Arcade::Sdl::~Sdl()
{
}

bool Arcade::Sdl::isWindowOpen() const
{
    return false;
}

void Arcade::Sdl::closeWindow()
{
}

void Arcade::Sdl::clearWindow()
{
}

int Arcade::Sdl::getKeyEvent()
{
    return 0;
}

void Arcade::Sdl::displayWindow()
{
}

void Arcade::Sdl::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    (void)entities;
}

void Arcade::Sdl::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    (void)texts;
}

void Arcade::Sdl::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void)sounds;
}

extern "C"
{
    __attribute__((constructor))
    void constructor()
    {
    }
    __attribute__((destructor))
    void destructor()
    {
    }

    Arcade::IGraphic *loadGraphicInstance()
    {
        return new Arcade::Sdl();
    }
}