/*
** EPITECH PROJECT, 2022
** tests_fuctions
** File description:
** FreeKOSOVO
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_project.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(function, test_output, .init = redirect_all_std)
{
    function("hello world");
    cr_assert_stdout_eq_str("hello world\n");
    cr_assert_eq(function(NULL), -1);
}
