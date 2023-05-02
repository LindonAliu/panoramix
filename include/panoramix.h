/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** FreeKOSOVO
*/

#ifndef MY_PROJECT_H_
    #define MY_PROJECT_H_

    #include "all_lib.h"
    #include <pthread.h>
    #include <stdbool.h>

void print_help(const char *bin_name);
int error_handling(int argc, const char *argv[]);
int panoramix(const char *av[]);

struct villager {
    size_t id;
    size_t nb_fights;
    bool drunk;
    struct village *village;
};

struct druid {
    size_t pot_size;
    size_t nb_refills;
    struct village *village;
};

struct village {
    size_t nb_potions;
    bool call_druid;
    pthread_mutex_t potion_mutex;
};

typedef void *handler_t(void *arg);
handler_t druid;
handler_t villager;

#endif/* !MY_PROJECT_H_ */
