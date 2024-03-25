/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#include "AGame.hpp"

std::vector<std::shared_ptr<IEntity>> AGame::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<IText>> AGame::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<ISound>> AGame::getSounds()
{
    return _sounds;
}

int AGame::getScore()
{
    return score;
}
