/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** FreeKOSOVO
*/

#pragma once

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
    bool no_refills;
    pthread_mutex_t potion_mutex;
    pthread_cond_t druid_cond;
    pthread_cond_t villager_cond;
};

typedef void *handler_t(void *arg);
handler_t druid;
handler_t villager;
