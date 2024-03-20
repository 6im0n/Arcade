/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"
#include "Wall.hpp"
#include "Void.hpp"

void generateWallLine(std::vector<std::shared_ptr<IEntity>> &_entities, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Wall> wall = std::make_shared<Wall>(i, y);
        _entities.push_back(wall);
    }
}

void generateLine(std::vector<std::shared_ptr<IEntity>> &_entities, int y, int size)
{
    std::shared_ptr<Wall> wall = std::make_shared<Wall>(0, y);
    _entities.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Void> void_case = std::make_shared<Void>(i, y);
        _entities.push_back(void_case);
    }
    std::shared_ptr<Wall> wall2 = std::make_shared<Wall>(size - 1, y);
    _entities.push_back(wall2);
}

Snake::Snake()
{
    generateWallLine(_entities, 0, 20);
    for (int i = 1; i < 15; i++) {
        generateLine(_entities, i, 20);
    }
    generateWallLine(_entities, 15, 20);
}

Snake::~Snake()
{
}

void Snake::startGame()
{
}

void Snake::stopGame()
{
}

int Snake::getScore()
{
    return _score;
}

void Snake::simulate()
{
}

void Snake::catchKeyEvent(int key)
{
    (void)key;
}

std::vector<std::shared_ptr<IEntity>> Snake::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<IText>> Snake::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<ISound>> Snake::getSounds()
{
    return _sounds;
}
