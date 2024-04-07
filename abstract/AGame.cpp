/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#include "AGame.hpp"

void Arcade::AGame::catchMousePosition(int x, int y)
{
    (void)x;
    (void)y;
}

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::AGame::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::AGame::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::AGame::getSounds()
{
    return _sounds;
}

int Arcade::AGame::getScore()
{
    return score;
}

void Arcade::AGame::setUserName(const std::string &name)
{
    _username = name;
}

std::string Arcade::AGame::getUserName()
{
    return _username;
}
