/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGame
*/

#pragma once

#include "Interfaces/IGame.hpp"    // IGame

namespace Arcade {
    class AGame : public IGame {
        public:
            virtual ~AGame() = default;

            //Game
            virtual int startGame() = 0;
            virtual int stopGame() = 0;
            int getScore();
            virtual int simulate() = 0;

            //Event
            virtual void catchKeyEvent(int key) = 0;

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();

        protected:
            std::vector<std::shared_ptr<IEntity>> _entities;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<ISound>> _sounds;
            int score;
    };
}
