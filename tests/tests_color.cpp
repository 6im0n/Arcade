/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_color
*/

#include <criterion/criterion.h>
#include "classes/Color.hpp"

Test(Color, DefaultConstructor)
{
    Color color = Color(0, 0, 0, 255);

    cr_assert_eq(color.getR(), 0);
    cr_assert_eq(color.getG(), 0);
    cr_assert_eq(color.getB(), 0);
    cr_assert_eq(color.getA(), 255);
}

Test(Color, CustomConstructor)
{
    Color color(255, 0, 0, 128);

    cr_assert_eq(color.getR(), 255);
    cr_assert_eq(color.getG(), 0);
    cr_assert_eq(color.getB(), 0);
    cr_assert_eq(color.getA(), 128);
}

Test(Color, SettersAndGetters)
{
    Color color = Color(0, 0, 0, 0);

    color.setColor(128, 64, 32, 192);

    cr_assert_eq(color.getR(), 128);
    cr_assert_eq(color.getG(), 64);
    cr_assert_eq(color.getB(), 32);
    cr_assert_eq(color.getA(), 192);
}
