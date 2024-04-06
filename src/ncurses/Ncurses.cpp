/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.cpp
*/

#include "Ncurses.hpp"
#include "includes/Keys.hpp"
#include <cmath>
#include <map>
#include <memory>
#include <iostream>


Arcade::Ncurses::Ncurses()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));

}

bool Arcade::Ncurses::isWindowOpen() const
{
    return true;
}

void Arcade::Ncurses::closeWindow()
{
    endwin();
}

void Arcade::Ncurses::clearWindow()
{
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            mvprintw(i, j, " ");
        }
    }
}

int Arcade::Ncurses::getKeyEvent()
{
    int key = getch();
    static std::map<int, int> keyMap = {
        {'A', Arcade::Keys::A},
        {'B', Arcade::Keys::B},
        {'C', Arcade::Keys::C},
        {'D', Arcade::Keys::D},
        {'E', Arcade::Keys::E},
        {'F', Arcade::Keys::F},
        {'G', Arcade::Keys::G},
        {'H', Arcade::Keys::H},
        {'I', Arcade::Keys::I},
        {'J', Arcade::Keys::J},
        {'K', Arcade::Keys::K},
        {'L', Arcade::Keys::L},
        {'M', Arcade::Keys::M},
        {'N', Arcade::Keys::N},
        {'O', Arcade::Keys::O},
        {'P', Arcade::Keys::P},
        {'Q', Arcade::Keys::Q},
        {'R', Arcade::Keys::R},
        {'S', Arcade::Keys::S},
        {'T', Arcade::Keys::T},
        {'U', Arcade::Keys::U},
        {'V', Arcade::Keys::V},
        {'W', Arcade::Keys::W},
        {'X', Arcade::Keys::X},
        {'Y', Arcade::Keys::Y},
        {'Z', Arcade::Keys::Z},
        {'1', Arcade::Keys::ONE},
        {'2', Arcade::Keys::TWO},
        {'3', Arcade::Keys::THREE},
        {'4', Arcade::Keys::FOUR},
        {'5', Arcade::Keys::FIVE},
        {'6', Arcade::Keys::SIX},
        {'7', Arcade::Keys::SEVEN},
        {'8', Arcade::Keys::EIGHT},
        {'9', Arcade::Keys::NINE},
        {'0', Arcade::Keys::ZERO},
        {27, Arcade::Keys::ESCAPE},
        {9, Arcade::Keys::TAB},
        {KEY_BACKSPACE, Arcade::Keys::BACKSPACE},
        {KEY_UP, Arcade::Keys::UP},
        {KEY_DOWN, Arcade::Keys::DOWN},
        {KEY_LEFT, Arcade::Keys::LEFT},
        {KEY_RIGHT, Arcade::Keys::RIGHT},
        {10, Arcade::Keys::ENTER},
        {32, Arcade::Keys::SPACE},
        {KEY_MOUSE, Arcade::Keys::MOUSE_LEFT}
    };
    return keyMap[key];
}

std::pair<int, int> Arcade::Ncurses::getMousePosition()
{
    MEVENT event;
    if (getmouse(&event) == OK) {
        return {event.x * 29 , event.y * 29};
    }
    return {-1, -1};
}

void Arcade::Ncurses::displayWindow()
{
    refresh();
}

int Arcade::Ncurses::colorToNcurses(const std::shared_ptr<IColor>& color)
{
    int bestColor = 1;
    double minDistance = 1000000;

    std::map<int, std::tuple<int, int, int, int>> colors = {
        {1, {255, 255, 255, 255}},
        {2, {255, 0, 0, 255}},
        {3, {0, 255, 0, 255}},
        {4, {0, 0, 255, 255}},
        {5, {255, 255, 0, 255}},
        {6, {255, 0, 255, 255}},
        {7, {0, 255, 255, 255}},
        {8, {255, 255, 255, 255}}

    };

    for (auto &colorPair : colors) {
        double distance = sqrt(pow(std::get<0>(colorPair.second) - color->getR(), 2) + pow(std::get<1>(colorPair.second) - color->getG(), 2) + pow(std::get<2>(colorPair.second) - color->getB(), 2));
        if (distance < minDistance) {
            minDistance = distance;
            bestColor = colorPair.first;
        }
    }
    return bestColor;
}

void Arcade::Ncurses::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        int x = colorToNcurses(entity->getColor());
        wattron(stdscr, COLOR_PAIR(x));
        mvwaddch(stdscr, entity->getPos()[1], entity->getPos()[0], (char)entity->getChar());
        wattroff(stdscr, COLOR_PAIR(x));
    }
}

void Arcade::Ncurses::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        int x = colorToNcurses(text->getColor());
        if (text->getFontPath().empty())
            continue;
        wattron(stdscr, COLOR_PAIR(x));
        mvprintw(text->getPos()[1], text->getPos()[0], "%s", text->getText().c_str());
        wattroff(stdscr, COLOR_PAIR(x));
    }
}

void Arcade::Ncurses::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void)sounds;
}

extern "C"
{
    __attribute__((constructor))
    void constructor()
    {
    }
    __attribute__((destructor))
    void destructor()
    {
    }
    Arcade::Ncurses *loadGraphicInstance()
    {
        return new Arcade::Ncurses();
    }
}
