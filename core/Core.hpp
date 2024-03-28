/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#include "Interfaces/IGame.hpp"
#include "Interfaces/IGraphic.hpp"
#include "menu/Menu.hpp"
#include "DLLoader.hpp"
#include <memory>

#define ENTRY_POINT_GRAPHIC "loadGraphicInstance"
#define ENTRY_POINT_GAME "loadGameInstance"

#define IM_HERE std::cout << "I'm here " << __LINE__ << " on " << __FILE__ << std::endl;
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
            std::unique_ptr<Menu> _menu;
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphic> _graphic;
            DLLoader<IGame> _gameLoader;
            DLLoader<IGraphic> _graphicLoader;
            std::string _gameLib;
            std::string _graphicLib;
            int _key_event;
            bool _isMenu;
    };
}
