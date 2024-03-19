#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/theories.h>
#include <criterion/internal/assert.h>
#include <iostream>
#include <memory>

Test(test, test)
{
    cr_assert(1 == 1);
}
