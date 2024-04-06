/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl.hpp
*/

#pragma once
#include "includes/Keys.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <memory>
#include <vector>
#include "Interfaces/IGraphic.hpp"
#include "Interfaces/IEntity.hpp"
#include "Interfaces/IText.hpp"
#include "Interfaces/ISound.hpp"

namespace Arcade {
    class Sdl : public IGraphic {
        public:
            Sdl();
            ~Sdl();
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
            SDL_Window *_window;
            SDL_Renderer *_renderer;
    };
}
