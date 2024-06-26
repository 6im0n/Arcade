/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#define BUTTON_PATH "assets/core/button"
#define BUTTON_SELECTED_PATH "assets/core/buttonSelect"
#define FONT_PATH "assets/core/Roboto-Regular"

#pragma once
#include "abstract/AGame.hpp"
#include "Button.hpp"
#include "includes/Keys.hpp"
#include "classes/Text.hpp"

namespace Arcade {
    class Menu : public AGame {
        public :
            Menu(std::string graphicLib, std::vector<std::string> libsVector);
            ~Menu() override;
            void catchKeyEvent(int key) override;
            int simulate() override;
            int startGame() override;
            int stopGame() override;
            void setGraphic(std::string graphic);
            void setGame(std::string game);
            std::string getSelectedGame() const;
            std::string getSelectedGraphic() const;
            std::string getPlayerName() const;
            void setScore(int score, int gameIndex);
            bool isRunning() const;
            bool isExit() const;
            void restart();
            void addToPlayerName(Keys key);
            void catchMousePosition(int x, int y);
            void manageClick();
            void updateLibs(std::vector<std::string> libsVector);
        private :
            bool _isRunning;
            bool _exit;
            bool _changePlayer;
            Keys _lastKey;
            std::vector<int> _gamesScore;
            std::string _selectedGame;
            std::string _selectedGraphic;
            Button *_currentButton;
            Button *_runButtons;
            Button *_gameButtons;
            Button *_graphicButtons;
            Button *_selectButton;
            std::string _playerName;
            std::pair<int, int> _mousePos;
    };
}
