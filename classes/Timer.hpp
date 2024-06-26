/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Timer
*/

#pragma once

#include <chrono>

namespace Arcade {
    class Timer {
        public:
            Timer();
            ~Timer() = default;

            void start();
            void reset();
            float getElapsedTime();

        protected:
        private:
            std::chrono::time_point<std::chrono::system_clock> _start;
    };
}
