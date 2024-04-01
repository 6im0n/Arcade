/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_void
*/

#include <criterion/criterion.h>
#include "src/snake/Entities/Void.hpp"
#include "src/snake/Snake.hpp"
#include "classes/Color.hpp"
#include "src/snake/SnakeGame.hpp"

Test(Void, DefaultConstructor)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);
}

Test(Void, SetSizeAndGetSize)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setSize(10, 10);
    cr_assert_eq(elem.getSize()[0], 10);
    cr_assert_eq(elem.getSize()[1], 10);
}

Test(Void, SetPosAndGetPos)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setPos(10, 10);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
}

Test(Void, SetCharAndGetChar)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setChar('A');
    cr_assert_eq(elem.getChar(), 'A');
}

Test(Void, SetColorAndGetColor)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setColor(std::make_unique<Arcade::Color>(10, 10, 10, 10));
    cr_assert_eq(elem.getColor()->getR(), 10);
    cr_assert_eq(elem.getColor()->getG(), 10);
    cr_assert_eq(elem.getColor()->getB(), 10);
    cr_assert_eq(elem.getColor()->getA(), 10);
}

Test(Void, SetPathAndGetPath)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setPath("assets/pear");
    cr_assert_str_eq(elem.getPath().c_str(), "assets/pear");
}

Test(Void, SetRotationAndGetRotation)
{
    Arcade::Snake snake = Arcade::Snake();
    Arcade::Void elem = Arcade::Void(10, 10);

    cr_assert_eq(elem.getPos().size(), 2);
    cr_assert_eq(elem.getPos()[0], 10);
    cr_assert_eq(elem.getPos()[1], 10);
    cr_assert_eq(elem.getSize().size(), 2);
    cr_assert_eq(elem.getSize()[0], 29);
    cr_assert_eq(elem.getSize()[1], 29);
    cr_assert_eq(elem.getPath(), VOID_PATH);
    cr_assert_eq(elem.getRotation(), 0);
    cr_assert_eq(elem.getChar(), ' ');
    cr_assert_eq(elem.getColor()->getR(), 66);
    cr_assert_eq(elem.getColor()->getG(), 242);
    cr_assert_eq(elem.getColor()->getB(), 17);
    cr_assert_eq(elem.getColor()->getA(), 255);

    elem.setRotation(10);
    cr_assert_eq(elem.getRotation(), 10);
}
