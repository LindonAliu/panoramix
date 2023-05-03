/*
** EPITECH PROJECT, 2023
** druid
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include "panoramix.h"

void *druid(void *arg)
{
    struct druid *d = arg;

    printf("Druid: I'm ready... but sleepy...\n");

    while (d->nb_refills > 0) {
        pthread_mutex_lock(&d->village->potion_mutex);
        while (d->village->call_druid == false) {
            pthread_cond_wait(&d->village->druid_cond,
                &d->village->potion_mutex);
        }
        d->village->nb_potions += d->pot_size;
        d->nb_refills--;
        d->village->call_druid = false;
        printf("Druid: Ah! Yes, yes I'm awake! Working on it! Beware I can only make %ld more refills after this one.\n", d->nb_refills);
        pthread_mutex_unlock(&d->village->potion_mutex);
        pthread_cond_signal(&d->village->villager_cond);
    }
    printf("Druid: I'm out of viscus. I'm going back to... zZz\n");
    pthread_mutex_unlock(&d->village->potion_mutex);
    return NULL;
}
