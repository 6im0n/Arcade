/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#include "lib/snake/SnakeGame.hpp"
#include "lib/snake/Entities/Wall.hpp"
#include "lib/snake/Entities/Void.hpp"
#include "includes/keys.hpp"

void generateWallLine(std::vector<std::shared_ptr<IEntity>> &line, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Wall> wall = std::make_shared<Wall>(i, y);
        line.push_back(wall);
    }
}

void generateLine(std::vector<std::shared_ptr<IEntity>> &line, int y, int size)
{
    std::shared_ptr<Wall> wall = std::make_shared<Wall>(0, y);
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Void> void_case = std::make_shared<Void>(i, y);
        line.push_back(void_case);
    }
    std::shared_ptr<Wall> wall2 = std::make_shared<Wall>(size - 1, y);
    line.push_back(wall2);
}

SnakeGame::SnakeGame()
{
    generateWallLine(_map[0], 0, 20);
    for (int i = 1; i < 14; i++) {
        generateLine(_map[i], i, 20);
    }
    generateWallLine(_map[14], 14, 20);
    _score = 0;
    _snake = Snake();
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
    if (key == Arcade::Keys::LEFT) {
        _snake.setDirection(true);
    } else if (key == Arcade::Keys::RIGHT) {
        _snake.setDirection(false);
    }
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
