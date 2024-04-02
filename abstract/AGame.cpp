/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#include "AGame.hpp"

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
