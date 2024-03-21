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

template <typename T>
Arcade::DLLoader<T>::DLLoader(std::string const &entryPoint) : entryPoint(entryPoint) {
    handle = nullptr;
}

template <typename T>
Arcade::DLLoader<T>::~DLLoader() {
    dlclose(handle);
}

template <typename T>
T *Arcade::DLLoader<T>::getInstance(std::string const &libname) {
    if (handle != nullptr)
        dlclose(handle);
    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return nullptr;
    }
    T *(*object)(void) = (T*(*)())dlsym(handle, entryPoint.c_str());
    T *tmp = object();
    return tmp;
}

template <typename T>
void Arcade::DLLoader<T>::setEntryPoint(std::string const &entryPoint) {
    this->entryPoint = entryPoint;
}

template class Arcade::DLLoader<int>;
template class Arcade::DLLoader<Arcade::IGame>;
template class Arcade::DLLoader<Arcade::IGraphic>;
