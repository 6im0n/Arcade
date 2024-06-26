/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.hpp
*/

#include "Menu.hpp"
#include "classes/Color.hpp"
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::string> libs {
    "",
    "",
    "",
};

std::vector<std::string> games {
    "",
    "",
};

std::vector<char> libsLabel {
    '\0',
    '\0',
    '\0',
};

std::vector<char> gamesLabel {
    '\0',
    '\0',
};

Arcade::Menu::Menu(std::string graphicLib, std::vector<std::string> libsVector)
{
    setGraphic(graphicLib);
    setGame("");
    games.at(0) = libsVector.at(0);
    games.at(1) = libsVector.at(1);
    libs.at(0) = libsVector.at(2);
    libs.at(1) = libsVector.at(3);
    libs.at(2) = libsVector.at(4);
    for (std::size_t i = 0; i < 2; i++) {
        if (i < games.size() && games.at(i).size() > 11)
            gamesLabel.at(i) = games.at(i).at(11) - 32;
        else
            gamesLabel.at(i) = '\0';
    }
    for (std::size_t i = 0; i < 3; i++) {
        if (i < libsVector.size() && libs.at(i).size() > 11)
            libsLabel.at(i) = libs.at(i).at(11) - 32;
        else
            libsLabel.at(i) = '\0';
    }
    _isRunning = true;
    _runButtons = new Button("Run", std::vector<std::size_t>(2, 2), std::vector<std::size_t>(130, 87), 'R', "", BUTTON_PATH);
    _runButtons->setNextButton(new Button(std::string("Exit"), std::vector<std::size_t>(10, 2), std::vector<std::size_t>(130, 87), 'E', "", BUTTON_PATH));
    _runButtons->getNextButton()->setPos(10, 2);
    _runButtons->setPrevButton(new Button(std::string("Player"), std::vector<std::size_t>(18, 2), std::vector<std::size_t>(130, 87), 'P', "", BUTTON_PATH));
    _runButtons->getPrevButton()->setPos(18, 2);
    _runButtons->getPrevButton()->setPrevButton(_runButtons->getNextButton());

    _gameButtons = new Button(games.at(0), std::vector<std::size_t>(6, 14), std::vector<std::size_t>(130, 87), gamesLabel.at(0), games.at(0), BUTTON_PATH);
    _gameButtons->setPos(6, 14);
    _gameButtons->setNextButton(new Button(games.at(1), std::vector<std::size_t>(14, 14), std::vector<std::size_t>(130, 87), gamesLabel.at(1), games.at(1), BUTTON_PATH));
    _gameButtons->getNextButton()->setPos(14, 14);
    _gameButtons->setPrevButton(_gameButtons->getNextButton());
    _gameButtons->setUpButton(_runButtons);

    _graphicButtons = new Button(libs.at(0), std::vector<std::size_t>(2, 26), std::vector<std::size_t>(130, 87), libsLabel.at(0), libs.at(0), BUTTON_PATH);
    _graphicButtons->setPos(2, 26);
    _graphicButtons->setNextButton(new Button(libs.at(1), std::vector<std::size_t>(10, 26), std::vector<std::size_t>(130, 87), libsLabel.at(1), libs.at(1), BUTTON_PATH));
    _graphicButtons->getNextButton()->setPos(10, 26);
    _graphicButtons->setPrevButton(new Button(libs.at(2), std::vector<std::size_t>(18, 26), std::vector<std::size_t>(130, 87), libsLabel.at(2), libs.at(2), BUTTON_PATH));
    _graphicButtons->getPrevButton()->setPos(18, 26);
    _graphicButtons->getNextButton()->setNextButton(_graphicButtons->getPrevButton());
    _graphicButtons->setDownButton(_runButtons);
    _graphicButtons->setUpButton(_gameButtons);

    _runButtons->getNextButton()->setDownButton(_runButtons->getDownButton());
    _runButtons->getNextButton()->setUpButton(_runButtons->getUpButton());
    _runButtons->getPrevButton()->setDownButton(_runButtons->getDownButton());
    _runButtons->getPrevButton()->setUpButton(_runButtons->getUpButton());

    _gameButtons->getNextButton()->setDownButton(_gameButtons->getDownButton());
    _gameButtons->getNextButton()->setUpButton(_gameButtons->getUpButton());

    _graphicButtons->getNextButton()->setDownButton(_graphicButtons->getDownButton());
    _graphicButtons->getNextButton()->setUpButton(_graphicButtons->getUpButton());
    _graphicButtons->getPrevButton()->setDownButton(_graphicButtons->getDownButton());
    _graphicButtons->getPrevButton()->setUpButton(_graphicButtons->getUpButton());

    _selectButton = new Button("Select", std::vector<std::size_t>(2, 2), std::vector<std::size_t>(130, 87), '\0', "", BUTTON_SELECTED_PATH);

    _currentButton = _runButtons;
    _selectButton->setPos(_currentButton->getPos().at(0), _currentButton->getPos().at(1));
    _exit = false;

    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(2, 2), std::vector<std::size_t>(15,15), ' '));
    _texts.at(0)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(0)->setFontPath(FONT_PATH);
    _texts.at(0)->setPos(0, 0);
    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(5, 2), std::vector<std::size_t>(15,15), ' '));
    _texts.at(1)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(1)->setFontPath(FONT_PATH);
    _texts.at(1)->setPos(5, 0);
    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(10, 2), std::vector<std::size_t>(15, 15), ' '));
    _texts.at(2)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(2)->setFontPath(FONT_PATH);
    _texts.at(2)->setPos(10, 0);
    _texts.push_back(std::make_shared<Text>("Run", std::vector<std::size_t>(3, 3), std::vector<std::size_t>(30, 30), 'R'));
    _texts.at(3)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(3)->setFontPath(FONT_PATH);
    _texts.at(3)->setPos(3, 3);
    _texts.push_back(std::make_shared<Text>("Exit", std::vector<std::size_t>(11, 3), std::vector<std::size_t>(30, 30), 'E'));
    _texts.at(4)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(4)->setFontPath(FONT_PATH);
    _texts.at(4)->setPos(11, 3);
    _texts.push_back(std::make_shared<Text>("Player", std::vector<std::size_t>(19, 3), std::vector<std::size_t>(30, 30), 'P'));
    _texts.at(5)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(5)->setFontPath(FONT_PATH);
    _texts.at(5)->setPos(19, 3);
    _texts.push_back(std::make_shared<Text>(games.at(0).substr(games.at(0).find("_") + 1, games.at(0).substr(games.at(0).find("_") + 1).length() - 3), std::vector<std::size_t>(6, 15), std::vector<std::size_t>(25, 25), gamesLabel.at(0)));
    _texts.at(6)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(6)->setFontPath(FONT_PATH);
    _texts.at(6)->setPos(6, 15);
    _texts.push_back(std::make_shared<Text>(games.at(1).substr(games.at(1).find("_") + 1, games.at(1).substr(games.at(1).find("_") + 1).length() - 3), std::vector<std::size_t>(15, 15), std::vector<std::size_t>(20, 20), gamesLabel.at(1)));
    _texts.at(7)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(7)->setFontPath(FONT_PATH);
    _texts.at(7)->setPos(15, 15);
    _texts.push_back(std::make_shared<Text>(libs.at(0).substr(libs.at(0).find("_") + 1, libs.at(0).substr(libs.at(0).find("_") + 1).length() - 3), std::vector<std::size_t>(3, 27), std::vector<std::size_t>(30, 30), libsLabel.at(0)));
    _texts.at(8)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(8)->setFontPath(FONT_PATH);
    _texts.at(8)->setPos(3, 27);
    _texts.push_back(std::make_shared<Text>(libs.at(1).substr(libs.at(1).find("_") + 1, libs.at(1).substr(libs.at(1).find("_") + 1).length() - 3), std::vector<std::size_t>(11, 27), std::vector<std::size_t>(30, 30), libsLabel.at(1)));
    _texts.at(9)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(9)->setFontPath(FONT_PATH);
    _texts.at(9)->setPos(10, 27);
    _texts.push_back(std::make_shared<Text>(libs.at(2).substr(libs.at(2).find("_") + 1, libs.at(2).substr(libs.at(2).find("_") + 1).length() - 3), std::vector<std::size_t>(17, 27), std::vector<std::size_t>(30, 30), libsLabel.at(2)));
    _texts.at(10)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(10)->setFontPath(FONT_PATH);
    _texts.at(10)->setPos(19, 27);

    _playerName = "";
    _changePlayer = false;
    _gamesScore.push_back(0);
    _gamesScore.push_back(0);
    _entities.push_back(std::shared_ptr<IEntity>(new Button("Run", std::vector<std::size_t>(2, 2), std::vector<std::size_t>(130, 87), 'R', "", BUTTON_PATH)));
    _entities.back()->setPos(2, 2);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button("Exit", std::vector<std::size_t>(10, 2), std::vector<std::size_t>(130, 87), 'E', "", BUTTON_PATH)));
    _entities.back()->setPos(10, 2);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button("Player", std::vector<std::size_t>(18, 2), std::vector<std::size_t>(130, 87), 'P', "", BUTTON_PATH)));
    _entities.back()->setPos(18, 2);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button(games.at(0), std::vector<std::size_t>(6, 14), std::vector<std::size_t>(130, 87), gamesLabel.at(0), games.at(0), BUTTON_PATH)));
    _entities.back()->setPos(6, 14);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button(games.at(1), std::vector<std::size_t>(14, 14), std::vector<std::size_t>(130, 87), gamesLabel.at(1), games.at(1), BUTTON_PATH)));
    _entities.back()->setPos(14, 14);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button(libs.at(0), std::vector<std::size_t>(2, 26), std::vector<std::size_t>(130, 87), libsLabel.at(0), libs.at(0), BUTTON_PATH)));
    _entities.back()->setPos(2, 26);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button(libs.at(1), std::vector<std::size_t>(10, 26), std::vector<std::size_t>(130, 87), libsLabel.at(1), libs.at(1), BUTTON_PATH)));
    _entities.back()->setPos(10, 26);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(new Button(libs.at(2), std::vector<std::size_t>(18, 26), std::vector<std::size_t>(130, 87), libsLabel.at(2), libs.at(2), BUTTON_PATH)));
    _entities.back()->setPos(18, 26);
    _entities.back()->setSize(130, 87);
    _entities.push_back(std::shared_ptr<IEntity>(_selectButton));
    _entities.back()->setPos(_currentButton->getPos().at(0), _currentButton->getPos().at(1));
    _entities.back()->setSize(130, 87);
    _sounds = std::vector<std::shared_ptr<ISound>>();
}

Arcade::Menu::~Menu()
{
}

void Arcade::Menu::catchKeyEvent(int key)
{
    _lastKey = static_cast<Keys>(key);
    if (_lastKey == Keys::ONE) {
        _gameButtons = _gameButtons->getPrevButton();
        setGame(_gameButtons->getLabel());
    }
    if (_lastKey == Keys::TWO) {
        _gameButtons = _gameButtons->getNextButton();
        setGame(_gameButtons->getLabel());
    }
    if (_lastKey == Keys::THREE) {
        _graphicButtons = _graphicButtons->getPrevButton();
        setGraphic(_graphicButtons->getLabel())   ;
    }
    if (_lastKey == Keys::FOUR) {
        _graphicButtons = _graphicButtons->getNextButton();
        setGraphic(_graphicButtons->getLabel());
    }
    if (!_isRunning) {
        return;
    }
    if (_changePlayer) {
        addToPlayerName(_lastKey);
        return;
    }
    if (_lastKey == Keys::ESCAPE) {
        _exit = true;
    }
    if (_lastKey == Keys::ENTER && !_changePlayer) {
        if (_currentButton->getLabel() == "Run") {
            _isRunning = false;
        }
        if (_currentButton->getLabel() == "Exit") {
            _exit = true;
        }
        if (_currentButton->getLabel() == "Player") {
            _changePlayer = true;
            _playerName = "";
        }
        if (_currentButton->getLabel() == games.at(0)) {
            setGame(games.at(0));
        }
        if (_currentButton->getLabel() == games.at(1)) {
            setGame(games.at(1));
        }
        if (_currentButton->getLabel() == libs.at(0)) {
            setGraphic(libs.at(0));
        }
        if (_currentButton->getLabel() == libs.at(1)) {
            setGraphic(libs.at(1));
        }
        if (_currentButton->getLabel() == libs.at(2)) {
            setGraphic(libs.at(2));
        }
    }
    if (!_changePlayer) {
        if (_lastKey == Keys::UP || _lastKey == Keys::Z) {
            _currentButton = _currentButton->getUpButton();
        }
        if (_lastKey == Keys::DOWN || _lastKey == Keys::S) {
            _currentButton = _currentButton->getDownButton();
        }
        if (_lastKey == Keys::LEFT || _lastKey == Keys::Q) {
            _currentButton = _currentButton->getPrevButton();
        }
        if (_lastKey == Keys::RIGHT || _lastKey == Keys::D) {
            _currentButton = _currentButton->getNextButton();
        }
    }
    if (key == Keys::MOUSE_LEFT || key == Keys::MOUSE_RIGHT) {
        manageClick();
    }
    if (_lastKey == Keys::ESCAPE) {
        stopGame();
    }
}

int Arcade::Menu::simulate()
{
    if (!_isRunning) {
        return -1;
    }
    if (_currentButton == nullptr) {
        _currentButton = _runButtons;
    }
    _selectButton->setPos(_currentButton->getPos().at(0), _currentButton->getPos().at(1));
    _texts.at(0)->setText(_playerName);
    return 0;
}

int Arcade::Menu::startGame()
{
    _isRunning = true;
    return 0;
}

int Arcade::Menu::stopGame()
{
    _isRunning = false;
    return 0;
}

void Arcade::Menu::setGraphic(std::string graphic)
{
    _selectedGraphic = graphic;
}

void Arcade::Menu::setGame(std::string game)
{
    _selectedGame = game;
}

std::string Arcade::Menu::getSelectedGame() const
{
    return _selectedGame;
}

std::string Arcade::Menu::getSelectedGraphic() const
{
    return _selectedGraphic;
}

void Arcade::Menu::setScore(int score, int gameIndex)
{
    _gamesScore.at(gameIndex) = score;
}

bool Arcade::Menu::isRunning() const
{
    return _isRunning;
}

bool Arcade::Menu::isExit() const
{
    return _exit;
}

void Arcade::Menu::restart()
{
    _isRunning = true;
    _exit = false;
    _changePlayer = false;
    _currentButton = _runButtons;
    _selectedGame = "";
}

void Arcade::Menu::addToPlayerName(Keys key)
{
    if (key == Keys::ESCAPE) {
        _changePlayer = false;
        _playerName = "";
    }
    if (key == Keys::ENTER) {
        _changePlayer = false;
    }
    if (key == Keys::A) {
        _playerName += "A";
    }
    if (key == Keys::B) {
        _playerName += "B";
    }
    if (key == Keys::C) {
        _playerName += "C";
    }
    if (key == Keys::D) {
        _playerName += "D";
    }
    if (key == Keys::E) {
        _playerName += "E";
    }
    if (key == Keys::F) {
        _playerName += "F";
    }
    if (key == Keys::G) {
        _playerName += "G";
    }
    if (key == Keys::H) {
        _playerName += "H";
    }
    if (key == Keys::I) {
        _playerName += "I";
    }
    if (key == Keys::J) {
        _playerName += "J";
    }
    if (key == Keys::K) {
        _playerName += "K";
    }
    if (key == Keys::L) {
        _playerName += "L";
    }
    if (key == Keys::M) {
        _playerName += "M";
    }
    if (key == Keys::N) {
        _playerName += "N";
    }
    if (key == Keys::O) {
        _playerName += "O";
    }
    if (key == Keys::P) {
        _playerName += "P";
    }
    if (key == Keys::Q) {
        _playerName += "Q";
    }
    if (key == Keys::R) {
        _playerName += "R";
    }
    if (key == Keys::S) {
        _playerName += "S";
    }
    if (key == Keys::T) {
        _playerName += "T";
    }
    if (key == Keys::U) {
        _playerName += "U";
    }
    if (key == Keys::V) {
        _playerName += "V";
    }
    if (key == Keys::W) {
        _playerName += "W";
    }
    if (key == Keys::X) {
        _playerName += "X";
    }
    if (key == Keys::Y) {
        _playerName += "Y";
    }
    if (key == Keys::Z) {
        _playerName += "Z";
    }
    if (key == Keys::SPACE) {
        _playerName += " ";
    }
    if (key == Keys::BACKSPACE) {
        _playerName = _playerName.substr(0, _playerName.size() - 1);
    }
}

std::string Arcade::Menu::getPlayerName() const
{
    return _playerName;
}

void Arcade::Menu::catchMousePosition(int x, int y)
{
    _mousePos.first = x;
    _mousePos.second = y;
}

void Arcade::Menu::manageClick()
{
    if ((std::size_t)_mousePos.first >= _runButtons->getPos().at(0) - (_runButtons->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _runButtons->getPos().at(0) + (_runButtons->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _runButtons->getPos().at(1) - (_runButtons->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _runButtons->getPos().at(1) + (_runButtons->getSize().at(1) / 2)) {
    }
    if ((std::size_t)_mousePos.first >= _runButtons->getNextButton()->getPos().at(0) - (_runButtons->getNextButton()->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _runButtons->getNextButton()->getPos().at(0) + (_runButtons->getNextButton()->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _runButtons->getNextButton()->getPos().at(1) - (_runButtons->getNextButton()->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _runButtons->getNextButton()->getPos().at(1) + (_runButtons->getNextButton()->getSize().at(1) / 2)) {
        _exit = true;
    }
    if ((std::size_t)_mousePos.first >= _runButtons->getPrevButton()->getPos().at(0) - (_runButtons->getPrevButton()->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _runButtons->getPrevButton()->getPos().at(0) + (_runButtons->getPrevButton()->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _runButtons->getPrevButton()->getPos().at(1) - (_runButtons->getPrevButton()->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _runButtons->getPrevButton()->getPos().at(1) + (_runButtons->getPrevButton()->getSize().at(1) / 2)) {
        _changePlayer = true;
        _playerName = "";
    }
    if ((std::size_t)_mousePos.first >= _gameButtons->getPos().at(0) - (_gameButtons->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _gameButtons->getPos().at(0) + (_gameButtons->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _gameButtons->getPos().at(1) - (_gameButtons->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _gameButtons->getPos().at(1) + (_gameButtons->getSize().at(1) / 2)) {
        setGame(_gameButtons->getLabel());
    }
    if ((std::size_t)_mousePos.first >= _gameButtons->getNextButton()->getPos().at(0) - (_gameButtons->getNextButton()->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _gameButtons->getNextButton()->getPos().at(0) + (_gameButtons->getNextButton()->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _gameButtons->getNextButton()->getPos().at(1) - (_gameButtons->getNextButton()->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _gameButtons->getNextButton()->getPos().at(1) + (_gameButtons->getNextButton()->getSize().at(1) / 2)) {
        setGame(_gameButtons->getNextButton()->getLabel());
    }
    if ((std::size_t)_mousePos.first >= _graphicButtons->getPos().at(0) - (_graphicButtons->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _graphicButtons->getPos().at(0) + (_graphicButtons->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _graphicButtons->getPos().at(1) - (_graphicButtons->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _graphicButtons->getPos().at(1) + (_graphicButtons->getSize().at(1) / 2)) {
        setGraphic(_graphicButtons->getLabel());
    }
    if ((std::size_t)_mousePos.first >= _graphicButtons->getNextButton()->getPos().at(0) - (_graphicButtons->getNextButton()->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _graphicButtons->getNextButton()->getPos().at(0) + (_graphicButtons->getNextButton()->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _graphicButtons->getNextButton()->getPos().at(1) - (_graphicButtons->getNextButton()->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _graphicButtons->getNextButton()->getPos().at(1) + (_graphicButtons->getNextButton()->getSize().at(1) / 2)) {
        setGraphic(_graphicButtons->getNextButton()->getLabel());
    }
    if ((std::size_t)_mousePos.first >= _graphicButtons->getPrevButton()->getPos().at(0) - (_graphicButtons->getPrevButton()->getPos().at(0) / 2) && (std::size_t)_mousePos.first <= _graphicButtons->getPrevButton()->getPos().at(0) + (_graphicButtons->getPrevButton()->getSize().at(0) / 2) && (std::size_t)_mousePos.second >= _graphicButtons->getPrevButton()->getPos().at(1) - (_graphicButtons->getPrevButton()->getPos().at(1) / 2) && (std::size_t)_mousePos.second <= _graphicButtons->getPrevButton()->getPos().at(1) + (_graphicButtons->getPrevButton()->getSize().at(1) / 2)) {
        setGraphic(_graphicButtons->getPrevButton()->getLabel());
    }
}

void Arcade::Menu::updateLibs(std::vector<std::string> libsVector)
{
    games.at(0) = libsVector.at(0);
    games.at(1) = libsVector.at(1);
    libs.at(0) = libsVector.at(2);
    libs.at(1) = libsVector.at(3);
    libs.at(2) = libsVector.at(4);
    for (std::size_t i = 0; i < 2; i++) {
        if (i < games.size() && games.at(i).size() > 11)
            gamesLabel.at(i) = games.at(i).at(11) - 32;
        else
            gamesLabel.at(i) = '\0';
    }
    for (std::size_t i = 0; i < 3; i++) {
        if (i < libsVector.size() && libs.at(i).size() > 11)
            libsLabel.at(i) = libs.at(i).at(11) - 32;
        else
            libsLabel.at(i) = '\0';
    }
    if (libsVector.size() >= 1)
        _texts.at(6)->setText(games.at(0).substr(games.at(0).find("_") + 1, games.at(0).substr(games.at(0).find("_") + 1).length() - 3));
    if (libsVector.size() >= 2)
        _texts.at(7)->setText(games.at(1).substr(games.at(1).find("_") + 1, games.at(1).substr(games.at(1).find("_") + 1).length() - 3));
    if (libsVector.size() >= 3)
        _texts.at(8)->setText(libs.at(0).substr(libs.at(0).find("_") + 1, libs.at(0).substr(libs.at(0).find("_") + 1).length() - 3));
    if (libsVector.size() >= 4)
        _texts.at(9)->setText(libs.at(1).substr(libs.at(1).find("_") + 1, libs.at(1).substr(libs.at(1).find("_") + 1).length() - 3));
    if (libsVector.size() >= 5)
        _texts.at(10)->setText(libs.at(2).substr(libs.at(2).find("_") + 1, libs.at(2).substr(libs.at(2).find("_") + 1).length() - 3));
}
