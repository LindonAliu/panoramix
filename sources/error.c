/*
** EPITECH PROJECT, 2022
** error
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "str.h"

static int help_is_called(int ac, char const *av[])
{
    if (ac == 1)
        return 1;
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "--help") == 0)
            return 1;
    }
    return 0;
}

void print_help(const char *bin_name)
{
    dprintf(2, "USAGE: %s <nb_villagers>", bin_name);
    dprintf(2, " <pot_size> <nb_fights> <nb_refills>\n");
}

int error_handling(int ac, const char *av[])
{
    if (help_is_called(ac, av)) {
        print_help(av[0]);
        return 1;
    }
    if (ac != 5)
        return -1;
    for (int i = 1; av[i] != NULL; i++) {
        if (!my_str_isnum(av[i]))
            return -1;
        if (atoi(av[i]) <= 0)
            return -1;
    }
    return 0;
}
