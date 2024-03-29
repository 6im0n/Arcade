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
#include "includes/Keys.hpp"

void generateWallLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(wall);
    }
}

void generateLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(START_WIDTH, y + START_HEIGHT);
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Arcade::Void> void_case = std::make_shared<Arcade::Void>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(void_case);
    }
    std::shared_ptr<Arcade::Wall> wall2 = std::make_shared<Arcade::Wall>(size - 1 + START_WIDTH, y + START_HEIGHT);
    line.push_back(wall2);
}

Arcade::SnakeGame::SnakeGame()
{
    for (int i = 0; i < 15; i++) {
        std::vector<std::shared_ptr<Arcade::IEntity>> line;
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
    _score = std::make_shared<Score>();
    srand(time(NULL));
}

int Arcade::SnakeGame::startGame()
{
    _snake = Snake();
    auto new_food = std::make_shared<Food>(_snake);
    _foods.push_back(new_food);
    _score.get()->resetScore();
    return 0;
}

int Arcade::SnakeGame::stopGame()
{
    _foods.clear();
    _entities.clear();
    return 0;
}

int Arcade::SnakeGame::getScore()
{
    return _score.get()->getScore();
}

int Arcade::SnakeGame::simulate()
{
    _entities.clear();
    for (auto &line : _map) {
        for (auto &entity : line) {
            _entities.push_back(entity);
        }
    }

    auto head = _snake.getSnake().front();
    for (std::size_t i = 0; i < _foods.size(); i++) {
        std::vector<std::size_t> pos = _foods[i].get()->getPos();
        if (head->getPos()[0] == pos[0] && head->getPos()[1] == pos[1]) {
            _score.get()->incrementScore();
            _snake.growSnake();

            _foods.erase(_foods.begin() + i);
            auto new_food = std::make_shared<Food>(_snake);
            _foods.push_back(new_food);
        }
    }
    for (auto &food : _foods) {
        _entities.push_back(food);
    }
    for (auto snakeBody : _snake.getSnake()) {
        _entities.push_back(snakeBody);
    }
    if (_snake.moveSnake(_map) == -1)
        return -1;
    return 0;
}

void Arcade::SnakeGame::catchKeyEvent(int key)
{
    if (key == Arcade::Keys::LEFT) {
        _snake.setDirection(Direction::D_LEFT);
    } else if (key == Arcade::Keys::RIGHT) {
        _snake.setDirection(Direction::D_RIGHT);
    } else if (key == Arcade::Keys::UP) {
        _snake.setDirection(Direction::D_UP);
    } else if (key == Arcade::Keys::DOWN) {
        _snake.setDirection(Direction::D_DOWN);
    }
}

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::SnakeGame::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::SnakeGame::getTexts()
{
    _texts.clear();
    _texts.push_back(_score);
    return _texts;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::SnakeGame::getSounds()
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
    Arcade::SnakeGame *loadGameInstance()
    {
        return new Arcade::SnakeGame();
    }
}
