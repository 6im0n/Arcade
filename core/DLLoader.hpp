/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlLoader.hpp
*/

#include <vector>
#include <string>

namespace arcade {
    template <typename T>
    class DLLoader {
        public :
            DLLoader(std::string const &entryPoint);
            ~DLLoader();
            T *getInstance(std::string const &libname);
        private :
            void *handle;
            const std::string entryPoint;
    };
}
