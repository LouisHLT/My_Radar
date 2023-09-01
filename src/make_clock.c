/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** make_clock.c
*/

#include "my.h"

void create_clock(plane_t **plane, window_t *win)
{
    win->time = sfClock_getElapsedTime(win->clock);
    win->seconds = win->time.microseconds / 1000000.0;
    for (int i = 0; i != win->number_of_plane; i++) {
        if (win->seconds > 0.1) {
            plane[i]->pos_departure.x += plane[i]->vector.x
            / (plane[i]->distance / plane[i]->speed);
            plane[i]->pos_departure.y += plane[i]->vector.y
            / (plane[i]->distance / plane[i]->speed);
            sfClock_restart(win->clock);
        }
    }
}
