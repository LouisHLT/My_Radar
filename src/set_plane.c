/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** set_plane.c
*/

#include "my.h"

void compute_vector(plane_t **plane, int i )
{
    plane[i]->vector.x = plane[i]->pos_arrival.x - plane[i]->pos_departure.x;
    plane[i]->vector.y = plane[i]->pos_arrival.y - plane[i]->pos_departure.y;
    plane[i]->distance = sqrt(pow(plane[i]->vector.x, 2)
    + pow(plane[i]->vector.y, 2));
}

void create_square(plane_t **plane, window_t *win)
{
    for (int i = 0; i != win->number_of_plane; i++) {
        plane[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(plane[i]->rect, plane[i]->pos_departure);
        sfRectangleShape_setSize(plane[i]->rect, (sfVector2f) {20, 20});
        sfRectangleShape_setScale(plane[i]->rect, (sfVector2f) {1, 1});
        sfRectangleShape_setFillColor(plane[i]->rect, sfTransparent);
        sfRectangleShape_setOutlineColor(plane[i]->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(plane[i]->rect, 2);
        sfRectangleShape_setOrigin(plane[i]->rect, (sfVector2f) {10, 10});
        sfRectangleShape_setRotation(plane[i]->rect, plane[i]->angle);
        sfRenderWindow_drawRectangleShape(win->window, plane[i]->rect, NULL);
    }
}

void display_plane(plane_t **plane, window_t *win)
{

    for (int i = 0; i != win->number_of_plane; i++) {
        compute_vector(plane, i);
        compute_rotation(plane[i]);
        sfSprite_setOrigin(plane[i]->plane_sprite, (sfVector2f) {142.5, 134});
        sfSprite_setPosition(plane[i]->plane_sprite, plane[i]->pos_departure);
        sfSprite_setRotation(plane[i]->plane_sprite, plane[i]->angle);
        sfRenderWindow_drawSprite(win->window, plane[i]->plane_sprite, NULL);
    }
}

void set_plane(plane_t **plane, window_t *win)
{
    char **temp = NULL;
    int j = 0;
    for (int i = 0; i < win->number_of_plane + win->number_of_tower; i++) {
        if (win->info[i][0] == 'A') {
            temp = my_str_to_word_array(win->info[i], ' ');
            plane[j]->pos_departure.x = my_getnbr(temp[1]);
            plane[j]->pos_departure.y = my_getnbr(temp[2]);
            plane[j]->pos_arrival.x = my_getnbr(temp[3]);
            plane[j]->pos_arrival.y = my_getnbr(temp[4]);
            plane[j]->speed = my_getnbr(temp[5]);
            plane[j]->take_off_delay = my_getnbr(temp[6]);
            j++;
            free_2darray(temp);
        }
    }
}
