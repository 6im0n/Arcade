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
            ~AGame() override = default;

            //Game
            int startGame() override = 0;
            int stopGame() override = 0;
            int getScore() override;
            int simulate() override = 0;

            //Event
            void catchKeyEvent(int key) override = 0;

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities() override;
            std::vector<std::shared_ptr<IText>> getTexts() override;
            std::vector<std::shared_ptr<ISound>> getSounds() override;

        protected:
            std::vector<std::shared_ptr<IEntity>> _entities;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<ISound>> _sounds;
            int score;
    };
}
