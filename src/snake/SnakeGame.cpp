/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#include "SnakeGame.hpp"
#include "Entities/Wall.hpp"
#include "Entities/Void.hpp"
#include "Entities/Food.hpp"
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
    for (int i = 0; i < 15; i++) {
        std::vector<std::shared_ptr<IEntity>> line;
        _map.push_back(line);
    }
    generateWallLine(_map[0], 0, 20);
    for (int i = 1; i < 14; i++) {
        generateLine(_map[i], i, 20);
    }
    generateWallLine(_map[14], 14, 20);
    for (auto &line : _map) {
        for (auto &entity : line) {
            _entities.push_back(entity);
        }
    }
}

SnakeGame::~SnakeGame()
{
}

int SnakeGame::startGame()
{
    _snake = Snake();
    auto new_food = std::make_shared<Food>(_snake);
    _foods.push_back(new_food);
    _score = 0;
    return 0;
}

int SnakeGame::stopGame()
{
    return 0;
}

int SnakeGame::getScore()
{
    return _score;
}

int SnakeGame::simulate()
{
    _entities.clear();
    for (auto &line : _map) {
        for (auto &entity : line) {
            _entities.push_back(entity);
        }
    }
    if (_snake.moveSnake(_map) == -1)
        return -1;

    auto head = _snake.getSnake().front();
    for (auto &food : _foods) {
        std::vector<std::size_t> pos = food.get()->getPos();
        if (head->getPos()[0] == pos[0] && head->getPos()[1] == pos[1]) {
            _score += 1;
            _snake.growSnake();

            delete &food;
            auto new_food = std::make_shared<Food>(_snake);
            _foods.push_back(new_food);
        }
        _entities.push_back(food);
    }
    for (auto snakeBody : _snake.getSnake()) {
        _entities.push_back(snakeBody);
    }
    return 0;
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
    std::unique_ptr<SnakeGame> loadGameInstance()
    {
        return std::make_unique<SnakeGame>();
    }
}
