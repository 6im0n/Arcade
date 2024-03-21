/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "Interfaces/IGame.hpp"
#include "lib/snake/Snake.hpp"
#include "lib/snake/Entities/Food.hpp"

#define AREA_GAME_WIDTH 17
#define AREA_GAME_HEIGHT 15

class SnakeGame : public IGame {
    public:
        SnakeGame();
        ~SnakeGame();

        //Game
        void startGame();
        void stopGame();
        int getScore();
        void simulate();

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
        std::vector<Food> _foods;
};
