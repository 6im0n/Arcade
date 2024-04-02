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
            DLLoader(std::string const &entryPoint) : entryPoint(entryPoint) {
                handle = nullptr;
            }
            ~DLLoader() {
                // if (handle != nullptr)
                //     dlclose(handle);
            }
            std::unique_ptr<T> getInstance(std::string const &libname) {
                if (handle != nullptr)
                    dlclose(handle);
                handle = dlopen(libname.c_str(), RTLD_LAZY);
                if (dlerror() != NULL || !handle) {
                    std::cerr << "Error: " << libname << " " << entryPoint << dlerror() << std::endl;
                    return nullptr;
                }
                T *(*object)(void) = (T*(*)())dlsym(handle, entryPoint.c_str());
                if (dlerror() != NULL || !object) {
                    std::cerr << "Error: "  << libname << " " << entryPoint << dlerror() << std::endl;
                    return nullptr;
                }
                T *tmp = object();
                if (tmp == nullptr) {
                    std::cerr << "Error: " << libname << " " << entryPoint << " returned nullptr" << std::endl;
                }
                return std::unique_ptr<T>(tmp);
            }
            void setEntryPoint(std::string const &entryPoint) {
                this->entryPoint = entryPoint;
            }
        private :
            void *handle;
            std::string entryPoint;
    };
}
