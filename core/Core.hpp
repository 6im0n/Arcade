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

#define ENTRY_POINT "loadInstance"

//key O = previous game
//key P = next game
//key L = previous graphic
//key M = next graphic

namespace arcade {
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
            IGame *_menu;
            IGame *_game;
            IGraphic *_graphic;
            DLLoader<IGame> *_gameLoader;
            DLLoader<IGraphic> *_graphicLoader;
            int _key_event;
            bool _isMenu;
    };
}
