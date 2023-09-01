/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** set_sprite.c
*/

#include "my.h"

void set_all_sprite(plane_t **plane, tower_t **tower, window_t *win)
{
    set_window_sprite(win);
    set_tower_sprite(tower, win);
    set_plane_sprite(plane, win);
    set_plane(plane, win);
    set_tower(tower, win);
}

void destroy_sprite(plane_t **plane, window_t *win)
{
    for (int i = 0; i != win->number_of_plane; i++) {
        float error_margin = 10.0f;
        if ((plane[i]->pos_departure.x - plane[i]->pos_arrival.x <= error_margin
        && plane[i]->pos_arrival.x -
        plane[i]->pos_departure.x <= error_margin) &&
            (plane[i]->pos_departure.y - plane[i]->pos_arrival.y <= error_margin
            && plane[i]->pos_arrival.y -
            plane[i]->pos_departure.y <= error_margin)) {
            }
    }
}

void compute_rotation(plane_t *plane)
{
    float angle = 0.0f;
    float dot_product = 0.0f;
    float norme = 0.0f;
    dot_product = plane->ref_vector.x * plane->vector.x ;
    norme = sqrt(pow(plane->vector.x, 2) + pow(plane->vector.y, 2));
    angle = acos(dot_product / (plane->ref_vector.x * norme)) * 180 / M_PI;
    if (plane->vector.y < 0)
        angle = -angle;
    plane->angle = angle;
}

void set_tower_sprite(tower_t **tower, window_t *win)
{
    for (int i = 0; i != win->number_of_tower; i++) {
        tower[i] = malloc(sizeof(tower_t));
        tower[i]->tower_texture = sfTexture_createFromFile("img/tower.png",
        NULL);
        tower[i]->tower_sprite = sfSprite_create();
        tower[i]->tower_pos.x = 0.0f;
        tower[i]->tower_pos.y = 0.0f;
        tower[i]->tower_scale.x = 0.1f;
        tower[i]->tower_scale.y = 0.1f;
        sfSprite_setScale(tower[i]->tower_sprite, tower[i]->tower_scale);
        sfSprite_setTexture(tower[i]->tower_sprite, tower[i]->tower_texture,
        sfFalse);
    }
}

void set_plane_sprite(plane_t **plane, window_t *win)
{
    for (int i = 0; i != win->number_of_plane; i++) {
        plane[i] = malloc(sizeof(plane_t));
        plane[i]->plane_texture =
        sfTexture_createFromFile("img/plane.png", NULL);
        plane[i]->plane_sprite = sfSprite_create();
        plane[i]->pos_departure.x = 0.0f;
        plane[i]->pos_departure.y = 0.0f;
        plane[i]->pos_arrival.x = 0.0f;
        plane[i]->pos_arrival.y = 0.0f;
        plane[i]->plane_scale.x = 0.1f;
        plane[i]->plane_scale.y = 0.1f;
        plane[i]->ref_vector.x = 50.0f;
        plane[i]->ref_vector.y = 0.0f;
        compute_rotation(plane[i]);
        sfSprite_setScale(plane[i]->plane_sprite, plane[i]->plane_scale);
        sfSprite_setTexture(plane[i]->plane_sprite, plane[i]->plane_texture,
        sfFalse);
    }
}
