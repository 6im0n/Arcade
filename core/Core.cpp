/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "includes/keys.hpp"
#include <iostream>
#include <memory>

Arcade::Core::Core(std::string graphicPath)
{
    _graphicLoader = DLLoader<IGraphic>(ENTRY_POINT_GRAPHIC);
    _graphic = _graphicLoader.getInstance(graphicPath);
    if (_graphic == nullptr || _graphic.get() == nullptr) {
        std::cerr << "Error: " << graphicPath << " " << ENTRY_POINT_GRAPHIC << " returned nullptr" << std::endl;
        exit(84);
    }
    _gameLoader = DLLoader<IGame>(ENTRY_POINT_GAME);
    _menu = std::make_unique<Menu>(graphicPath);
    _isMenu = true;
}

Arcade::Core::~Core()
{
    _graphic.reset();
    _game.reset();
    _menu.reset();
}

void Arcade::Core::run()
{
    while (5) {
        _key_event = _graphic.get()->getKeyEvent();
        if (_key_event == Keys::O || _key_event == Keys::P
            || _key_event == Keys::L || _key_event == Keys::M) {
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
            _graphic.get()->displayWindow();
            _graphic.get()->displayEntities(_game.get()->getEntities());
            _graphic.get()->displayText(_game.get()->getTexts());
            _graphic.get()->playSound(_game.get()->getSounds());
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
        }
        _key_event = Keys::UNKNOWN;
    }
}

void Arcade::Core::loadMenu()
{
    _isMenu = true;
}

void Arcade::Core::loadGame(const std::string &gamePath)
{
    if (_gameLib == gamePath)
        return;
    _gameLib = gamePath;
    _game.reset(_gameLoader.getInstance(gamePath).release());
    _isMenu = false;
}

void Arcade::Core::loadGraphic(const std::string &graphicPath)
{
    if (_graphicLib == graphicPath)
        return;
    _graphicLib = graphicPath;
    _graphic.reset(_graphicLoader.getInstance(graphicPath).release());
}

void Arcade::Core::quitGame()
{
    loadMenu();
}
