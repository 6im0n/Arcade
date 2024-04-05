/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"
#include "includes/Keys.hpp"
#include <memory>
#include <iostream>

int init(void)
{
    return 0;
}

Arcade::Ncurses::Ncurses()
{
}

bool Arcade::Ncurses::isWindowOpen() const
{
    return false;
}

void Arcade::Ncurses::closeWindow()
{
}

void Arcade::Ncurses::clearWindow()
{
}

int Arcade::Ncurses::getKeyEvent()
{
    return Keys::A;
}

void Arcade::Ncurses::displayWindow()
{
}

void Arcade::Ncurses::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    (void)entities;
}

void Arcade::Ncurses::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    (void)texts;
}

void Arcade::Ncurses::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void)sounds;
}

std::pair<int, int> Arcade::Ncurses::getMousePosition()
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
    Arcade::Ncurses *loadGraphicInstance()
    {
        return new Arcade::Ncurses();
    }
}
