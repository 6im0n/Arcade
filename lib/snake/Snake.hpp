/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include "../../Interfaces/IGame.hpp"

class Snake : public IGame {
    public:
        Snake();
        ~Snake();

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
};
