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
            DLLoader() {
                handle = nullptr;
            };
            DLLoader(const std::string &entryPoint) : entryPoint(entryPoint) {
                handle = nullptr;
            }
            ~DLLoader() {
                // if (handle != nullptr)
                //     dlclose(handle);
            }
            T *getInstance(const std::string &libname) {
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
            void setEntryPoint(std::string const &entryPoint) {
                this->entryPoint = entryPoint;
            }
        private :
            void *handle;
            std::string entryPoint;
    };
}
