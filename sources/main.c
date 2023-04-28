/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include "panoramix.h"

int main(int argc, const char *argv[])
{
    int error = error_handling(argc, argv);
    int return_value = 0;

    if (error < 0) {
        return_value = 84;
        print_help(argv[0]);
    } else if (error == 0)
        return_value = panoramix(argv);
    return return_value;
}
