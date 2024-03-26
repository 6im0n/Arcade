/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "includes/keys.hpp"
#include <iostream>

Arcade::Core::Core(std::string graphicPath)
{
    _graphicLoader = new DLLoader<std::unique_ptr<IGraphic>>(ENTRY_POINT_GRAPHIC);
    _graphic = _graphicLoader->getInstance(graphicPath);
    if (_graphic == nullptr) {
        exit(84);
    }
    _gameLoader = new DLLoader<std::unique_ptr<Arcade::IGame>>(ENTRY_POINT_GAME);
    _game = _gameLoader->getInstance("lib/arcade_snake.so");
    if (_game == nullptr) {
        exit(84);
    }
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
        _key_event = _graphic->get()->getKeyEvent();
        if (_key_event == Keys::O || _key_event == Keys::P
            || _key_event == Keys::L || _key_event == Keys::M) {
        } else if (_key_event != Keys::UNKNOWN) {
            _game->get()->catchKeyEvent(_key_event);
        }
        _graphic->get()->displayWindow();
        _graphic->get()->displayEntities(_game->get()->getEntities());
        _graphic->get()->displayText(_game->get()->getTexts());
        _graphic->get()->playSound(_game->get()->getSounds());
        if (_game->get()->simulate() == -1) {
            if (_game->get()->stopGame() == -1) {
                if (_isMenu == false) {
                    quitGame();
                } else {
                    exit(84);
                }
            }
            if (_game->get()->startGame() == -1) {
                if (_isMenu == false) {
                    quitGame();
                } else {
                    exit(84);
                }
            }
        }
        _key_event = Keys::UNKNOWN;
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
