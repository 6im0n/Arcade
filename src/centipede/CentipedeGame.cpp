/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CentipedeGame
*/

#include "CentipedeGame.hpp"
#include "Entities/Wall.hpp"
#include "Entities/Void.hpp"
#include "Entities/VoidRunnable.hpp"
#include "Entities/Bullet.hpp"
#include "includes/Keys.hpp"
#include "includes/Direction.hpp"

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

void generateLineRunnable(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(START_WIDTH, y + START_HEIGHT);
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Arcade::VoidRunnable> void_case = std::make_shared<Arcade::VoidRunnable>(i + START_WIDTH, y + START_HEIGHT);
        line.push_back(void_case);
    }
    std::shared_ptr<Arcade::Wall> wall2 = std::make_shared<Arcade::Wall>(size - 1 + START_WIDTH, y + START_HEIGHT);
    line.push_back(wall2);
}

void generateMap(std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> &map)
{
    for (int i = 0; i < 15; i++) {
        std::vector<std::shared_ptr<Arcade::IEntity>> line;
        map.push_back(line);
    }
    generateWallLine(map[0], 0, 20);
    for (int i = 1; i < 11; i++) {
        generateLine(map[i], i, 20);
    }
    for (int i = 11; i < 14; i++) {
        generateLineRunnable(map[i], i, 20);
    }
    generateWallLine(map[14], 14, 20);
}

Arcade::CentipedeGame::CentipedeGame()
{
    generateMap(_map);
    _score = std::make_shared<Score>();
    _player = std::make_shared<Player>();
    _timer = Timer();
    srand(time(NULL));
}

int Arcade::CentipedeGame::startGame()
{
    _snake = Snake();
    _score.get()->resetScore();
    _timer.reset();
    return 0;
}

int Arcade::CentipedeGame::stopGame()
{
    _entities.clear();
    return 0;
}

int Arcade::CentipedeGame::getScore()
{
    return _score.get()->getScore();
}

int Arcade::CentipedeGame::simulate()
{
    _entities.clear();
    for (auto &line : _map) {
        for (auto &entity : line) {
            _entities.push_back(entity);
        }
    }
    for (auto snakeBody : _snake.getSnake()) {
        _entities.push_back(snakeBody);
    }
    for (auto bullet : _bullets) {
        bullet->moveBullet(_timer);
        _entities.push_back(bullet);
    }
    _entities.push_back(_player);
    if (_snake.moveSnake(_map) == -1)
        return -1;
    return 0;
}

void Arcade::CentipedeGame::catchKeyEvent(int key)
{
    if (key == Arcade::Keys::LEFT) {
        _snake.setDirection(Direction::D_LEFT);
    } else if (key == Arcade::Keys::RIGHT) {
        _snake.setDirection(Direction::D_RIGHT);
    } else if (key == Arcade::Keys::UP) {
        _snake.setDirection(Direction::D_UP);
    } else if (key == Arcade::Keys::DOWN) {
        _snake.setDirection(Direction::D_DOWN);
    } else if (key == Arcade::Keys::SPACE) {
        _player.get()->shoot(_bullets, _timer);
    }
}

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::CentipedeGame::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::CentipedeGame::getTexts()
{
    _texts.clear();
    _texts.push_back(_score);
    return _texts;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::CentipedeGame::getSounds()
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
    Arcade::CentipedeGame *loadGameInstance()
    {
        return new Arcade::CentipedeGame();
    }
}
