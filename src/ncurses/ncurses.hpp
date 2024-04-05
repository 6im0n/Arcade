/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.hpp
*/

#pragma once

#include "Interfaces/IGraphic.hpp"
#include "includes/Keys.hpp"

namespace Arcade {
    class Ncurses : public IGraphic {
        public:
            Ncurses();
            ~Ncurses() = default;
            bool isWindowOpen() const override;
            void closeWindow();
            void clearWindow();

            //Event
            int getKeyEvent() override;
            std::pair<int, int> getMousePosition();

            //Display
            void displayWindow();
            void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
            void displayText(std::vector<std::shared_ptr<IText>> texts) override;
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
        private:
            std::vector<IEntity> _entities;
            std::vector<IText> _texts;
            std::vector<ISound> _sounds;
            Keys _key;
    };
}
