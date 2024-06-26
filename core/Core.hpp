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
#define TOP_SCORE_FILE "lib/topScores.txt"
#define GAME_FILS "lib/games.txt"
#define GRAPHIC_FILS "lib/graphics.txt"

#define IM_HERE std::cout << "I'm here " << __LINE__ << " on " << __FILE__ << std::endl;
//key 1 = previous game
//key 2 = next game
//key 3 = previous graphic
//key 4 = next graphic

namespace Arcade {
    class Core {
        public :
            Core(const std::string &graphicPath);
            ~Core();
            void run();
            void loadGame(const std::string &gamePath);
            void loadMenu();
            void loadGraphic(const std::string &graphicPath);
            void quitGame();
            void saveTopScores();
            void loadTopScores();
            void updateTopScores();
            std::vector<std::string> getLibs();
        private :
            std::unique_ptr<Menu> _menu;
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphic> _graphic;
            DLLoader<IGame> _gameLoader;
            DLLoader<IGraphic> _graphicLoader;
            std::string _gameLib;
            std::string _graphicLib;
            std::vector<std::string> _topPlayers;
            std::vector<std::string> _GamesName;
            std::vector<int> _topScores;
            std::string _playerName;
            int _indexGame;
            int _key_event;
            bool _isMenu;
    };
};
