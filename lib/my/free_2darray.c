/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** free_2darray.c
*/

#include "my.h"

void free_2darray(char **var)
{
    for (int i = 0; var[i]; i++) {
        free(var[i]);
    }
    free(var);
}
