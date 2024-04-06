/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman.cpp
*/

#include "pacman.hpp"

Arcade::Pacman::Pacman()
{
}

int Arcade::Pacman::startGame()
{
    return 0;
}

int Arcade::Pacman::stopGame()
{
    return 0;
}

int Arcade::Pacman::getScore()
{
    return 0;
}

int Arcade::Pacman::simulate()
{
    return 0;
}

void Arcade::Pacman::catchKeyEvent(int key)
{
    (void)key;
}

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::Pacman::getEntities()
{
    return std::vector<std::shared_ptr<Arcade::IEntity>>();
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::Pacman::getTexts()
{
    return std::vector<std::shared_ptr<Arcade::IText>>();
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::Pacman::getSounds()
{
    return std::vector<std::shared_ptr<Arcade::ISound>>();
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
    Arcade::Pacman *loadGameInstance()
    {
        return new Arcade::Pacman();
    }
}
