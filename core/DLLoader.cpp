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
    _handle = nullptr;
};

template <typename T>
Arcade::DLLoader<T>::DLLoader(const std::string &entryPoint) {
    _handle = nullptr;
    _entryPoint = entryPoint;
}

template <typename T>
Arcade::DLLoader<T>::~DLLoader() {
    if (_handle != nullptr)
        dlclose(_handle);
}

template <typename T>
T *Arcade::DLLoader<T>::getInstance(const std::string &libname) {
    if (_handle != nullptr)
        dlclose(_handle);
    _handle = dlopen(libname.c_str(), RTLD_LAZY);
    if (!_handle) {
        std::cerr << "Error1: " << dlerror() << std::endl;
        return nullptr;
    }
    T *(*object)(void) = (T*(*)())dlsym(_handle, _entryPoint.c_str());
    if (!object) {
        std::cerr << "Error2: "  << dlerror() << std::endl;
        return nullptr;
    }
    T *tmp = object();
    if (tmp == nullptr) {
        std::cerr << libname << std::endl;
        std::cerr << _entryPoint << std::endl;
        std::cerr << "Error3: " << libname << " " << _entryPoint << " returned nullptr" << std::endl;
        return nullptr;
    }
    return tmp;
}

template <typename T>
void Arcade::DLLoader<T>::setEntryPoint(std::string const &entryPoint) {
    this->_entryPoint = entryPoint;
}

template <typename T>
void Arcade::DLLoader<T>::close() {
    if (_handle != nullptr)
        dlclose(_handle);
    _handle = nullptr;
}

template class Arcade::DLLoader<int>;
template class Arcade::DLLoader<Arcade::IGame>;
template class Arcade::DLLoader<Arcade::IGraphic>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGame>>;
template class Arcade::DLLoader<std::unique_ptr<Arcade::IGraphic>>;
