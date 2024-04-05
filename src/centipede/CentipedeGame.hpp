/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CentipedeGame
*/

#pragma once

#include "Interfaces/IGame.hpp"
#include "Snake.hpp"
#include "Score.hpp"
#include "Entities/Player.hpp"
#include "classes/Timer.hpp"

#define AREA_GAME_WIDTH 15
#define AREA_GAME_HEIGHT 25
#define WINDOW_WIDTH 25
#define WINDOW_HEIGHT 31
#define START_WIDTH (WINDOW_WIDTH - AREA_GAME_WIDTH) / 2
#define START_HEIGHT (WINDOW_HEIGHT - AREA_GAME_HEIGHT) / 2

#define POSX 0
#define POSY 1

// Pour toutes les positions de l'aire de jeu le premier elem du vector sera le x et le deuxième le y
#define GET_POSX_AREA(x) (x + START_WIDTH)
#define GET_POSY_AREA(y) (y + START_HEIGHT)
#define GET_POSXY_AREA(x, y) GET_POSX_AREA(x), GET_POSY_AREA(y)

#define WALL_PATH "assets/snake/wall"
#define VOID_PATH "assets/snake/void"
#define FOOD_PATH "assets/snake/apple"
#define SNAKE_BODY_PATH "assets/snake/body"
#define SNAKE_CORNER_PATH "assets/snake/body_corner"
#define SNAKE_HEAD_PATH "assets/snake/head"
#define SNAKE_TAIL_PATH "assets/snake/tail"

namespace Arcade {
    class CentipedeGame : public IGame {
        public:
            CentipedeGame();
            ~CentipedeGame() = default;

            //Game
            int startGame();
            int stopGame();
            int getScore();
            int simulate();
            void killSnake(Snake snakeKilled, std::vector<std::size_t> pos);

            //Event
            void catchKeyEvent(int key);

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();

        private:
            std::vector<std::shared_ptr<IEntity>> _entities;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::vector<std::shared_ptr<IEntity>>> _map;
            std::shared_ptr<Bullet> _bullet;
            std::shared_ptr<Player> _player;
            float _lastTime;

            std::shared_ptr<Score> _score;
            std::vector<Snake> _snakes;
            Timer _timer;
    };
}
