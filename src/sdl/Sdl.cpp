/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "Sdl.hpp"

Arcade::Sdl::Sdl()
{
}

Arcade::Sdl::~Sdl()
{
}

bool Arcade::Sdl::isWindowOpen() const
{
    return true;
}

void Arcade::Sdl::closeWindow()
{
}

void Arcade::Sdl::clearWindow()
{
}

int Arcade::Sdl::getKeyEvent()
{
    return -1;
}

void Arcade::Sdl::displayWindow()
{
    SDL_RenderPresent(this->_renderer);
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

std::pair<int, int> Arcade::Sdl::getMousePosition()
{
    return std::make_pair(0, 0);
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
    Arcade::Sdl *loadGraphicInstance()
    {
        return new Arcade::Sdl();
    }
}
