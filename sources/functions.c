/*
** EPITECH PROJECT, 2022
** functions
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "my_printf.h"

int function(const char *str)
{
    if (!str)
        return (-1);
    my_printf("%s\n", str);
    return (0);
}
