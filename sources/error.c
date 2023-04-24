/*
** EPITECH PROJECT, 2022
** error
** File description:
** FreeKOSOVO
*/

#include <stddef.h>

int handly_error(int argc, const char *argv[], const char *env[])
{
    if (env == NULL || env[0] == NULL || argc != 2 || argv == NULL)
        return (-1);
    return (0);
}
