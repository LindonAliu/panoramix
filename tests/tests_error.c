/*
** EPITECH PROJECT, 2022
** tests_error
** File description:
** tests error handling
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include "my_project.h"

Test(all_errors, test_argc)
{
    const char *env[] = {"env", NULL};
    const char *env_error[] = {NULL, NULL};
    const char *argc[] = {"./bin", "argument"};

    cr_assert_eq(handly_error(0, argc, env), -1);
    cr_assert_eq(handly_error(2, NULL, env), -1);
    cr_assert_eq(handly_error(2, argc, NULL), -1);
    cr_assert_eq(handly_error(2, argc, env_error), -1);
    cr_assert_eq(handly_error(2, argc, env), 0);
}
