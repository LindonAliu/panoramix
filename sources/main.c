/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "all_lib.h"

int main(UNUSED int argc, UNUSED const char *argv[], UNUSED const char *env[])
{

    int a = 0;
    char *phrase = "10";

    a = my_getnbr(phrase);
    printf("%d\n", a);
}
