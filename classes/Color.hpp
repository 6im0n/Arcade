/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Color
*/

#pragma once

#include "Interfaces/IEntity.hpp"

namespace Arcade {
    class Color : public IColor {
        public:
            Color(short r, short g, short b, short a);
            ~Color() = default;

        void setColor(short r, short g, short b, short a);

        short getR();
        short getG();
        short getB();
        short getA();

        private:
            short _r;
            short _g;
            short _b;
            short _a;
    };
}
