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
    arcade::DLLoader<int> *tmp = new arcade::DLLoader<int>("init");
    int *test = tmp->getInstance("./lib/ncurses.so");
    cr_assert_eq(test, 0);
}

Test(dlLoader, dlLoader_bad_lib)
{
    arcade::DLLoader<int> *tmp = new arcade::DLLoader<int>("init");
    int *test = tmp->getInstance("./lib/ncuses.so");
    cr_assert_eq(test, nullptr);
}

Test(dlLoader, dlLoader_bad_entry)
{
    arcade::DLLoader<int> *tmp = new arcade::DLLoader<int>("a");
    int *test = tmp->getInstance("./lib/ncurses.so");
    cr_assert_eq(test, nullptr);
}
