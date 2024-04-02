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

template <typename T>
Arcade::DLLoader<T>::DLLoader() {
    handle = nullptr;
};

template <typename T>
Arcade::DLLoader<T>::DLLoader(const std::string &entryPoint) : entryPoint(entryPoint) {
    handle = nullptr;
}

template <typename T>
Arcade::DLLoader<T>::~DLLoader() {
    // if (handle != nullptr)
    //     dlclose(handle);
}

template <typename T>
T *Arcade::DLLoader<T>::getInstance(const std::string &libname) {
    if (handle != nullptr)
        dlclose(handle);
    handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << libname << std::endl;
        std::cerr << entryPoint << std::endl;
        std::cerr << "Error1: " << dlerror() << std::endl;
        exit(84);
    }
    T *(*object)(void) = (T*(*)())dlsym(handle, entryPoint.c_str());
    if (!object) {
        std::cerr << libname << std::endl;
        std::cerr << entryPoint << std::endl;
        std::cerr << "Error2: "  << dlerror() << std::endl;
        exit(84);
    }
    T *tmp = object();
    if (tmp == nullptr) {
        std::cerr << libname << std::endl;
        std::cerr << entryPoint << std::endl;
        std::cerr << "Error3: " << libname << " " << entryPoint << " returned nullptr" << std::endl;
        exit(84);
    }
    return tmp;
}

template <typename T>
void Arcade::DLLoader<T>::setEntryPoint(std::string const &entryPoint) {
    this->entryPoint = entryPoint;
}

template class Arcade::DLLoader<int>;
template class Arcade::DLLoader<Arcade::IGame>;
template class Arcade::DLLoader<Arcade::IGraphic>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGame>>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGraphic>>;
