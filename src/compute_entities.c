/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** compute_entities.c
*/

#include "my.h"

void compute_plane_tower(window_t *win)
{
    int number_plane = 0;
    int number_tower = 0;
    number_plane = count_plane(win);
    number_tower = count_tower(win);
    win->number_of_plane = number_plane;
    win->number_of_tower = number_tower;
}
