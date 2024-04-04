/*
** EPITECH PROJECT, 2024
** Arcade_Proj
** File description:
** Sdl
*/

#pragma once

#include "Interfaces/IGraphic.hpp"

namespace Arcade {
    class Sdl: public Arcade::IGraphic {
        public:
            Sdl();
            ~Sdl() override;

            //Window
            bool isWindowOpen() const override;
            void closeWindow() override;
            void clearWindow() override;

            //Event
            int getKeyEvent() override;

            //Display
            void displayWindow() override;
            void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
            void displayText(std::vector<std::shared_ptr<IText>> texts) override;
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
    };
}
