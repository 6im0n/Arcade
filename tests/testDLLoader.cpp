#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/theories.h>
#include <criterion/internal/assert.h>
#include <iostream>
#include <memory>
#include "../core/DLLoader.hpp"

Test(dlLoader, dlLoader_good_test)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("init");
    int *test = tmp->getInstance("./lib/ncurses.so");
    cr_assert_eq(test, 0);
}

Test(dlLoader, dlLoader_bad_lib)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("init");
    int *test = tmp->getInstance("./lib/ncuses.so");
    cr_assert_eq(test, nullptr);
}

Test(dlLoader, dlLoader_bad_entry)
{
    Arcade::DLLoader<int> *tmp = new Arcade::DLLoader<int>("a");
    int *test = tmp->getInstance("./lib/ncurses.so");
    cr_assert_eq(test, nullptr);
}
