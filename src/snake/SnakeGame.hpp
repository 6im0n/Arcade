/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "Interfaces/IGame.hpp"
#include "Snake.hpp"
#include "Entities/Food.hpp"

#define AREA_GAME_WIDTH 17
#define AREA_GAME_HEIGHT 15
#define WINDOW_WIDTH 25
#define WINDOW_HEIGHT 29
#define START_WIDTH (WINDOW_WIDTH - AREA_GAME_WIDTH) / 2
#define START_HEIGHT (WINDOW_HEIGHT - AREA_GAME_HEIGHT) / 2

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

        //Display
        std::vector<std::shared_ptr<IEntity>> getEntities();
        std::vector<std::shared_ptr<IText>> getTexts();
        std::vector<std::shared_ptr<ISound>> getSounds();

    private:
        std::vector<std::shared_ptr<IEntity>> _entities;
        std::vector<std::shared_ptr<IText>> _texts;
        std::vector<std::shared_ptr<ISound>> _sounds;
        std::vector<std::vector<std::shared_ptr<IEntity>>> _map;

        int _score;
        Snake _snake;
        std::vector<std::shared_ptr<Food>> _foods;
};
