/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** display.c
*/

#include "my.h"

void display(plane_t **plane, tower_t **tower, window_t *win)
{
    sfRenderWindow_drawSprite(win->window, win->my_sprite, NULL);
    if (win->area_hitbox_enabled) {
        create_circle(tower, win);
        create_square(plane, win);
        create_clock(plane, win);
    }
    if (win->sprite_enabled) {
        display_plane(plane, win);
        display_tower(tower, win);
        create_clock(plane, win);
    }
    destroy_sprite(plane, win);
    sfRenderWindow_display(win->window);
}
