/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_snake_body
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "src/snake/Entities/SnakeBody.hpp"
#include "classes/Color.hpp"
#include "src/snake/direction.hpp"

Test(Snake, snake_constructor)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getPos().size(), 2);
    cr_assert_eq(snake.getPos()[0], 10);
    cr_assert_eq(snake.getPos()[1], 10);
    cr_assert_eq(snake.getSize().size(), 2);
    cr_assert_eq(snake.getSize()[0], 29);
    cr_assert_eq(snake.getSize()[1], 29);
    cr_assert_eq(snake.getChar(), '=');
    cr_assert_eq(snake.getColor()->getR(), 39);
    cr_assert_eq(snake.getColor()->getG(), 122);
    cr_assert_eq(snake.getColor()->getB(), 16);
    cr_assert_eq(snake.getColor()->getA(), 255);
}

Test(Snake, setPos)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getPos().size(), 2);
    cr_assert_eq(snake.getPos()[0], 10);
    cr_assert_eq(snake.getPos()[1], 10);
    snake.setPos(20, 20);
    cr_assert_eq(snake.getPos().size(), 2);
    cr_assert_eq(snake.getPos()[0], 20);
    cr_assert_eq(snake.getPos()[1], 20);
}

Test(Snake, setSize)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getSize().size(), 2);
    cr_assert_eq(snake.getSize()[0], 29);
    cr_assert_eq(snake.getSize()[1], 29);
    snake.setSize(20, 20);
    cr_assert_eq(snake.getSize().size(), 2);
    cr_assert_eq(snake.getSize()[0], 20);
    cr_assert_eq(snake.getSize()[1], 20);
}

Test(Snake, setChar)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getChar(), '=');
    snake.setChar('O');
    cr_assert_eq(snake.getChar(), 'O');
}

Test(Snake, setColor)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getColor()->getR(), 39);
    cr_assert_eq(snake.getColor()->getG(), 122);
    cr_assert_eq(snake.getColor()->getB(), 16);
    cr_assert_eq(snake.getColor()->getA(), 255);
    snake.setColor(std::make_unique<Arcade::Color>(10, 20, 30, 40));
    cr_assert_eq(snake.getColor()->getR(), 10);
    cr_assert_eq(snake.getColor()->getG(), 20);
    cr_assert_eq(snake.getColor()->getB(), 30);
    cr_assert_eq(snake.getColor()->getA(), 40);
}

Test(Snake, setPath)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getPath(), "assets/body");
    snake.setPath("assets/apple");
    cr_assert_eq(snake.getPath(), "assets/apple");
}

Test(Snake, setRotation)
{
    Arcade::SnakeBody snake = Arcade::SnakeBody(10, 10, "assets/body", Arcade::Direction::D_RIGHT);

    cr_assert_eq(snake.getRotation(), 90);
    snake.setRotation(0);
    cr_assert_eq(snake.getRotation(), 0);
}
