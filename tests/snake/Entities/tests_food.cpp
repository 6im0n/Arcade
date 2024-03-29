/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_food
*/

#include <criterion/criterion.h>
#include "src/snake/Entities/Food.hpp"
#include "src/snake/Snake.hpp"
#include "classes/Color.hpp"

Test(Food, DefaultConstructor)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);
}

Test(Food, SetSizeAndGetSize)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setSize(10, 10);
    cr_assert_eq(food.getSize()[0], 10);
    cr_assert_eq(food.getSize()[1], 10);
}

Test(Food, SetPosAndGetPos)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setPos(10, 10);
    cr_assert_eq(food.getPos()[0], 10);
    cr_assert_eq(food.getPos()[1], 10);
}

Test(Food, SetCharAndGetChar)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setChar('A');
    cr_assert_eq(food.getChar(), 'A');
}

Test(Food, SetColorAndGetColor)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setColor(std::make_unique<Arcade::Color>(10, 10, 10, 10));
    cr_assert_eq(food.getColor()->getR(), 10);
    cr_assert_eq(food.getColor()->getG(), 10);
    cr_assert_eq(food.getColor()->getB(), 10);
    cr_assert_eq(food.getColor()->getA(), 10);
}

Test(Food, SetPathAndGetPath)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setPath("assets/pear");
    cr_assert_str_eq(food.getPath().c_str(), "assets/pear");
}

Test(Food, SetRotationAndGetRotation)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Food food = Arcade::Food(snake);

    cr_assert_eq(food.getPos().size(), 2);
    cr_assert_eq(food.getSize().size(), 2);
    cr_assert_eq(food.getSize()[0], 17);
    cr_assert_eq(food.getSize()[1], 17);
    cr_assert_eq(food.getPath(), "assets/apple");
    cr_assert_eq(food.getRotation(), 0);
    cr_assert_eq(food.getChar(), 'O');
    cr_assert_eq(food.getColor()->getR(), 40);
    cr_assert_eq(food.getColor()->getG(), 79);
    cr_assert_eq(food.getColor()->getB(), 42);
    cr_assert_eq(food.getColor()->getA(), 255);

    food.setRotation(10);
    cr_assert_eq(food.getRotation(), 10);
}
