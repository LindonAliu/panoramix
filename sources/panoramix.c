/*
** EPITECH PROJECT, 2022
** functions
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "my_printf.h"
#include "panoramix.h"

static void create_villagers(int nb_villagers, int nb_fights,
    struct villager villagers[], struct village *v)
{
    for (int i = 0; i < nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].nb_fights = nb_fights;
        villagers[i].village = v;
        villagers[i].drunk = false;
    }
}

static void create_threads(int nb_villagers, struct villager villagers[],
    pthread_t threads[], struct druid *d)
{
    for (int i = 0; i < nb_villagers; i++) {
        pthread_create(&threads[i], NULL, &villager, &villagers[i]);
    }
    pthread_create(&threads[nb_villagers], NULL, &druid, d);
    for (int i = 0; i < nb_villagers + 1; i++) {
        pthread_join(threads[i], NULL);
    }
}

int panoramix(const char *av[])
{
    struct village v = { atoi(av[2]), false, PTHREAD_MUTEX_INITIALIZER };
    struct villager villagers[atoi(av[1])];
    struct druid d = { atoi(av[2]), atoi(av[4]), &v };
    pthread_t threads[atoi(av[1]) + 1];

    create_villagers(atoi(av[1]), atoi(av[3]), villagers, &v);
    create_threads(atoi(av[1]), villagers, threads, &d);
    return (0);
}
