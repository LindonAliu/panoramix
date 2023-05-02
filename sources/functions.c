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

static void villager_fight(struct villager *v)
{
    if (v->drunk) {
        v->drunk = false;
        v->nb_fights--;
        printf("Villager %ld: Take that roman scum! Only %ld left.\n", v->id,
            v->nb_fights);
    }
}

static void villager_drink(struct villager *v)
{
    pthread_mutex_lock(&v->village->potion_mutex);

    printf("Villager %ld: I need a drink... I see %ld servings left.\n",
        v->id, v->village->nb_potions);

    if (v->village->nb_potions == 0) {
        printf("Villager %ld: Druid! I need a drink!\n", v->id);
        v->village->call_druid = true;
    } else {
        v->village->nb_potions--;
        v->drunk = true;
    }

    pthread_mutex_unlock(&v->village->potion_mutex);
}

static void *villager(void *arg)
{
    struct villager *v = arg;

    printf("Villager %ld: Going into battle!\n", v->id);
    while (v->nb_fights > 0) {
        villager_drink(v);
        villager_fight(v);
    }
    printf("Villager %ld: I'm going to sleep now.\n", v->id);
    return NULL;
}

static void *druid(void *arg)
{
    struct druid *d UNUSED= arg;

    printf("Druid: I'm ready... but sleepy...\n");
    return NULL;
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
