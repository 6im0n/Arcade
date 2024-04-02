/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Timer
*/

#include "Timer.hpp"

Arcade::Timer::Timer()
{
    _start = std::chrono::system_clock::now();
}

void Arcade::Timer::start()
{
    _start = std::chrono::system_clock::now();
}

void Arcade::Timer::reset()
{
    _start = std::chrono::system_clock::now();
}

float Arcade::Timer::getElapsedTime()
{
    std::chrono::duration<float> elapsed_seconds = std::chrono::system_clock::now() - _start;
    return elapsed_seconds.count();
}
