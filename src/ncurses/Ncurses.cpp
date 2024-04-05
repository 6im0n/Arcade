/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.cpp
*/

#include "Ncurses.hpp"
#include "includes/Keys.hpp"
#include <memory>
#include <iostream>

Arcade::Ncurses::Ncurses()
{
    initscr();
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
    clear();
}

int Arcade::Ncurses::getKeyEvent()
{
    int key = getch();
    if (key == 27)
        return Arcade::Keys::ESCAPE;
    if (key == 10)
        return Arcade::Keys::ENTER;
    if (key == 32)
        return Arcade::Keys::SPACE;
    if (key == 65)
        return Arcade::Keys::UP;
    if (key == 66)
        return Arcade::Keys::DOWN;
    if (key == 67)
        return Arcade::Keys::RIGHT;
    if (key == 68)
        return Arcade::Keys::LEFT;
    if (key == 97)
        return Arcade::Keys::A;
    if (key == 98)
        return Arcade::Keys::B;
    if (key == 99)
        return Arcade::Keys::C;
    if (key == 100)
        return Arcade::Keys::D;
    if (key == 101)
        return Arcade::Keys::E;
    if (key == 102)
        return Arcade::Keys::F;
    if (key == 103)
        return Arcade::Keys::G;
    if (key == 104)
        return Arcade::Keys::H;
    if (key == 105)
        return Arcade::Keys::I;
    if (key == 106)
        return Arcade::Keys::J;
    if (key == 107)
        return Arcade::Keys::K;
    if (key == 108)
        return Arcade::Keys::L;
    if (key == 109)
        return Arcade::Keys::M;
    if (key == 110)
        return Arcade::Keys::N;
    if (key == 111)
        return Arcade::Keys::O;
    if (key == 112)
        return Arcade::Keys::P;
    if (key == 113)
        return Arcade::Keys::Q;
    if (key == 114)
        return Arcade::Keys::R;
    if (key == 115)
        return Arcade::Keys::S;
    if (key == 116)
        return Arcade::Keys::T;
    if (key == 117)
        return Arcade::Keys::U;
    if (key == 118)
        return Arcade::Keys::V;
    if (key == 119)
        return Arcade::Keys::W;
    if (key == 120)
        return Arcade::Keys::X;

    return -1;
}

std::pair<int, int> Arcade::Ncurses::getMousePosition()
{
    return std::make_pair(0, 0);
}

void Arcade::Ncurses::displayWindow()
{
    refresh();
}

void Arcade::Ncurses::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        auto color = entity->getColor();
        start_color();
        init_pair(255,255,255);
        attron(COLOR_PAIR(1));
        mvprintw(entity->getPos()[1] * 29 , entity->getPos()[0] *29, "%c", entity->getChar());
        attroff(COLOR_PAIR(1));
    }
}

void Arcade::Ncurses::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        mvprintw(text->getPos()[1] *29 , text->getPos()[0] * 29, "%s", text->getText().c_str());
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
