/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** set_tower.c
*/

#include "my.h"

int count_tower(window_t *win)
{
    int number = 0;
    for (int i = 0; win->info[i]; i++) {
        if (win->info[i][0] == 'T')
            number++;
    }
    return number;
}

void create_circle(tower_t **tower, window_t *win)
{
    for (int i = 0; i != win->number_of_tower; i++) {
        tower[i]->tower_circle = sfCircleShape_create();
        sfCircleShape_setPosition(tower[i]->tower_circle, tower[i]->tower_pos);
        sfCircleShape_setScale(tower[i]->tower_circle, tower[i]->tower_scale);
        sfCircleShape_setRadius(tower[i]->tower_circle, tower[i]->radius_area);
        sfCircleShape_setFillColor(tower[i]->tower_circle, sfTransparent);
        sfCircleShape_setOutlineColor(tower[i]->tower_circle, sfRed);
        sfCircleShape_setOutlineThickness(tower[i]->tower_circle, 20);
        sfCircleShape_setOrigin(tower[i]->tower_circle, (sfVector2f)
        {tower[i]->radius_area, tower[i]->radius_area});
        sfRenderWindow_drawCircleShape(win->window, tower[i]->tower_circle,
        NULL);

    }
}

void display_tower(tower_t **tower, window_t *win)
{
    for (int i = 0; i != win->number_of_tower; i++) {
        sfSprite_setOrigin(tower[i]->tower_sprite, (sfVector2f) {256, 256});
        sfSprite_setPosition(tower[i]->tower_sprite, tower[i]->tower_pos);
        sfRenderWindow_drawSprite(win->window, tower[i]->tower_sprite, NULL);
    }
}

void set_tower(tower_t **tower, window_t *win)
{
    int j = 0;
    char **temp = NULL;
    for (int i = 0; i < win->number_of_plane + win->number_of_tower; i++) {
        if (win->info[i][0] == 'T') {
            temp = my_str_to_word_array(win->info[i], ' ');
            tower[j]->tower_pos.x = my_getnbr(temp[1]);
            tower[j]->tower_pos.y = my_getnbr(temp[2]);
            tower[j]->radius_area = my_getnbr(temp[3]);
            j++;
            free_2darray(temp);
        }
    }
}
