/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Timer
*/

#include "Timer.hpp"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::start()
{
    _start = std::chrono::system_clock::now();
}

void Timer::reset()
{
    _start = std::chrono::system_clock::now();
}

float Timer::getElapsedTime()
{
    std::chrono::duration<float> elapsed_seconds = std::chrono::system_clock::now() - _start;
    return elapsed_seconds.count();
}
