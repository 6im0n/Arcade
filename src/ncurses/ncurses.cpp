/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"
#include "includes/keys.hpp"
#include <memory>
#include <iostream>

int init(void)
{
    return 0;
}

Arcade::Ncurses::Ncurses()
{
    std::cout << "Ncurses constructor" << std::endl;
}

Arcade::Ncurses::~Ncurses()
{
    std::cout << "Ncurses destructor" << std::endl;
}

bool Arcade::Ncurses::isWindowOpen() const
{
    std::cout << "Ncurses isWindowOpen" << std::endl;
    return false;
}

void Arcade::Ncurses::closeWindow()
{
    std::cout << "Ncurses closeWindow" << std::endl;
}

void Arcade::Ncurses::clearWindow()
{
    std::cout << "Ncurses clearWindow" << std::endl;
}

int Arcade::Ncurses::getKeyEvent()
{
    std::cout << "Ncurses getKeyEvent" << std::endl;
    return Keys::A;
}

void Arcade::Ncurses::displayWindow()
{
    std::cout << "Ncurses displayWindow" << std::endl;
}

void Arcade::Ncurses::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    std::cout << "Ncurses displayEntities" << std::endl;
    (void)entities;
}

void Arcade::Ncurses::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    std::cout << "Ncurses displayText" << std::endl;
    (void)texts;
}

void Arcade::Ncurses::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    std::cout << "Ncurses playSound" << std::endl;
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
    Arcade::Ncurses *loadGraphicInstance()
    {
        return new Arcade::Ncurses();
    }
}
