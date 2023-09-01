/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** my.h
*/


#ifndef _MY_H_
    #define _MY_H_
    #define BUFF_SIZE 1024

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <math.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <string.h>
    #include <stdbool.h>

    typedef struct window_s {
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
        sfTexture *my_texture;
        sfSprite *my_sprite;
        sfVector2f my_pos;
        sfVector2f scale;
        sfTime time;
        sfClock *clock;
        sfFont *font;
        sfText *text;
        sfClock *timer_clock;
        sfTime timer_time;
        int second;
        float seconds;
        char **info;
        int number_of_plane;
        int number_of_tower;
        bool area_hitbox_enabled;
        bool sprite_enabled;
    } window_t;

    typedef struct plane_s {
        sfTexture *plane_texture;
        sfSprite *plane_sprite;
        sfVector2f pos_departure;
        sfVector2f pos_arrival;
        sfVector2f plane_scale;
        sfColor color;
        sfRectangleShape *rect;
        sfVector2f vector;
        sfVector2f ref_vector;
        int take_off_delay;
        int speed;
        int distance;
        float angle;
    } plane_t;

    typedef struct tower_s {
        sfTexture *tower_texture;
        sfSprite *tower_sprite;
        sfCircleShape *tower_circle;
        sfVector2f tower_pos;
        sfVector2f tower_scale;
        sfColor color;
        int radius_area;
    } tower_t;

/* LIB */
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int switch_check(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *str, char separator);
char *fill_array(char *str, char *array, int start, int end);
int count_separators(char *buf, char separator);
char *my_strdup(char const *src);
int get_back(char const *str, int i, int my_stop);
int my_getnbr(char const *str);
int strlen_custom(char const *str, char stopper);
void free_2darray(char **var);
char *my_itoa(int nb);

/* Error handling */
int error_handling(int ac, char **av);
void help(void);

/* Open window */
void check_event(window_t *win);
void open_window(window_t *win, plane_t **plane, tower_t **tower);
void set_window_sprite(window_t *win);
void destroy_sprite(plane_t **plane, window_t *win);
void free_info(plane_t **plane, tower_t **tower, window_t *win);

/* open_read info */
void compute_plane_tower(window_t *win);
int open_read(char **av, window_t *win);
int checking_file(char **buffer);
int count_line(char **av);

/* Create tower */
void set_tower(tower_t **tower, window_t *win);
void display_tower(tower_t **tower, window_t *win);
void set_tower_sprite(tower_t **tower, window_t *win);
void create_circle(tower_t **tower, window_t *win);
int count_tower(window_t *win);

/* Create plane */
void set_plane_sprite(plane_t **plane, window_t *win);
void set_plane(plane_t **plane, window_t *win);
void display_plane(plane_t **plane, window_t *win);
void create_square(plane_t **plane, window_t *win);
int count_plane(window_t *win);

/* Create clock */
void create_clock(plane_t **plane, window_t *win);
void compute_rotation(plane_t *plane);

/* Display */
void display(plane_t **plane, tower_t **tower, window_t *win);
void set_all_sprite(plane_t **plane, tower_t **tower, window_t *win);

#endif
