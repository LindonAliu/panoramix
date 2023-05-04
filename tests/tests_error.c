/*
** EPITECH PROJECT, 2022
** tests_error
** File description:
** tests error handling
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include "panoramix.h"

Test(all_errors, test_argc)
{
    const char *argv[] = {"./bin", "1", "2", "3", "4", NULL};
    const char *argv_incorrect[] = {"./bin", "0", "2", "3", "4", NULL};
    
    const char *av[] = {"./bin", NULL};
    const char *argv_help[] = {"./bin", "--help", NULL};
    const char *argv_help1[] = {"./bin", "-h", NULL};

    const char *argv_invalid_help[] = {"./bin", "-ho", NULL};

    const char *incorrect_av0[] = {"./bin", "un", "deux", "trois", "quatre", NULL};
    const char *incorrect_av1[] = {"./bin", "1", NULL};

    cr_assert_eq(error_handling(5, argv), 0);

    cr_assert_eq(error_handling(1, av), 1);
    cr_assert_eq(error_handling(2, argv_help), 1);
    cr_assert_eq(error_handling(2, argv_help1), 1);

    cr_assert_eq(error_handling(5, argv_incorrect), -1);
    cr_assert_eq(error_handling(2, argv_invalid_help), -1);
    
    cr_assert_eq(error_handling(5, incorrect_av0), -1);
    cr_assert_eq(error_handling(2, incorrect_av1), -1);
}

// Test(panoramix, test_pano)
// {
//     char *av[] = {"./panoramix", "3", "5", "3", "50", NULL};
//     cr_assert_eq(panoramix(av), 0);
// }
