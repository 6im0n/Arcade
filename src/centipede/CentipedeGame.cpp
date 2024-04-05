/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CentipedeGame
*/

#include "CentipedeGame.hpp"
#include "Entities/Wall.hpp"
#include "Entities/Void.hpp"
#include "Entities/Bullet.hpp"
#include "includes/Keys.hpp"
#include "includes/Direction.hpp"

#include <algorithm>

void generateWallLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    for (int i = 0; i < size; i++) {
        std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(GET_POSXY_AREA(i, y));
        line.push_back(wall);
    }
}

void generateLine(std::vector<std::shared_ptr<Arcade::IEntity>> &line, int y, int size)
{
    std::shared_ptr<Arcade::Wall> wall = std::make_shared<Arcade::Wall>(GET_POSXY_AREA(0, y));
    line.push_back(wall);
    for (int i = 1; i < size - 1; i++) {
        std::shared_ptr<Arcade::Void> void_case = std::make_shared<Arcade::Void>(GET_POSXY_AREA(i, y));
        line.push_back(void_case);
    }
    std::shared_ptr<Arcade::Wall> wall2 = std::make_shared<Arcade::Wall>(GET_POSXY_AREA(size - 1, y));
    line.push_back(wall2);
}

void generateMap(std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> &map)
{
    for (int i = 0; i < AREA_GAME_HEIGHT; i++) {
        std::vector<std::shared_ptr<Arcade::IEntity>> line;
        map.push_back(line);
    }
    generateWallLine(map[0], 0, AREA_GAME_WIDTH);
    for (int i = 1; i < AREA_GAME_HEIGHT; i++) {
        generateLine(map[i], i, AREA_GAME_WIDTH);
    }
    generateWallLine(map[AREA_GAME_HEIGHT - 1], AREA_GAME_HEIGHT, AREA_GAME_WIDTH);
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
    _snakes.push_back(Snake(D_RIGHT, 4, {GET_POSXY_AREA(5, 1)}, true));
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
    for (std::size_t i = 0; i < _bullets.size(); i++) {
        _entities.push_back(_bullets[i]);
        auto resultMove = _bullets[i]->moveBullet(_timer.getElapsedTime(), _snakes);
        if (resultMove[0] == 2) {
            killSnake(_snakes[resultMove[3]], _bullets[i]->getPos());
            i--;
        }
        if (resultMove[0] == 1 || resultMove[0] == 2) {
            _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
            i--;
        }
    }
    for (auto &snake : _snakes) {snake.moveSnake(_map);
        for (auto snakeBody : snake.getSnake()) {
            _entities.push_back(snakeBody);
        }
    }
    _entities.push_back(_player);
    return 0;
}

void Arcade::CentipedeGame::killSnake(Snake snakeKilled, std::vector<std::size_t> pos)
{
    for (std::size_t i = 0; i < _snakes.size(); i++) {
        if (_snakes[i] == snakeKilled) {
            _snakes.erase(_snakes.begin() + i);
            _score.get()->incrementScore();
            break;
        }
    }
    _map[pos[POSY] - START_HEIGHT][pos[POSX] - START_WIDTH] = std::make_shared<Arcade::Wall>(pos[POSX], pos[POSY]);
    _snakes.push_back(Snake(D_RIGHT, 4, {pos[POSX], pos[POSY]}, true));
    _snakes.push_back(Snake(D_LEFT, 4, {pos[POSX], pos[POSY]}, false));
}

void Arcade::CentipedeGame::catchKeyEvent(int key)
{
    if (key == Arcade::Keys::LEFT) {
        _player.get()->move(Direction::D_LEFT);
    } else if (key == Arcade::Keys::RIGHT) {
        _player.get()->move(Direction::D_RIGHT);
    } else if (key == Arcade::Keys::UP) {
        _player.get()->move(Direction::D_UP);
    } else if (key == Arcade::Keys::DOWN) {
        _player.get()->move(Direction::D_DOWN);
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
