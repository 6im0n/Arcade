/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "includes/Keys.hpp"
#include <iostream>
#include <memory>
#include <sys/types.h>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>

Arcade::Core::Core(const std::string &graphicPath)
{
    _graphicLoader = DLLoader<IGraphic>(ENTRY_POINT_GRAPHIC);
    _graphic = std::unique_ptr<IGraphic>(_graphicLoader.getInstance(graphicPath));
    _indexGame = 1;
    _gameLoader = DLLoader<IGame>(ENTRY_POINT_GAME);
    _menu = std::make_unique<Menu>(graphicPath);
    _isMenu = true;
    loadTopScores();
}

Arcade::Core::~Core()
{
    saveTopScores();
}

void Arcade::Core::run()
{
    while (5) {
        _key_event = _graphic->getKeyEvent();
        if (_key_event == Keys::ONE || _key_event == Keys::TWO
            || _key_event == Keys::THREE || _key_event == Keys::FOUR) {
                _menu->catchKeyEvent(_key_event);
                _menu->getSelectedGame();
                _menu->getSelectedGraphic();
        } else if (_key_event != Keys::UNKNOWN) {
            if (_isMenu) {
                _menu->catchKeyEvent(_key_event);
            } else
                _game.get()->catchKeyEvent(_key_event);
        }
        if (!_isMenu) {
            _graphic.get()->clearWindow();
            _graphic.get()->displayEntities(_game.get()->getEntities());
            _graphic.get()->displayText(_game.get()->getTexts());
            _graphic.get()->playSound(_game.get()->getSounds());
            _graphic.get()->displayWindow();
            if (_game.get()->simulate() == -1) {
                if (_game.get()->stopGame() == -1) {
                    if (_isMenu == false) {
                        quitGame();
                    } else {
                        exit(84);
                    }
                }
                if (_game.get()->startGame() == -1) {
                    if (_isMenu == false) {
                        quitGame();
                    } else {
                        exit(84);
                    }
                }
            }
        } else {
            if (_menu->isExit()) {
                return;
            }
            _graphic.get()->displayWindow();
            _graphic.get()->displayEntities(_menu->getEntities());
            _graphic.get()->displayText(_menu->getTexts());
            _graphic.get()->playSound(_menu->getSounds());
            _graphic.get()->displayWindow();
            if (_menu->simulate() == -1) {
                if (_menu->stopGame() == -1) {
                    if (_isMenu == false) {
                        quitGame();
                    } else {
                        exit(84);
                    }
                }
                if (_menu->startGame() == -1) {
                    if (_isMenu == false) {
                        quitGame();
                    } else {
                        exit(84);
                    }
                }
            }
            if (_menu->isRunning())
                loadGame(_menu->getSelectedGame());
        }
        _key_event = Keys::UNKNOWN;
    }
}

void Arcade::Core::loadMenu()
{
    _isMenu = true;
    _menu->restart();
}

void Arcade::Core::loadGame(const std::string &gamePath)
{
    if (_gameLib == gamePath)
        return;
    if (_indexGame == 1) {
        _indexGame = 0;
    } else {
        _indexGame = 1;
    }
    std::cout << "indexGame: " << _indexGame << std::endl;
    std::cout << "menu text: " << _menu->getTexts().size() << std::endl;
    _menu->getTexts().at(_indexGame)->setText(_GamesName.at(_indexGame) + " " + _topPlayers.at(_indexGame) + " " + std::to_string(_topScores.at(_indexGame)));
    _gameLib = gamePath;
    _game.reset();
    _game = std::unique_ptr<IGame>(_gameLoader.getInstance(gamePath));
    _GamesName.at(_indexGame) = gamePath;
    _isMenu = false;
}

void Arcade::Core::loadGraphic(const std::string &graphicPath)
{
    if (_graphicLib == graphicPath)
        return;
    _graphicLib = graphicPath;
    _graphic.reset();
    _graphic = std::unique_ptr<IGraphic>(_graphicLoader.getInstance(graphicPath));
}

void Arcade::Core::quitGame()
{
    loadMenu();
    updateTopScores();
}

void Arcade::Core::saveTopScores()
{
    std::ofstream file("lib/topScores.txt");

    if (!file.is_open()) {
        std::cerr << "Error: can't save top scores" << std::endl;
        return;
    }
    file.clear();
    for (std::size_t i = 0; i < _topPlayers.size(); i++) {
        file << _GamesName.at(i) << " " << _topPlayers.at(i) << " " << _topScores.at(i) << std::endl;
    }
    file.close();
}

void Arcade::Core::loadTopScores()
{
    std::ifstream file("lib/topScores.txt");
    if (!file.is_open()) {
        std::cerr << "Error: can't load top scores" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::string game = line.substr(0, line.find(" "));
        std::string tmp = line.substr(line.find(" ") + 1, line.length() - 1);
        std::string player = tmp.substr(0, tmp.find(" "));
        tmp = tmp.substr(tmp.find(" ") + 1, tmp.length() - 1);
        std::string score = tmp;
        _GamesName.push_back(game);
        _topPlayers.push_back(player);
        _topScores.push_back(std::stoi(score));
    }
    if (_topPlayers.size() == 0) {
        _topPlayers.push_back("");
        _topPlayers.push_back("");
    }
    if (_topScores.size() == 0) {
        _topScores.push_back(0);
        _topScores.push_back(0);
    }
    if (_GamesName.size() == 0) {
        _GamesName.push_back("");
        _GamesName.push_back("");
    }
    file.close();
}

void Arcade::Core::updateTopScores()
{
    if (_game != nullptr) {
        if (_game->getScore() > _topScores.at(_indexGame)) {
            _topScores.at(_indexGame) = _game->getScore();
            _topPlayers.at(_indexGame) = _playerName;
            _menu->getTexts().at(_indexGame + 1)->setText(_GamesName.at(_indexGame) + " " + _topPlayers.at(_indexGame) + " " + std::to_string(_topScores.at(_indexGame)));
        }
    }
}
