/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "Interfaces/IGame.hpp"
#include "Snake.hpp"
#include "Score.hpp"
#include "Entities/Food.hpp"

#define AREA_GAME_WIDTH 17
#define AREA_GAME_HEIGHT 15
#define WINDOW_WIDTH 25
#define WINDOW_HEIGHT 29
#define START_WIDTH (WINDOW_WIDTH - AREA_GAME_WIDTH) / 2
#define START_HEIGHT (WINDOW_HEIGHT - AREA_GAME_HEIGHT) / 2

#define WALL_PATH "assets/snake/wall"
#define VOID_PATH "assets/snake/void"
#define FOOD_PATH "assets/snake/apple"
#define SNAKE_BODY_PATH "assets/snake/body"
#define SNAKE_CORNER_PATH "assets/snake/body_corner"
#define SNAKE_HEAD_PATH "assets/snake/head"
#define SNAKE_TAIL_PATH "assets/snake/tail"

namespace Arcade {
    class SnakeGame : public IGame {
        public:
            SnakeGame();
            ~SnakeGame() = default;

            //Game
            int startGame();
            int stopGame();
            int getScore();
            int simulate();

            //Event
            void catchKeyEvent(int key);
            void catchMousePosition(int x, int y);

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();

        private:
            std::vector<std::shared_ptr<IEntity>> _entities;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::vector<std::shared_ptr<IEntity>>> _map;

            std::shared_ptr<Score> _score;
            Snake _snake;
            std::vector<std::shared_ptr<Food>> _foods;
    };
}
