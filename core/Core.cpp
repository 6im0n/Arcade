/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "includes/keys.hpp"

Arcade::Core::Core(std::string graphicPath)
{
    _graphicLoader = new DLLoader<IGraphic>(ENTRY_POINT);
    _graphic = _graphicLoader->getInstance(graphicPath);
    if (_graphic == nullptr) {
        exit(84);
    }
    _gameLoader = new DLLoader<IGame>(ENTRY_POINT);
}

Arcade::Core::~Core()
{
    delete _graphic;
    delete _game;
    delete _menu;
    delete _graphicLoader;
    delete _gameLoader;
}

void Arcade::Core::run()
{
    while (5) {
        _key_event = _graphic->getKeyEvent();
        if (_key_event == Arcade::Keys::O || _key_event == Arcade::Keys::P
            || _key_event == Arcade::Keys::L || _key_event == Arcade::Keys::M) {
        } else {
            _game->catchKeyEvent(_key_event);
        }
        _graphic->displayWindow();
        _graphic->displayEntities(_game->getEntities());
        _graphic->displayText(_game->getTexts());
        _graphic->playSound(_game->getSounds());
        if (_game->simulate() == -1) {
            if (_game->stopGame() == -1) {
                if (_isMenu == false) {
                    quitGame();
                } else {
                    exit(84);
                }
            }
            if (_game->startGame() == -1) {
                if (_isMenu == false) {
                    quitGame();
                } else {
                    exit(84);
                }
            }
        }
        _key_event = Arcade::Keys::UNKNOWN;
    }
}

void Arcade::Core::loadMenu()
{
    _game = _menu;
    _isMenu = true;
}

void Arcade::Core::loadGame(const std::string &gamePath)
{
    _game = _gameLoader->getInstance(gamePath);
    _isMenu = false;
}

void Arcade::Core::loadGraphic(const std::string &graphicPath)
{
    _graphic = _graphicLoader->getInstance(graphicPath);
}

void Arcade::Core::quitGame()
{
    delete _game;
    loadMenu();
}
