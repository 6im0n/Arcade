/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.hpp
*/

#pragma once

#include "Interfaces/IGraphic.hpp"
#include "includes/Keys.hpp"
#include <ncurses.h>

namespace Arcade {
    class Ncurses : public IGraphic {
        public:
            Ncurses();
            ~Ncurses() override;
            bool isWindowOpen() const override;
            void closeWindow() override;
            void clearWindow() override;

            //Event
            int getKeyEvent() override;
            std::pair<int, int> getMousePosition() override;

            //Display
            void displayWindow() override;
            void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
            void displayText(std::vector<std::shared_ptr<IText>> texts) override;
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
        private:
            static int colorToNcurses(const std::shared_ptr<IColor>& color);
            std::vector<IEntity> _entities;
            std::vector<IText> _texts;
            std::vector<ISound> _sounds;
            Keys _key;
    };
}
