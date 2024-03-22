/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** tests_SnakeGame
*/

#include <criterion/criterion.h>
#include "src/snake/SnakeGame.hpp"

Test(SnakeGame, StartGame)
{
    SnakeGame game;
    int result = game.startGame();

    cr_assert_eq(game.getScore(), 0);
    cr_assert_eq(result, 0);
}

Test(SnakeGame, StopGame)
{
    SnakeGame game;
    int result = game.stopGame();
    cr_assert_eq(result, 0);
}

Test(SnakeGame, GetScore)
{
    SnakeGame game;
    int score = game.getScore();
    cr_assert_eq(score, 0);
}

Test(SnakeGame, Simulate)
{
    SnakeGame game;
    int result = game.simulate();

    auto entities = game.getEntities();
    cr_assert(entities.size() != 0);
    cr_assert_eq(result, 0);
}
