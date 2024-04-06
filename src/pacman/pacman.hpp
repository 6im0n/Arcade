/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "Interfaces/IGame.hpp"

namespace Arcade {
    class Pacman : public IGame {
        public:
            Pacman();
            ~Pacman() = default;

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
    };
}
