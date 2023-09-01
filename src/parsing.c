/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** open_read.c
*/

#include "my.h"

int checking_file(char **buffer)
{
    int res = 0;
    for (int x = 0; buffer[x]; x++) {
        if (buffer[x][0] != 'A' && buffer[x][0] != 'T') {
            res = 1;
            break;
        } else
            res = 0;

    }
    return res;
}

int count_line(char **av)
{
    int size_file = 0;
    ssize_t read;
    size_t len = 0;
    char *line = NULL;
    FILE *fd = fopen(av[1], "r");

    if (fd == 0) {
        my_printf("Unable to open the file : %s\n", av[1]);
        return 1;
    }
    while ((read = getline(&line, &len, fd)) != -1)
        size_file += read;

    fclose(fd);
    return size_file;
}

int open_read(char **av, window_t *win)
{
    char *temp;
    int size_file = count_line(av);
    int fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        my_printf("Unable to open the file : %s\n", av[1]);
        return 1;
    }
    temp = malloc(sizeof(char) * (size_file + 1));
    read(fd, temp, size_file);
    if (errno != 0) {
        my_printf("Unable to read the file : %s\n", av[1]);
        return 1;
    }
    temp[size_file] = '\0';
    win->info = my_str_to_word_array(temp, '\n');
    int var = checking_file(win->info);
    return var;
}
