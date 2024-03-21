/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

arcade::Core::Core(std::string graphicPath)
{
    _graphicLoader = new DLLoader<IGraphic>(ENTRY_POINT);
    _graphic = _graphicLoader->getInstance(graphicPath);
    if (_graphic == nullptr) {
        exit(84);
    }
    _gameLoader = new DLLoader<IGame>(ENTRY_POINT);
}

arcade::Core::~Core()
{
    delete _graphic;
    delete _game;
    delete _menu;
    delete _graphicLoader;
    delete _gameLoader;
}

void arcade::Core::run()
{
    while (5) {
        _key_event = _graphic->getKeyEvent();
        if (_key_event == arcade::Keys::O || _key_event == arcade::Keys::P
            || _key_event == arcade::Keys::L || _key_event == arcade::Keys::M) {
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
        _key_event = arcade::Keys::UNKNOWN;
    }
}

void arcade::Core::loadMenu()
{
    _game = _menu;
    _isMenu = true;
}

void arcade::Core::loadGame(const std::string &gamePath)
{
    _game = _gameLoader->getInstance(gamePath);
    _isMenu = false;
}

void arcade::Core::loadGraphic(const std::string &graphicPath)
{
    _graphic = _graphicLoader->getInstance(graphicPath);
}

void arcade::Core::quitGame()
{
    delete _game;
    loadMenu();
}
