#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/theories.h>
#include <criterion/internal/assert.h>
#include <iostream>
#include <memory>
#include "../core/DLLoader.hpp"

Test(dlLoader, dlLoader_good_test_graphic)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("loadGraphicInstance");
    int *test = tmp->getInstance("./lib/arcade_ncurses.so");
    cr_assert_eq(test, 0);
}

Test(dlLoader, dlLoader_good_test_game)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("loadGraphicInstance");
    int *test = tmp->getInstance("./lib/arcade_snake.so");
    cr_assert_eq(test, 0);
}

Test(dlLoader, dlLoader_bad_lib)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("loadGraphicInstance");
    int *test = tmp->getInstance("./lib/ncuses.so");
    cr_assert_eq(test, nullptr);
}

Test(dlLoader, dlLoader_bad_entry)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("a");
    int *test = tmp->getInstance("./lib/arcade_ncurses.so");
    cr_assert_eq(test, nullptr);
}
