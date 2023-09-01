/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** main.c
*/

#include "my.h"

void set_window_sprite(window_t *win)
{
    win->video_mode = (sfVideoMode) {1920, 1080, 32};
    win->window = sfRenderWindow_create(win->video_mode, "Radar",
                                        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->my_texture = sfTexture_createFromFile("img/map.png", NULL);
    win->my_sprite = sfSprite_create();
    win->my_pos.x = 0.0f;
    win->my_pos.y = 0.0f;
    win->scale.x = 1.0f;
    win->scale.y = 1.0f;
    sfSprite_setScale(win->my_sprite, win->scale);
    sfSprite_setPosition(win->my_sprite, win->my_pos);
    sfSprite_setTexture(win->my_sprite, win->my_texture, sfFalse);
}

void check_event(window_t *win)
{
    if (win->event.type == sfEvtClosed) {
        sfRenderWindow_close(win->window);
    } else if (win->event.type == sfEvtKeyPressed
    && win->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(win->window);
    }
    if (win->event.type == sfEvtKeyPressed) {
        if (win->event.key.code == sfKeyL)
            win->area_hitbox_enabled = !win->area_hitbox_enabled;
    }
    if (win->event.type == sfEvtKeyPressed) {
        if (win->event.key.code == sfKeyS)
            win->sprite_enabled = !win->sprite_enabled;
    }
}

void open_window(window_t *win, plane_t **plane, tower_t **tower)
{
    set_all_sprite(plane, tower, win);
    win->clock = sfClock_create();
    while (sfRenderWindow_isOpen(win->window)) {
        while (sfRenderWindow_pollEvent(win->window, &win->event)) {
            check_event(win);
        }
        display(plane, tower, win);
    }
}

int count_plane(window_t *win)
{
    int number = 0;
    for (int i = 0; win->info[i]; i++) {
        if (win->info[i][0] == 'A')
            number++;
    }
    return number;
}

int main(int ac, char **av)
{
    int res = error_handling(ac, av);
    int temp = 0;
    window_t *win = malloc(sizeof(window_t));
    if (ac == 2 && my_strcmp(av[1], "-h") != 0) {
        temp = open_read(av, win);
        compute_plane_tower(win);
    } else
        res = 2;
    tower_t **tower = malloc(sizeof(tower_t *) * (win->number_of_tower + 1));
    plane_t **plane = malloc(sizeof(plane_t *) * (win->number_of_plane + 1));
    if (res == 1 || temp == 1)
        return 84;
    else if (res == 2)
        return 0;
    else {
        open_window(win, plane, tower);
    }
    return res;
}
