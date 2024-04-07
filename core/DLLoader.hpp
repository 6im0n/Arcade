/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlLoader.hpp
*/

#pragma once
#include "../Interfaces/IGame.hpp"
#include "../Interfaces/IGraphic.hpp"
#include <iostream>
#include <dlfcn.h>
#include <memory>

namespace Arcade {
    template <typename T>
    class DLLoader {
        public :
            DLLoader();
            DLLoader(const std::string &entryPoint);
            ~DLLoader();
            T *getInstance(const std::string &libname);
            void setEntryPoint(std::string const &entryPoint);
        private :
            void *_handle;
            std::string _entryPoint;
    };
}
