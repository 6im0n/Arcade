/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlLoader.hpp
*/

#include "DLLoader.hpp"
#include "../Interfaces/IGame.hpp"
#include "../Interfaces/IGraphic.hpp"
#include <iostream>
#include <dlfcn.h>
#include <memory>

template class Arcade::DLLoader<int>;
template class Arcade::DLLoader<Arcade::IGame>;
template class Arcade::DLLoader<Arcade::IGraphic>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGame>>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGraphic>>;
