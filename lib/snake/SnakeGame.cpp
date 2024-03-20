/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#include "SnakeGame.hpp"
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

SnakeGame::SnakeGame()
{
    generateWallLine(_entities, 0, 20);
    for (int i = 1; i < 15; i++) {
        generateLine(_entities, i, 20);
    }
    generateWallLine(_entities, 15, 20);
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::startGame()
{
}

void SnakeGame::stopGame()
{
}

int SnakeGame::getScore()
{
    return _score;
}

void SnakeGame::simulate()
{
}

void SnakeGame::catchKeyEvent(int key)
{
    (void)key;
}

std::vector<std::shared_ptr<IEntity>> SnakeGame::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<IText>> SnakeGame::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<ISound>> SnakeGame::getSounds()
{
    return _sounds;
}
