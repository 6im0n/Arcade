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
    _graphicLib = graphicPath;
    if (_graphic == nullptr) {
        std::cerr << "Error: can't load graphic library" << std::endl;
        exit(84);
    }
    _indexGame = 1;
    _gameLoader = DLLoader<IGame>(ENTRY_POINT_GAME);
    std::vector<std::string> libs = getLibs();
    _menu = std::make_unique<Menu>(graphicPath, libs);
    _isMenu = true;
    loadTopScores();
}

Arcade::Core::~Core()
{
    _graphic->closeWindow();
    saveTopScores();
    exit(0);
}

void Arcade::Core::run()
{
    std::pair<int, int> mousePos;
    while (5) {
        _key_event = _graphic->getKeyEvent();
        if (_key_event == Keys::ESCAPE) {
            if (_isMenu == false) {
                _key_event = Keys::UNKNOWN;
                quitGame();
            } else {
                return;
            }
        }
        mousePos = _graphic->getMousePosition();
        if (_key_event == Keys::ONE || _key_event == Keys::TWO
            || _key_event == Keys::THREE || _key_event == Keys::FOUR) {
                _menu->catchKeyEvent(_key_event);
                _menu->getSelectedGame();
                _menu->getSelectedGraphic();
        } else if (_key_event != Keys::UNKNOWN) {
            if (_isMenu) {
                _menu->catchMousePosition(mousePos.first, mousePos.second);
                _menu->catchKeyEvent(_key_event);
            } else {
                if (_key_event == Keys::FIVE) {
                    _game->stopGame();
                    _game->startGame();
                    _key_event = Keys::UNKNOWN;
                }
                _game.get()->catchMousePosition(mousePos.first, mousePos.second);
                _game.get()->catchKeyEvent(_key_event);
            }
        }
        if (!_isMenu) {
            _game.get()->catchMousePosition(mousePos.first, mousePos.second);
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
                loadMenu();
            }
        } else {
            if (_menu->isExit()) {
                return;
            }
            std::vector<std::string> libs = getLibs();
            _menu->updateLibs(libs);
            _menu->catchMousePosition(mousePos.first, mousePos.second);
            _graphic.get()->clearWindow();
            _graphic.get()->displayEntities(_menu->getEntities());
            _graphic.get()->displayText(_menu->getTexts());
            _graphic.get()->playSound(_menu->getSounds());
            _graphic.get()->displayWindow();
            if (_menu->simulate() == -1) {
                if (_menu->stopGame() == -1) {
                    exit(84);
                }
                if (_menu->startGame() == -1) {
                    exit(84);
                }
            }
        }
        loadGame(_menu->getSelectedGame());
        loadGraphic(_menu->getSelectedGraphic());
        _key_event = Keys::UNKNOWN;
    }
}

void Arcade::Core::loadMenu()
{
    _isMenu = true;
    _game.reset();
    _gameLib = "";
    _menu->restart();
}

void Arcade::Core::loadGame(const std::string &gamePath)
{
    if (_gameLib == gamePath || gamePath == "")
        return;
    if (_indexGame == 1) {
        _indexGame = 0;
    } else {
        _indexGame = 1;
    }
    _gameLib = gamePath;
    _game.reset();
    _game = std::unique_ptr<IGame>(_gameLoader.getInstance(gamePath));
    _game->startGame();
    _GamesName.at(_indexGame) = gamePath;
    _isMenu = false;
}

void Arcade::Core::loadGraphic(const std::string &graphicPath)
{
    if (_graphicLib == graphicPath)
        return;
    _graphicLib = graphicPath;
    _graphic->clearWindow();
    _graphic->closeWindow();
    _graphic.reset();
    _graphic = std::unique_ptr<IGraphic>(_graphicLoader.getInstance(graphicPath));
}

void Arcade::Core::quitGame()
{
    _graphic->clearWindow();
    updateTopScores();
    _game->stopGame();
    loadMenu();
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
        if (_topPlayers.at(i) != "") {
            std::string game;
            if (_GamesName.at(i).find("arcade_") != std::string::npos)
                game = _GamesName.at(i).substr(_GamesName.at(i).find("_") + 1, _GamesName.at(i).substr(_GamesName.at(i).find("_") + 1).length() - 3);
            else
                game = _GamesName.at(i);
            file << game << " " << _topPlayers.at(i) << " " << _topScores.at(i) << std::endl;
        }
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
    int i = 0;
    while (i < 2 && std::getline(file, line)) {
        std::string game = line.substr(0, line.find(" "));
        std::string tmp = line.substr(line.find(" ") + 1, line.length() - 1);
        std::string player = tmp.substr(0, tmp.find(" "));
        tmp = tmp.substr(tmp.find(" ") + 1, tmp.length() - 1);
        std::string score = tmp;
        _GamesName.push_back(game);
        _topPlayers.push_back(player);
        _topScores.push_back(std::stoi(score));
        i++;
    }
    while (_topPlayers.size() < 2) {
        _topPlayers.push_back("");
    }
    while (_topScores.size() < 2) {
        _topScores.push_back(0);
    }
    while (_GamesName.size() < 2) {
        _GamesName.push_back("");
    }
    if (_GamesName.at(0) != "" && _topPlayers.at(0) != "")
        _menu->getTexts().at(1)->setText(_GamesName.at(0) + "  " + _topPlayers.at(0) + "  " + std::to_string(_topScores.at(0)));
    if (_GamesName.at(1) != "" && _topPlayers.at(1) != "")
        _menu->getTexts().at(2)->setText(_GamesName.at(1) + "  " + _topPlayers.at(1) + "  " + std::to_string(_topScores.at(1)));
    file.close();
}

void Arcade::Core::updateTopScores()
{
    if (_game != nullptr) {
        std::string game = _GamesName.at(_indexGame).substr(_GamesName.at(_indexGame).find("_") + 1, _GamesName.at(_indexGame).substr(_GamesName.at(_indexGame).find("_") + 1).length() - 3);
        std::cout << game << std::endl;
        std::cout << _GamesName.at(0) << std::endl;
        std::cout << _GamesName.at(1) << std::endl;
        if (game == _GamesName.at(0)) {
            std::cout << "game 0" << std::endl;
            _indexGame = 0;
        } else if (game == _GamesName.at(1)) {
            std::cout << "game 1" << std::endl;
            _indexGame = 1;
        }
        if (_GamesName.at(0) == _GamesName.at(1)) {
            _indexGame = 0;
            _GamesName.at(1) = "";
            _topPlayers.at(1) = "";
            _topScores.at(1) = 0;
        }
        if (_game->getScore() > _topScores.at(_indexGame) && _menu->getPlayerName() != "") {
            _topScores.at(_indexGame) = _game->getScore();
            _topPlayers.at(_indexGame) = _menu->getPlayerName();
            _menu->getTexts().at(_indexGame + 1)->setText(game + "  " + _topPlayers.at(_indexGame) + "  " + std::to_string(_topScores.at(_indexGame)));
        }
    }
}

std::vector<std::string> Arcade::Core::getLibs()
{
    std::vector<std::string> libs;
    std::ifstream file("lib/games.txt");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: can't load games" << std::endl;
        return libs;
    }
    while (std::getline(file, line)) {
        if (line.find("arcade_") != std::string::npos && line.find(".so") != std::string::npos) {
            _GamesName.push_back(line.substr(line.find("_") + 1, line.substr(line.find("_") + 1).length() - 3));
            libs.push_back("./lib/" + line);
        }
    }
    while (libs.size() < 2)
        libs.push_back("");
    file.close();
    file.open("lib/graphics.txt");
    if (!file.is_open()) {
        std::cerr << "Error: can't load graphics" << std::endl;
        return libs;
    }
    while (std::getline(file, line)) {
        if (line.find("arcade_") != std::string::npos && line.find(".so") != std::string::npos) {
            libs.push_back("./lib/" + line);
        }
    }
    file.close();
    while (libs.size() < 5)
        libs.push_back("");
    return libs;
}
