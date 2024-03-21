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
arcade::DLLoader<T>::DLLoader(std::string const &entryPoint) : entryPoint(entryPoint) {
    handle = nullptr;
}

template <typename T>
arcade::DLLoader<T>::~DLLoader() {
    dlclose(handle);
}

template <typename T>
T *arcade::DLLoader<T>::getInstance(std::string const &libname) {
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
void arcade::DLLoader<T>::setEntryPoint(std::string const &entryPoint) {
    this->entryPoint = entryPoint;
}

template class arcade::DLLoader<int>;
template class arcade::DLLoader<arcade::IGame>;
template class arcade::DLLoader<arcade::IGraphic>;
