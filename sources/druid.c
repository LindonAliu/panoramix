/*
** EPITECH PROJECT, 2023
** druid
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include "panoramix.h"

static void waiting_villager_call_druid(struct village *v)
{
    while (v->call_druid == false) {
        pthread_cond_wait(&v->druid_cond, &v->druid_mutex);
    }
}

static void refill_potions(struct druid *d)
{
    const char *msg = "Ah! Yes, yes, I'm awake! Working on it! Beware";

    d->village->nb_potions += d->pot_size;
    d->nb_refills--;
    d->village->call_druid = false;
    printf("Druid: %s I can only make %ld more refills after this one.\n",
        msg, d->nb_refills);
}

static void unlock_and_send_signal(struct village *v)
{
    pthread_mutex_unlock(&v->druid_mutex);
    pthread_cond_signal(&v->villager_cond);
}

void *druid(void *arg)
{
    struct druid *d = arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (d->nb_refills > 0) {
        pthread_mutex_lock(&d->village->druid_mutex);
        waiting_villager_call_druid(d->village);
        refill_potions(d);
        unlock_and_send_signal(d->village);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    d->village->no_more_refills = true;
    pthread_mutex_unlock(&d->village->druid_mutex);
    return NULL;
}
