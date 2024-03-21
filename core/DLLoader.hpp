/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlLoader.hpp
*/

#include <vector>
#include <string>

namespace Arcade {
    template <typename T>
    class DLLoader {
        public :
            DLLoader();
            DLLoader(std::string const &entryPoint);
            ~DLLoader();
            T *getInstance(std::string const &libname);
            void setEntryPoint(std::string const &entryPoint);
        private :
            void *handle;
            std::string entryPoint;
    };
}
