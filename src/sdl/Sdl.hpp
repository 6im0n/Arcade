/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl.hpp
*/

#pragma once

#include "Interfaces/IGraphic.hpp"
#include "includes/Keys.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <memory>

namespace Arcade {
    class Sdl : public IGraphic {
    public:
        Sdl();
        ~Sdl() = default;
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
        std::vector<IEntity> _entities;
        std::vector<IText> _texts;
        std::vector<ISound> _sounds;
        SDL_Window *_window;
        SDL_Renderer *_renderer;

    };
}
