/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"
#include <iostream>
#include <csignal>


int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./arcade path_to_graphic_library" << std::endl;
        return 84;
    }
    Arcade::Core core(argv[1]);
    core.run();
    return 0;
}