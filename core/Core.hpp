/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#include "Interfaces/IGame.hpp"
#include "Interfaces/IGraphic.hpp"
#include "DLLoader.hpp"
#include <memory>

#define ENTRY_POINT_GRAPHIC "loadGraphicInstance"
#define ENTRY_POINT_GAME "loadGameInstance"

//key O = previous game
//key P = next game
//key L = previous graphic
//key M = next graphic

namespace Arcade {
    class Core {
        public :
            Core(std::string graphicPath);
            ~Core();
            void run();
            void loadGame(const std::string &gamePath);
            void loadMenu();
            void loadGraphic(const std::string &graphicPath);
            void quitGame();
        private :
            std::unique_ptr<IGame> *_menu;
            std::unique_ptr<Arcade::IGame> *_game;
            std::unique_ptr<IGraphic> *_graphic;
            DLLoader<std::unique_ptr<IGame>> *_gameLoader;
            DLLoader<std::unique_ptr<IGraphic>> *_graphicLoader;
            int _key_event;
            bool _isMenu;
    };
}
