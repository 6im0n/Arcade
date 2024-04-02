/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_Color
*/

#include <criterion/criterion.h>
#include "classes/Color.hpp"

Test(Color, DefaultConstructor)
{
    Arcade::Color color = Arcade::Color(0, 0, 0, 255);

    cr_assert_eq(color.getR(), 0);
    cr_assert_eq(color.getG(), 0);
    cr_assert_eq(color.getB(), 0);
    cr_assert_eq(color.getA(), 255);
}

Test(Color, CustomConstructor)
{
    Arcade::Color color(255, 0, 0, 128);

    cr_assert_eq(color.getR(), 255);
    cr_assert_eq(color.getG(), 0);
    cr_assert_eq(color.getB(), 0);
    cr_assert_eq(color.getA(), 128);
}

Test(Color, SettersAndGetters)
{
    Arcade::Color color = Arcade::Color(0, 0, 0, 0);

    color.setColor(128, 64, 32, 192);

    cr_assert_eq(color.getR(), 128);
    cr_assert_eq(color.getG(), 64);
    cr_assert_eq(color.getB(), 32);
    cr_assert_eq(color.getA(), 192);
}
