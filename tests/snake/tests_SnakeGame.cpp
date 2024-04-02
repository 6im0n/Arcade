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
    Arcade::SnakeGame game;
    int result = game.startGame();

    cr_assert_eq(game.getScore(), 0);
    cr_assert_eq(result, 0);
}

Test(SnakeGame, StopGame)
{
    Arcade::SnakeGame game;
    int result = game.stopGame();
    cr_assert_eq(result, 0);
}

Test(SnakeGame, GetScore)
{
    Arcade::SnakeGame game;
    int score = game.getScore();
    cr_assert_eq(score, 0, "Expected 0, got %d", score);
}

Test(SnakeGame, Simulate)
{
    Arcade::SnakeGame game;
    int result = game.simulate();

    auto entities = game.getEntities();
    cr_assert(entities.size() != 0);
    cr_assert_eq(result, 0);
}
