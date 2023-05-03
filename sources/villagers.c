/*
** EPITECH PROJECT, 2023
** villagers
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include "panoramix.h"

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
        printf("Villager %ld: Hey Pano wake up! We need more potion.\n", v->id);
        v->village->call_druid = true;
        pthread_cond_signal(&v->village->druid_cond);
        while (v->village->call_druid) {
            pthread_cond_wait(&v->village->villager_cond,
                &v->village->potion_mutex);
        }
        v->village->nb_potions--;
        v->drunk = true;
    } else {
        v->village->nb_potions--;
        v->drunk = true;
    }

    pthread_mutex_unlock(&v->village->potion_mutex);
}

void *villager(void *arg)
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
