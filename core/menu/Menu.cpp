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

Arcade::Menu::Menu(std::string graphicLib)
{
    setGraphic(graphicLib);
    setGame("");
    _isRunning = true;
    _runButtons = new Button("Run", std::vector<std::size_t>(2, 2), std::vector<std::size_t>(1, 1), 'R', "", BUTTON_PATH);
    _runButtons->setNextButton(new Button(std::string("Exit"), std::vector<std::size_t>(4, 2), std::vector<std::size_t>(1, 1), 'E', "", BUTTON_PATH));
    _runButtons->setPrevButton(new Button(std::string("Player"), std::vector<std::size_t>(6, 2), std::vector<std::size_t>(1, 1), 'E', "", BUTTON_PATH));
    _runButtons->getPrevButton()->setPrevButton(_runButtons->getNextButton());

    _gameButtons = new Button(games.at(0), std::vector<std::size_t>(3, 4), std::vector<std::size_t>(1, 1), gamesLabel.at(0), games.at(0), BUTTON_PATH);
    _gameButtons->setNextButton(new Button(games.at(1), std::vector<std::size_t>(5, 4), std::vector<std::size_t>(1, 1), gamesLabel.at(1), games.at(1), BUTTON_PATH));
    _gameButtons->setPrevButton(_gameButtons->getNextButton());
    _gameButtons->setUpButton(_runButtons);

    _graphicButtons = new Button(libs.at(0), std::vector<std::size_t>(2, 6), std::vector<std::size_t>(1, 1), libsLabel.at(0), libs.at(0), BUTTON_PATH);
    _graphicButtons->setNextButton(new Button(libs.at(1), std::vector<std::size_t>(4, 6), std::vector<std::size_t>(1, 1), libsLabel.at(0), libs.at(1), BUTTON_PATH));
    _graphicButtons->setPrevButton(new Button(libs.at(2), std::vector<std::size_t>(4, 6), std::vector<std::size_t>(1, 1), libsLabel.at(0), libs.at(2), BUTTON_PATH));
    _graphicButtons->getNextButton()->setNextButton(_graphicButtons->getPrevButton());
    _graphicButtons->setDownButton(_runButtons);
    _graphicButtons->setUpButton(_gameButtons);

    _selectButton = new Button("Select", std::vector<std::size_t>(20, 20), std::vector<std::size_t>(1, 1), '\0', "", BUTTON_SELECTED_PATH);

    _currentButton = _runButtons;
    _selectButton->setPos(_currentButton->getPos().at(0), _currentButton->getPos().at(1));
    _exit = false;
    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(10, 10), std::vector<std::size_t>(1, 1), ' '));
    _texts.at(0)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(0)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(13, 12), std::vector<std::size_t>(1, 1), ' '));
    _texts.at(1)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(1)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>("", std::vector<std::size_t>(16, 14), std::vector<std::size_t>(1, 1), ' '));
    _texts.at(2)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(2)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>("Run", std::vector<std::size_t>(19, 16), std::vector<std::size_t>(1, 1), 'R'));
    _texts.at(3)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(3)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>("Exit", std::vector<std::size_t>(19, 18), std::vector<std::size_t>(1, 1), 'E'));
    _texts.at(4)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(4)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>("Player", std::vector<std::size_t>(19, 20), std::vector<std::size_t>(1, 1), 'P'));
    _texts.at(5)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(5)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>(games.at(0), std::vector<std::size_t>(19, 22), std::vector<std::size_t>(1, 1), gamesLabel.at(0)));
    _texts.at(6)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(6)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>(games.at(1), std::vector<std::size_t>(19, 24), std::vector<std::size_t>(1, 1), gamesLabel.at(1)));
    _texts.at(7)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(7)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>(libs.at(0), std::vector<std::size_t>(19, 26), std::vector<std::size_t>(1, 1), libsLabel.at(0)));
    _texts.at(8)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(8)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>(libs.at(1), std::vector<std::size_t>(19, 28), std::vector<std::size_t>(1, 1), libsLabel.at(1)));
    _texts.at(9)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(9)->setFontPath(FONT_PATH);
    _texts.push_back(std::make_shared<Text>(libs.at(2), std::vector<std::size_t>(19, 30), std::vector<std::size_t>(1, 1), libsLabel.at(2)));
    _texts.at(10)->setColor(std::make_unique<Color>(255, 255, 255, 255));
    _texts.at(10)->setFontPath(FONT_PATH);
    std::cout << "menu text size: " << _texts.size() << std::endl;
    _playerName = "";
    _changePlayer = false;
    _gamesScore.push_back(0);
    _gamesScore.push_back(0);
    _entities.push_back(std::shared_ptr<IEntity>(_runButtons));
    _entities.push_back(std::shared_ptr<IEntity>(_runButtons->getNextButton()));
    _entities.push_back(std::shared_ptr<IEntity>(_runButtons->getPrevButton()));
    _entities.push_back(std::shared_ptr<IEntity>(_gameButtons));
    _entities.push_back(std::shared_ptr<IEntity>(_gameButtons->getNextButton()));
    _entities.push_back(std::shared_ptr<IEntity>(_graphicButtons));
    _entities.push_back(std::shared_ptr<IEntity>(_graphicButtons->getNextButton()));
    _entities.push_back(std::shared_ptr<IEntity>(_graphicButtons->getPrevButton()));
    _entities.push_back(std::shared_ptr<IEntity>(_selectButton));
    _sounds = std::vector<std::shared_ptr<ISound>>();
}

Arcade::Menu::~Menu()
{
    delete _runButtons;
    delete _gameButtons;
    delete _graphicButtons;
}

void Arcade::Menu::catchKeyEvent(int key)
{
    if (!_isRunning) {
        return;
    }
    _lastKey = static_cast<Keys>(key);
    if (_changePlayer) {
        addToPlayerName(_lastKey);
        std::cout << "player: " << _playerName << std::endl;
        return;
    }
    if (_lastKey == Keys::O) {
        _gameButtons = _gameButtons->getPrevButton();
        setGame(_gameButtons->getLabel());
    }
    if (_lastKey == Keys::P) {
        _gameButtons = _gameButtons->getNextButton();
        setGame(_gameButtons->getLabel());
    }
    if (_lastKey == Keys::L) {
        _graphicButtons = _graphicButtons->getPrevButton();
        setGraphic(_graphicButtons->getLabel())   ;
    }
    if (_lastKey == Keys::M) {
        _graphicButtons = _graphicButtons->getNextButton();
        setGraphic(_graphicButtons->getLabel());
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
            std::cout << "change player" << std::endl;
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
        if (_lastKey == Keys::UP) {
            _currentButton = _currentButton->getUpButton();
        }
        if (_lastKey == Keys::DOWN) {
            _currentButton = _currentButton->getDownButton();
        }
        if (_lastKey == Keys::LEFT) {
            _currentButton = _currentButton->getPrevButton();
        }
        if (_lastKey == Keys::RIGHT) {
            _currentButton = _currentButton->getNextButton();
        }
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
        std::cout << "Current button is null" << std::endl;
        _currentButton = _runButtons;
    }
    _selectButton->setPos(_currentButton->getPos().at(0), _currentButton->getPos().at(1));
    std::cout << "Current button: " << _currentButton->getLabel() << std::endl;
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
    _currentButton = _runButtons;
}

void Arcade::Menu::addToPlayerName(Keys key)
{
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
