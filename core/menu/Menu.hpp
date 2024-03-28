/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#pragma once
#include "abstract/AGame.hpp"
#include "Button.hpp"
#include "includes/keys.hpp"

const std::vector<std::string> libs {
    "lib/arcade_sfml.so",
    "lib/arcade_ncurses.so",
    "lib/arcade_sdl.so",
};

const std::vector<std::string> games {
    "lib/arcade_pacman.so",
    "lib/arcade_snake.so",
};

const std::vector<char> libsLabel {
    'S',
    'N',
    'D',
};

const std::vector<char> gamesLabel {
    'P',
    'S',
};

namespace Arcade {
    class Menu : public AGame {
        public :
            Menu(std::string graphicLib);
            ~Menu() override;
            void catchKeyEvent(int key) override;
            int simulate() override;
            int startGame() override;
            int stopGame() override;
            void setGraphic(std::string graphic);
            void setGame(std::string game);
            std::string getSelectedGame();
            std::string getSelectedGraphic();
            void setScore(int score, int gameIndex);
            bool isRunning();
            bool isExit();
        private :
            bool _isRunning;
            bool _exit;
            Keys _lastKey;
            std::vector<int> _gamesScore;
            std::string _selectedGame;
            std::string _selectedGraphic;
            Button *_currentButton;
            Button *_runButtons;
            Button *_gameButtons;
            Button *_graphicButtons;
            std::shared_ptr<IText> _score;
    };
}
