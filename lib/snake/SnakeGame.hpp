/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "../../Interfaces/IGame.hpp"
#include "lib/snake/Entities/Snake.hpp"

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
        int _score;
        Snake _snake;
};
