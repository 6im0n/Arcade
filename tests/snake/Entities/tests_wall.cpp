/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_wall
*/

#include <criterion/criterion.h>
#include "src/snake/Entities/Wall.hpp"
#include "src/snake/Snake.hpp"
#include "classes/Color.hpp"

Test(Wall, DefaultConstructor)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);
}

Test(Wall, SetSizeAndGetSize)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setSize(10, 10);
    cr_assert_eq(elem.getSize()[0], 10);
    cr_assert_eq(elem.getSize()[1], 10);
}

Test(Wall, SetPosAndGetPos)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setPos(10, 10);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
}

Test(Wall, SetCharAndGetChar)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setChar('A');
    cr_assert_eq(elem.getChar(), 'A');
}

Test(Wall, SetColorAndGetColor)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setColor(std::make_unique<Color>(10, 10, 10, 10));
    cr_assert_eq(elem.getColor()->getR(), 10);
    cr_assert_eq(elem.getColor()->getG(), 10);
    cr_assert_eq(elem.getColor()->getB(), 10);
    cr_assert_eq(elem.getColor()->getA(), 10);
}

Test(Wall, SetPathAndGetPath)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setPath("assets/pear");
    cr_assert_str_eq(elem.getPath().c_str(), "assets/pear");
}

Test(Wall, SetRotationAndGetRotation)
{
    Snake snake = Snake();
    Wall elem = Wall(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 17);
    cr_assert_eq(elem.getSize()[1], 17);
    cr_assert_eq(elem.getPath(), "assets/wall");
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), 'x');
    cr_assert_eq(elem.getColor()->getR(), 39);
    cr_assert_eq(elem.getColor()->getG(), 122);
    cr_assert_eq(elem.getColor()->getB(), 16);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setRotation(10);
    cr_assert_eq(elem.getRotation(), 10);
}
