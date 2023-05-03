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
    const char *msg = "Ah! Yes, yes I'm awake! Working on it! Beware";

    printf("Druid: I'm ready... but sleepy...\n");
    while (d->nb_refills > 0) {
        pthread_mutex_lock(&d->village->druid_mutex);
        while (d->village->call_druid == false)
            pthread_cond_wait(&d->village->druid_cond,
                &d->village->druid_mutex);
        d->village->nb_potions += d->pot_size;
        d->nb_refills--;
        d->village->call_druid = false;
        printf("Druid: %s I can only make %ld more refills after this one.\n",
            msg, d->nb_refills);
        pthread_mutex_unlock(&d->village->druid_mutex);
        pthread_cond_signal(&d->village->villager_cond);
    }
    printf("Druid: I'm out of viscus. I'm going back to... zZz\n");
    pthread_mutex_unlock(&d->village->druid_mutex);
    return NULL;
}
