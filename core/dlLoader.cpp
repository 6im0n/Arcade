/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlLoader.hpp
*/

#include "dlLoader.hpp"
#include <iostream>
#include <dlfcn.h>

template <typename T>
arcade::DLLoader<T>::DLLoader(std::string const &entryPoint) : entryPoint(entryPoint){
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

template class arcade::DLLoader<int>;
