/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_timer
*/

#include <criterion/criterion.h>
#include <unistd.h>

#include "classes/Timer.hpp"

Test(Timer, DefaultConstructor)
{
    Timer timer;

    cr_assert(timer.getElapsedTime() <= 0.1);
}

Test(Timer, StartStop)
{
    Timer timer;
    timer.start();
    usleep(1000000); // Wait for 1 second
    cr_assert(timer.getElapsedTime() >= 1 && timer.getElapsedTime() <= 2);
}

Test(Timer, Reset)
{
    Timer timer;
    timer.start();
    usleep(1000000); // Wait for 1 second
    timer.reset();
    cr_assert(timer.getElapsedTime() <= 0.1);
}
